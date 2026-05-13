#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	3

void *PrintHello(void *threadid)
{
    /* ... */
}

int main(int argc, char *argv[])
{
pthread_t threads[NUM_THREADS];
int rc; /* rc recebe o retorno de pthread_create para tratamento de erro */
long t;
for(t=0;t<NUM_THREADS;t++){
  printf("MAIN: criando a thread %ld\n", t);
  /* 
   * Insira seu coidgo aqui...
   */

  }
}
