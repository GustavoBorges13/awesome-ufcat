#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  //Biblioteca para o uso de threads
#include <semaphore.h>  //Bilbioteca para o uso de semáforos

sem_t semaphore;  //Variável de semáforo
int counter = 0;

void enterSC (){  //Função para controlar entrada na seção crítica
  sem_wait(&semaphore); //Para fazer o lock do semáforo
  return;
}

void leaveSC (){  //Função para sair da seção crítica
  sem_post(&semaphore); //Função que libera o semáforo
  return;
}

void * cria (void *arg){  //Função para a thread
  int *aux = (int *)arg, i = 0;  //Pegar o índice da thread
  enterSC();  //Chamada da função para entrar na seção crítica
  printf("\nP%d: A região crítica é minha!!!\n", *aux);
  counter++;
  printf("\n\nP%d: counter = %d\n\n", *aux, counter);
  leaveSC();  //Função para sair da seção crítica
  return NULL;
}

int main (void){
  pthread_t thi, thj; //Duas variáveis para a criação das threads
  sem_init(&semaphore, 0, 1); //Função para inicializar a variável de semáforo

  //Verifica se a thread foi criada corretamente
  if((pthread_create (&thi, NULL, cria, (void *)0)) != 0){
    printf("Algum erro ocorreu!\n");
    exit(1);
  }

  //Verifica se a thread foi criada corretamente
  if((pthread_create (&thj, NULL, cria, (void *)1)) != 0){
    printf("Algum erro ocorreu!\n");
    exit(1);
  }

  //Inicia as threads
  pthread_join (thi, NULL);
  pthread_join (thj, NULL);

  //Destrói a variável do semáforo ao fim do programa
  sem_destroy(&semaphore);
  return 0;
}
