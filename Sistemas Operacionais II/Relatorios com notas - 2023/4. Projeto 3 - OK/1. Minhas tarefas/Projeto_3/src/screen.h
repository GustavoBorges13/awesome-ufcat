#ifndef SCREEN_H
#define SCREEN_H
#include "types.h"

void clearLine(uint8 from, uint8 to); // Limpa a partir de uma linha especifica ate outra linha especifica

void updateCursor(); 	// Envia a localizacao do cursor para uma porta especifica: 0x3D4 e 0x3D5. Portas para a arquitetura 			       // x86. Estas portas controlam a posicao do cursor na tela no modo VGA sendo usado (modo usando
			// 80 x 25 x 16 cores. Assim, para mudar a posicao do cursor, basta atualizar os valores de x e y
			// e entao chamar a funcao updateCursor(). Demo de uso em 25:40. Passar como exercicio para os 
			// alunos.

void clearScreen(); // Limpa toda a tela, definindo todas as linhas com espaço em branco e reposiciona o cursor no início.

void scrollUp(uint8 lineNumber); // Realiza uma rolagem para cima na tela, movendo o conteúdo para a linha superior e limpando as linhas inferiores.

void newLineCheck(); // Caso se alcance o limite da tela por limitacao de texto, move-se o texto uma linha para cima.
		     // Isso da a impressao que o texto "rola" para cima a medida que a tela vai sendo preenchida.

void printch(char c); // Pega um argumento char e imprime na tela.

void print(string ch); // Imprime uma string na tela na posição atual do cursor.

/* NOVAS funções */
void set_screen_color(int text_color, int bg_color); // Define a cor do texto e do fundo do terminal.
void set_screen_color_from_color_code(int color_code); // Define a cor do terminal com base em um código de cor.
void print_colored(string ch, int text_color, int bg_color); // Imprime uma string na tela com cores específicas.

#endif
