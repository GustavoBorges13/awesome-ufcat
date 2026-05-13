#include "kb.h"
#include "system.h"

string readStr()
{
  char buff[256];
  string buffstr = buff;
  uint8 i = 0;
  uint8 reading = 1;

  while(reading) 
  { /*
     * Para ler dados do teclado, precisaremos ler dados de duas portas diferentes: 0x64 e 0x60. 
     * O endereco 0x64 permite ler o status do teclado, para saber quando uma tecla e pressionada.
     * O endereco 0x60 permite a leitura do "valor" da  tecla pressionada.
     */ 

    if(inportb(0x64) & 0x1) // indica se uma tecla foi pressionada. Como não existe scancode 0, qquer coisa diferente de 0 é válida.
    {
      switch(inportb(0x60)) // Esse switch representa a conversão entre scancode e ascii. A leitura no teclado é realizada inicialmente em scancode e aqui
                            // fazemos a conversão para ascii. Para a tabela completa vide: http://appplant.tistory.com/11 e 
                            // https://www.millisecond.com/support/docs/v5/html/language/scancodes.htm
                            // Esse scancode apresentado e para teclados americanos. Para outros idiomas, procure no site da Microsoft.
      {
        /*case 1:
		        printch((char)27);
		        buffstr[i] = (char)27;
 		        i++;
		        break;*/
        case 2:
		        printch('1');
		        buffstr[i] = '1'; // Adiciona o caracter ao final da variavel buffstr.
 		        i++;
		        break;
        case 3:
		        printch('2');
		        buffstr[i] = '2';
 		        i++;
		        break;
        case 4:
		        printch('3');
		        buffstr[i] = '3';
 		        i++;
		        break;
        case 5:
		        printch('4');
		        buffstr[i] = '4';
 		        i++;
		        break;
        case 6:
		        printch('5');
		        buffstr[i] = '5';
 		        i++;
		        break;
        case 7:
		        printch('6');
		        buffstr[i] = '6';
 		        i++;
		        break;
        case 8:
		        printch('7');
		        buffstr[i] = '7';
 		        i++;
		        break;
        case 9:
		        printch('8');
		        buffstr[i] = '8';
 		        i++;
		        break;
        case 10:
		        printch('9');
		        buffstr[i] = '9';
 		        i++;
		        break;
        case 11:
		        printch('0');
		        buffstr[i] = '0';
 		        i++;
		        break;
        case 12:
		        printch('-');
		        buffstr[i] = '-';
 		        i++;
		        break;
        case 13:
		        printch('=');
		        buffstr[i] = '=';
 		        i++;
		        break;
        case 14:
		        printch('\b');
		        buffstr[i] = '0';
 		        i++;
		        break;
        /* case 15:
		        printch('\t');
		        buffstr[i] = '\t';
 		        i++;
		        break; */
        case 15:
		        printch((char)9);
		        buffstr[i] = (char)9;
 		        i++;
		        break; 
        case 16:
		        printch('q');
		        buffstr[i] = 'q';
 		        i++;
		        break;
        case 17:
		        printch('w');
		        buffstr[i] = 'w';
 		        i++;
		        break;
        case 18:
		        printch('e');
		        buffstr[i] = 'e';
 		        i++;
		        break;
        case 19:
		        printch('r');
		        buffstr[i] = 'r';
 		        i++;
		        break;
        case 20:
		        printch('t');
		        buffstr[i] = 't';
 		        i++;
		        break;
        case 21:
		        printch('y');
		        buffstr[i] = 'y';
 		        i++;
		        break;
        case 22:
		        printch('u');
		        buffstr[i] = 'u';
 		        i++;
		        break;
        case 23:
		        printch('i');
		        buffstr[i] = 'i';
 		        i++;
		        break;
        case 24:
		        printch('o');
		        buffstr[i] = 'o';
 		        i++;
		        break;
        case 25:
		        printch('p');
		        buffstr[i] = 'p';
 		        i++;
		        break;
        case 26:
		        printch('[');
		        buffstr[i] = '[';
 		        i++;
		        break;
        case 27:
		        printch(']');
		        buffstr[i] = ']';
 		        i++;
		        break;
        case 28: //Enter
		        //printch((char)13);
		        //buffstr[i] = (char)13;
 		        //i++;
			      reading = 0;
		        break;
        /* case 29:
		        printch('q');   Left control
		        buffstr[i] = 'q';
 		        i++;
		        break; */
        case 30:
		        printch('a');
		        buffstr[i] = 'a';
 		        i++;
		        break;
        case 31:
		        printch('s');
		        buffstr[i] = 's';
 		        i++;
		        break;
        case 32:
		        printch('d');
		        buffstr[i] = 'd';
 		        i++;
		        break;
        case 33:
		        printch('f');
		        buffstr[i] = 'f';
 		        i++;
		        break;
        case 34:
		        printch('g');
		        buffstr[i] = 'g';
 		        i++;
		        break;
        case 35:
		        printch('h');
		        buffstr[i] = 'h';
 		        i++;
		        break;
        case 36:
		        printch('j');
		        buffstr[i] = 'j';
 		        i++;
		        break;
        case 37:
		        printch('k');
		        buffstr[i] = 'k';
 		        i++;
		        break;
        case 38:
		        printch('l');
		        buffstr[i] = 'l';
 		        i++;
		        break;
        case 39:
		        printch(';');
		        buffstr[i] = ';';
 		        i++;
		        break;
        case 40:
		        printch((char)39); // aspas simples (')
		        buffstr[i] = (char)39;
 		        i++;
		        break;
        case 41:
		        printch((char)96);
		        buffstr[i] = (char)96; // crase (`)
 		        i++;
		        break;
        /* case 42:
		        printch('l');     L shift
		        buffstr[i] = 'l';
 		        i++;
		        break; */
        case 43:
		        printch((char)92);
		        buffstr[i] = (char)92;
 		        i++;
		        break;
        case 44:
		        printch('z');
		        buffstr[i] = 'z';
 		        i++;
		        break;
        case 45:
		        printch('x');
		        buffstr[i] = 'x';
 		        i++;
		        break;
        case 46:
		        printch('c');
		        buffstr[i] = 'c';
 		        i++;
		        break;
        case 47:
		        printch('v');
		        buffstr[i] = 'v';
 		        i++;
		        break;
        case 48:
		        printch('b');
		        buffstr[i] = 'b';
 		        i++;
		        break;
        case 49:
		        printch('n');
		        buffstr[i] = 'n';
 		        i++;
		        break;
        case 50:
		        printch('m');
		        buffstr[i] = 'm';
 		        i++;
		        break;
        case 51:
		        printch((char)44);
		        buffstr[i] = (char)44; // acento agudo
 		        i++;
		        break;
        case 52:
		        printch('.');
		        buffstr[i] = '.';
 		        i++;
		        break;
        case 53:
		        printch('/');
		        buffstr[i] = '/';
 		        i++;
		        break;
        /* case 54:
		        printch(' ');     RShift
		        buffstr[i] = ' ';
 		        i++;
		        break; */
        /* case 55:
		        printch(' ');     PrtSc
		        buffstr[i] = ' ';
 		        i++;
		        break; */
        /* case 56:
		        printch(' ');     Alt
		        buffstr[i] = ' ';
 		        i++;
		        break; */
        case 57:
		        printch(' ');
		        buffstr[i] = ' ';
 		        i++;
		        break;
      }
    }
  }
  buffstr[i] = 0;   // Ajuste do último caractere como em toda string em C

  return buffstr;
}
