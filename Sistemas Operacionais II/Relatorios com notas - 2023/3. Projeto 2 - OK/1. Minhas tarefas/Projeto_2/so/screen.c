#include "basic/include/screen.h"

int32 cursorX = 0, cursorY = 0; // Posição do cursor na tela
const uint8 sw = 80, sh = 25, sd = 2; // Dimensões da tela (largura, altura, profundidade)

uint16 strlength(string ch) {
	uint16 i = 1;
	while(ch[i++]);
	return --i;
}

uint8 inportb (uint16 _port) {
	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0"
  				  : "=a" (rv) 		/* operando de saída */
  				  : "dN" (_port));	/* operando de entrada */
	return rv;
}

void outportb (uint16 _port, uint8 _data) {
	__asm__ __volatile__ ("outb %1, %0"
  				: 				 /* operando de saída */
    				: "dN" (_port), "a" (_data));/* operando de entrada */
}


// Limpa a tela de uma linha específica até outra
void clearLine(uint8 from, uint8 to) {
	uint16 i = sw * from * sd;
	string vidmem = (string)0xb8000;
	for (i; i < (sw * (to + 1) * sd); i++) {
		vidmem[i] = 0x0;    // Valor (caractere) 0
		vidmem[i+1] = 0x0F;   // Cor branca sobre fundo preto
	}
}

// Atualiza a posição do cursor na tela
void updateCursor() {
	unsigned temp;
	temp = cursorY * sw + cursorX;
	outportb(0x3D4, 14);
	outportb(0x3D5, temp >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
}

// Limpa toda a tela
void clearScreen() {
	clearLine(0, sh-1);      // Chama clearLine p/ limpar da linha 0 até n (sh-1)
	cursorX = 0;        // Reseta a posição do cursor na largura
	cursorY = 0;        // Reseta a posição do cursor na altura
	updateCursor(); // Atualiza a posição do cursor
}

// Desloca conteúdo da tela para cima, remove 'lineNumber' linhas na parte superior
void scrollUp(uint8 lineNumber) {
	string vidmem = (string)0xb8000;
	uint16 i = 0;
	
	for (i; i < sw * (sh - 1) * sd; i++) {
		vidmem[i] = vidmem[i + sw * sd * lineNumber];  // Move o conteúdo da tela p/ cima
        }

	clearLine(sh - 1 - lineNumber, sh - 1);  // Limpa linhas recém-criadas na parte inferior
	if ((cursorY - lineNumber) < 0) {
		cursorY = 0;
		cursorX = 0;
	} else {
		cursorY -= lineNumber;  // Atualiza a posição do cursor na altura
	}
	updateCursor();  // Atualiza a posição do cursor
}
// Verifica se o cursor atingiu a última linha da tela, e se sim, rola a tela para cima
void newLineCheck() {
	if (cursorY >= sh-1) {
		scrollUp(1);  // Chama scrollUp p/ rolar a tela p/ cima removendo uma linha
	}
}

// Imprime um caractere na posição atual do cursor
void printch(char c) {
	string vidmem = (string)0xb8000;
	switch(c) {
		case (0x08): // Retrocesso (BACKSPACE)
			if(cursorX > 0) {
				cursorX--; // Move cursor p/ posição anterior na largura
				vidmem[(cursorY * sw + cursorX)*sd] = 0x00; // Define o caractere como nulo
			}
			break;
		case (0x09): // Representa a tecla TAB
			cursorX = (cursorX + 8) & ~(8 - 1); // Move cursor p/ a próxima posição TAB
			break;
		case ('\r'): // Retorno de Carro
			cursorX = 0; // Move o cursor para a primeira posição na largura
			break;
		case ('\n'): // Nova Linha
			cursorX = 0; // Move o cursor para a primeira posição na largura
			cursorY++;  // Move o cursor para a próxima linha na altura
			break;
		default:
			vidmem[((cursorY * sw + cursorX)) * sd] = c; // Define o caractere na tela
			vidmem[((cursorY * sw + cursorX)) * sd + 1] = 0x0F; //Define a cor do caractere
			cursorX++; // Move o cursor para a próxima posição na largura
			break;
	}
	if (cursorX >= sw) {
		cursorX = 0; // Se ultrapassar a largura, move o cursor para a próxima linha
		cursorY++;  // na altura
	}
	newLineCheck(); // Verifica se o cursor atingiu a última linha da tela
	updateCursor();   // Atualiza a posição do cursor
}

// Imprime uma string chamando repetidamente printch para cada caractere na string
void print(string ch) {
	uint16 i = 0;
	for(i; i < strlength(ch); i++) {
		printch(ch[i]);  // Chama printch para cada caractere na string
	}
}
