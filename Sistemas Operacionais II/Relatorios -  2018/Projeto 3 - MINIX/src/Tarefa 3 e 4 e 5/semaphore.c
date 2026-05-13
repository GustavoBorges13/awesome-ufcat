#include <unistd.h>     /* Constantes simbolicas */
#include <sys/types.h>  /* Tipos de dados primitivos do sistema */ 
#include <errno.h>      /* Erros */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* Funcoes padrao */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* Manipulacao de string */
#include <semaphore.h>  /* Semaforos */


void handler ( void *ptr );

int counter; /* variavel compartilhada */

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;
    
    i[0] = 0; /* argumento para threads */
    i[1] = 1;
    
    pthread_create (&thread_a, NULL, (void *) &handler, (void *) &i[0]);
    pthread_create (&thread_b, NULL, (void *) &handler, (void *) &i[1]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    exit(0);
} 

void handler ( void *ptr )
{
    int x; 
    x = *((int *) ptr);
    printf("Thread %d: Aguardando para entrar na regiao critica...\n", x);

    /* REGIAO CRITICA */
    printf("Thread %d: Agora, na regiao critica...\n", x);
    printf("Thread %d: Valor do contador: %d\n", x, counter);
    printf("Thread %d: Incrementando o contador...\n", x);
    counter++;
    printf("Thread %d: Novo valor do contador: %d\n", x, counter);
    printf("Thread %d: Saindo da regiao critica...\n", x);
    /* FIM DA REGIAO CRITICA */    
    
    pthread_exit(0); 
}
