pdfjsLib.GlobalWorkerOptions.workerSrc = 'https://cdnjs.cloudflare.com/ajax/libs/pdf.js/2.16.105/pdf.worker.min.js';

const uploadInput = document.getElementById('upload-pdf');
const pagesContainer = document.getElementById('pages-container');
const btnBaixar = document.getElementById('btn-baixar');
const inputFilename = document.getElementById('filename');
const brushSizeInput = document.getElementById('brush-size');
const brushSizeDisplay = document.getElementById('brush-size-display');
const brushColorInput = document.getElementById('brush-color');
const btnUndo = document.getElementById('btn-undo');
const btnRedo = document.getElementById('btn-redo');

let pdfDoc = null;
let canvases = []; 
let isDrawing = false;
let currentCtx = null;

const MAX_HISTORY = 30;
let historyStack = []; 
let redoStack = [];

let brushSize = parseInt(brushSizeInput.value);
let brushColor = brushColorInput.value;

brushColorInput.addEventListener('input', (e) => {
    brushColor = e.target.value;
});

brushSizeInput.addEventListener('input', (e) => {
    brushSize = e.target.value;
    brushSizeDisplay.innerText = brushSize + 'px';
});

brushSizeInput.addEventListener('input', (e) => {
    brushSize = e.target.value;
    brushSizeDisplay.innerText = brushSize + 'px';
});

uploadInput.addEventListener('change', (e) => {
    const file = e.target.files[0];
    if (!file || file.type !== 'application/pdf') return;

    inputFilename.value = file.name.replace('.pdf', '_censurada.pdf');

    const fileReader = new FileReader();
    fileReader.onload = function() {
        const typedarray = new Uint8Array(this.result);
        pagesContainer.innerHTML = '<p class="placeholder-text">Carregando documento...</p>';
        
        pdfjsLib.getDocument(typedarray).promise.then(pdf => {
            pdfDoc = pdf;
            pagesContainer.innerHTML = ''; 
            canvases = [];
            historyStack = [];
            redoStack = [];
            atualizarBotoesHistorico();

            renderizarPaginaSequencial(1);
        });
    };
    fileReader.readAsArrayBuffer(file);
});

function renderizarPaginaSequencial(pageNum) {
    if (pageNum > pdfDoc.numPages) {
        btnBaixar.disabled = false;
        return;
    }

    pdfDoc.getPage(pageNum).then(page => {
        const viewport = page.getViewport({ scale: 1.5 });
        
        const wrapper = document.createElement('div');
        wrapper.className = 'canvas-wrapper';
        
        const canvas = document.createElement('canvas');
        canvas.height = viewport.height;
        canvas.width = viewport.width;
        canvas.dataset.index = pageNum - 1;
        
        wrapper.appendChild(canvas);
        pagesContainer.appendChild(wrapper);
        canvases.push(canvas);

        const ctx = canvas.getContext('2d', { willReadFrequently: true });
        const renderContext = { canvasContext: ctx, viewport: viewport };
        
        page.render(renderContext).promise.then(() => {
            configurarEventosDesenho(canvas, ctx);
            renderizarPaginaSequencial(pageNum + 1); 
        });
    });
}

function salvarEstado(canvasIndex, clearRedo = true) {
    if (clearRedo) redoStack = []; 
    
    const canvas = canvases[canvasIndex];
    const ctx = canvas.getContext('2d');
    const imgData = ctx.getImageData(0, 0, canvas.width, canvas.height);
    
    historyStack.push({ canvasIndex, imgData });
    if (historyStack.length > MAX_HISTORY) historyStack.shift();
    
    atualizarBotoesHistorico();
}

function desfazer() {
    if (historyStack.length === 0) return;
    
    const currentStateInfo = historyStack.pop();
    const canvasIndex = currentStateInfo.canvasIndex;
    const canvas = canvases[canvasIndex];
    const ctx = canvas.getContext('2d');

    redoStack.push({ 
        canvasIndex, 
        imgData: ctx.getImageData(0, 0, canvas.width, canvas.height) 
    });

    ctx.putImageData(currentStateInfo.imgData, 0, 0);
    atualizarBotoesHistorico();
}

function refazer() {
    if (redoStack.length === 0) return;

    const nextStateInfo = redoStack.pop();
    const canvasIndex = nextStateInfo.canvasIndex;
    const canvas = canvases[canvasIndex];
    const ctx = canvas.getContext('2d');

    historyStack.push({ 
        canvasIndex, 
        imgData: ctx.getImageData(0, 0, canvas.width, canvas.height) 
    });

    ctx.putImageData(nextStateInfo.imgData, 0, 0);
    atualizarBotoesHistorico();
}

function atualizarBotoesHistorico() {
    btnUndo.disabled = historyStack.length === 0;
    btnRedo.disabled = redoStack.length === 0;
}

btnUndo.addEventListener('click', desfazer);
btnRedo.addEventListener('click', refazer);

document.addEventListener('keydown', (e) => {
    if (e.ctrlKey && (e.key === 'z' || e.key === 'Z')) {
        e.preventDefault();
        desfazer();
    }
    if (e.ctrlKey && (e.key === 'y' || e.key === 'Y')) {
        e.preventDefault();
        refazer();
    }
});

function configurarEventosDesenho(canvas, ctx) {
    canvas.addEventListener('mousedown', (e) => iniciarDesenho(e, canvas, ctx));
    canvas.addEventListener('mousemove', (e) => desenhar(e, canvas, ctx));
    canvas.addEventListener('mouseup', pararDesenho);
    canvas.addEventListener('mouseout', pararDesenho);
}

function iniciarDesenho(e, canvas, ctx) {
    isDrawing = true;
    currentCtx = ctx;
    
    salvarEstado(parseInt(canvas.dataset.index));

    ctx.beginPath();
    ctx.lineWidth = brushSize;
    ctx.lineCap = 'round';
    ctx.lineJoin = 'round';
    ctx.strokeStyle = brushColor;
    desenhar(e, canvas, ctx);
}

function desenhar(e, canvas, ctx) {
    if (!isDrawing || currentCtx !== ctx) return;
    
    const rect = canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    ctx.lineTo(x, y);
    ctx.stroke();
}

function pararDesenho() {
    if (isDrawing) {
        currentCtx.closePath();
        isDrawing = false;
        currentCtx = null;
    }
}

btnBaixar.addEventListener('click', () => {
    if (canvases.length === 0) return;

    btnBaixar.innerText = "Processando...";
    btnBaixar.disabled = true;

    setTimeout(() => {
        const { jsPDF } = window.jspdf;
        
        const orientacaoInicial = canvases[0].width > canvases[0].height ? 'l' : 'p';
        const pdf = new jsPDF({
            orientation: orientacaoInicial,
            unit: 'px',
            format: [canvases[0].width, canvases[0].height]
        });

        for (let i = 0; i < canvases.length; i++) {
            const canvas = canvases[i];
            const imgData = canvas.toDataURL('image/jpeg', 0.95);
            
            if (i > 0) {
                const orientacao = canvas.width > canvas.height ? 'l' : 'p';
                pdf.addPage([canvas.width, canvas.height], orientacao);
            }
            
            pdf.addImage(imgData, 'JPEG', 0, 0, canvas.width, canvas.height);
        }

        let finalName = inputFilename.value.trim();
        if (!finalName) finalName = 'prova_censurada';
        if (!finalName.endsWith('.pdf')) finalName += '.pdf';

        pdf.save(finalName);

        btnBaixar.innerText = "Salvar PDF";
        btnBaixar.disabled = false;
    }, 100);
});