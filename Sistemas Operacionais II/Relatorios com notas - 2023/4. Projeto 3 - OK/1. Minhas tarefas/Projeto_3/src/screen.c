#include "screen.h"
#include "system.h"
#include "string.h"

int32 cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2; // Largura, altura e profundidade da tela

int color = 0x02; // NOVO: armazena a cor corrente usada no terminal

// NOVO: funcao clearLine() modificada para usar color
void clearLine(uint8 from, uint8 to) { // Limpa a partir de uma linha especifica ate outra linha especifica
  string vidmem = (string)0xb8000;  // Por ser um endereco numerico, sofre casting. Esse endereco representa a primeira
   
  // i = Largura * inicio * profundidade 
  // posicao da tela (tela de boot).
  for (uint16 i = sw * from * sd; i < (sw * to * sd); i++) {// NOVO
    vidmem[(i/2)*2+1] = color; // NOVO: referente a cor
    vidmem[(i/2)*2] = 0; // NOVO: referente ao caractere
  }
}

void updateCursor() { // Envia a localizacao do cursor para uma porta especifica: 0x3D4 e 0x3D5. Portas para a arquitetura 			    // x86. Estas portas controlam a posicao do cursor na tela no modo VGA sendo usado (modo usando
			// 80 x 25 x 16 cores. Assim, para mudar a posicao do cursor, basta atualizar os valores de x e y
			// e entao chamar a funcao updateCursor(). Demo de uso em 25:40. Passar como exercicio para os 
			// alunos.
  unsigned temp;
  temp = cursorY * sw + cursorX; 	// Posicao = (y * largura) + x. Obs. Variaveis x e y definidas como globais

  outportb(0x3D4, 14);			// CRT Control Register: seleciona a localizacao do cursor
  outportb(0x3D5, temp >> 8);		// Envia o byte de alta no barramento
  outportb(0x3D4, 15);			// CRT Control Register: seleciona o envio do byte de baixa
  outportb(0x3D5, temp);		// Envia o byte de baixa da localizacao do cursor
}

void clearScreen() {
  clearLine(0,sh-1);
  cursorX = 0;
  cursorY = 0;
  updateCursor();
}

void scrollUp(uint8 lineNumber) {
  string vidmem = (string)0xb8000;
 
  for (uint16 i = 0; i < sw * (sh - 1) * sd; i++)
  {
    vidmem[i] = vidmem[i + sw * sd * lineNumber]; // Move para a linha lineNumber para a linha 0 e depois move todas as 
						                                      // demais linhas abaixo de lineNumber subsequentemente.
  }
  
  clearLine(sh - 1 - lineNumber, sh - 1); // Ao mover todas as linhas a partir de lineNumber para o topo, apagam-se as 
					                                // copias 
  
  if ((cursorY - lineNumber) < 0) // Ao se mover o cursor para cima, garante que ele nao "some" da tela. Se isso ocorrer,
				                          // ele e colocado na primeira posicao valida.
  {
    cursorY = 0;
    cursorX = 0;
  }
  else 
  {
    cursorY -= lineNumber; // Se o cursor nao sair da tela, ele sera movido lineNumber posicoes para cima.
  }
  updateCursor(); // Atualiza a posicao do cursor, apos a atualizacao das variaveis cursorX e cursorY.
}

void newLineCheck() { // Caso se alcance o limite da tela por limitacao de texto, move-se o texto uma linha para cima.
		    // Isso da a impressao que o texto "rola" para cima a medida que a tela vai sendo preenchida.
  if(cursorY >= sh-1)
  {
    scrollUp(1);
  }
}

void printch(char c) { // Pega um argumento char e imprime na tela.
  string vidmem = (string)0xb8000;

  switch(c) 
  {
    case (0x08): // Representa a tecla backspace
	    if(cursorX > 0)
	    {
	      cursorX--; // Cursor move-se uma posicao a esquerda em X
	      vidmem[(cursorY * sw + cursorX)*sd] = 0x00; // Na posicao original onde o cursor estava, apagamos o conteudo
	    }
	    break;
    case (0x09): // Representa a tecla TAB
	    cursorX = (cursorX + 8) & ~(8 - 1); // Desloca a quantidade de espacos equivalente ao TAB.
					     // soma 8 ao cursorX e depois, faz uma operacao AND bitwise com o valor 
					     // ~7 em 32 bits, ou seja, mascara os 3 ultimos bits.
	      break;
    case ('\r'): // Carriage return ou retorno de carro
	    cursorX = 0;
	    break;
    case ('\n'): // Avanco de linha
	    cursorX = 0;
	    cursorY++;
	    break;
    default: // Demais casos, basicamente imprime-se o caractere na cor branca
	    vidmem[((cursorY * sw + cursorX)) * sd] = c;
	    vidmem[((cursorY * sw + cursorX)) * sd + 1] = color; // 0x(cor do fundo)(cor da fonte) NOVO
	    cursorX++;
	    break;
    }
  
  if (cursorX >= sw) // Cursor na posicao X chegou ao fim da tela, vai para o comeco da proxima linha
  {
    cursorX = 0;
    cursorY++;
  }
  newLineCheck(); // Verifica se chegamos a ultima linha da tela. Se sim, faz a rolagem uma linha para cima.
  updateCursor();
}

void print(string ch) {
  uint8 length = strlength(ch); // Atualizacao: dado armazenado em uma variavel para evitar chamar a funcao strlength() varias vezes.
  
  for(uint16 i = 0; i < length; i++)
  {
    printch(ch[i]);
  }
}

/* NOVAS funcoes */
void set_screen_color(int text_color, int bg_color) {
  color = (bg_color << 4) | text_color;
}

void set_screen_color_from_color_code(int color_code) {
  color = color_code;
}

void print_colored(string ch, int text_color, int bg_color) {
  int current_color = color;
  set_screen_color(text_color, bg_color);
  print(ch);
  set_screen_color_from_color_code(current_color);
}
