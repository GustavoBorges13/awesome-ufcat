import os
import sys

# Lista OFICIAL das disciplinas base (para aparecerem mesmo sem ter provas ainda)
DISCIPLINAS_UFCAT = [
    "Algebra Linear", "Algoritmos e Programacao de Computadores I", "Algoritmos e Programacao de Computadores II",
    "Analise e Projeto de Algoritmos", "Arquitetura de Computadores", "Banco de Dados I", "Banco de Dados II",
    "Calculo I", "Calculo II", "Compiladores", "Computacao Grafica", "Direito a Informatica", "Empreendedorismo",
    "Engenharia de Software I", "Engenharia de Software II", "Estrutura de Dados I", "Estrutura de Dados II",
    "Fabrica de Software", "Fisica III", "Inteligencia Artificial", "Interacao Humano Computador", "Introducao a Computacao",
    "Laboratorio de Programacao I", "Laboratorio de Programacao II", "Laboratorio de Programacao III",
    "Linguagens de Programacao", "Linguagens Formais e Automatos", "Logica Matematica", "Matematica Discreta",
    "Organizacao de Computadores", "Pesquisa Operacional", "Probabilidade e Estatistica", "Processamento de Imagens",
    "Producao de Texto", "Programacao Funcional e Logica", "Programacao Orientada a Objetos", "Redes de Computadores I",
    "Redes de Computadores II", "Sistemas Digitais", "Sistemas Distribuidos", "Sistemas Operacionais I",
    "Sistemas Operacionais II", "Teoria da Computacao", "Teoria dos Grafos"
]

BLACKLIST = ['.git', '.github', 'scripts', 'venv', 'README.md', 'CONTRIBUTING.md', 'LICENSE', 'update_readme.py', 'docs', 'ufcat_logo.png']

def gerar_arvore(caminho_base='.'):
    arvore_md = ""
    
    # 1. Pega todas as pastas REAIS que existem no repositório (ignorando a blacklist)
    pastas_reais = [d for d in os.listdir(caminho_base) if os.path.isdir(os.path.join(caminho_base, d)) and d not in BLACKLIST]
    
    # 2. Junta a lista fixa com as pastas reais e usa set() para remover duplicatas
    todas_disciplinas = list(set(DISCIPLINAS_UFCAT + pastas_reais))
    
    # 3. Coloca tudo em ordem alfabética
    todas_disciplinas = sorted(todas_disciplinas)
    
    for disciplina in todas_disciplinas:
        link_disciplina = disciplina.replace(" ", "%20")
        arvore_md += f"- [{disciplina}]({link_disciplina})\n"
        
        caminho_disciplina = os.path.join(caminho_base, disciplina)
        
        # Se a pasta existir de verdade, entra nela pra listar as provas
        if os.path.exists(caminho_disciplina) and os.path.isdir(caminho_disciplina):
            subpastas = sorted([sub for sub in os.listdir(caminho_disciplina) if os.path.isdir(os.path.join(caminho_disciplina, sub))])
            
            for subpasta in subpastas:
                link_subpasta = f"{disciplina.replace(' ', '%20')}/{subpasta.replace(' ', '%20')}"
                arvore_md += f"    - [{subpasta}]({link_subpasta})\n"
                
    return arvore_md.strip()

def atualizar_readme(texto_arvore):
    with open('README.md', 'r', encoding='utf-8') as f:
        conteudo = f.read()

    marcador_inicio = "<!-- INICIO_LISTA -->"
    marcador_fim = "<!-- FIM_LISTA -->"

    inicio = conteudo.find(marcador_inicio)
    fim = conteudo.find(marcador_fim)

    if inicio != -1 and fim != -1:
        novo_conteudo = (
            conteudo[:inicio + len(marcador_inicio)] + 
            "\n" + texto_arvore + 
            "\n" + conteudo[fim:]
        )
        with open('README.md', 'w', encoding='utf-8') as f:
            f.write(novo_conteudo)
    else:
        print("❌ ERRO: Marcadores <!-- INICIO_LISTA --> e <!-- FIM_LISTA --> não encontrados no README.md!")
        sys.exit(1)

if __name__ == '__main__':
    arvore = gerar_arvore()
    atualizar_readme(arvore)
