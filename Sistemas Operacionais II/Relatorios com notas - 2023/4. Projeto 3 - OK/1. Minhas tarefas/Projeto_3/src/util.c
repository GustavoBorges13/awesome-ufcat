#include "util.h"
#include "string.h"

void memory_copy(char *source, char *dest, int nbytes) {
  int i;
  for (i=0 ; i < nbytes; i++) {
    *(dest + i) = *(source + i); // dest[i] = source[i]
  }
}

void memory_set(uint8 *dest, uint8 val, uint32 len) {
  uint8 *temp = (uint8 *)dest;
  for ( ; len != 0; len--) 
    *temp++ = val;
}

void int_to_ascii(int n, char str[]) {
  int i;

  if (n < 0) // trabalho com qualquer número em módulo
    n = -n;

  i = 0;

  do {
    str[i++] = n % 10 + '0'; //5 ---> 5 + '0' = 5 + 48 = 53 que é o ASCII do 5
  } while ((n /= 10) > 0);

  str[i] = '\0'; // para fechar a string de maneira apropriada em C

  //TODO: implementacao do 'reverso'
}

/* NOVAS funcoes */
string int_to_string(int n) {
    string ch = malloc(50);
    int_to_ascii(n, ch);
    int len = strlength(ch);
    int i = 0, j = len - 1;

    while (i < (len / 2 + len % 2)) {
        char tmp = ch[i];
        ch[i] = ch[j];
        ch[j] = tmp;
        i++;
        j--;
    }

    return ch;
}

int str_to_int(string ch) {
    int n = 0;
    int p = 1;
    int strlen = strlength(ch);
    int i;

    for (i = strlen - 1; i >= 0; i--) {
        n += ((int)(ch[i] - '0')) * p;
        p *= 10;
    }

    return n;
}

void * malloc(int nbytes) {
    // maneira simples mas
    // malloc - nao faz uso de
    // mcb
    char variable[nbytes];
    return &variable;
}
