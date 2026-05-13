#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore, semaphore2;  //Variáveis do tipo semáforo
int counter = 0;  //Variável contadora

void enterSCQ(int i){ //Função para pegar o recurso Q
  sem_wait(&semaphore);
  printf("O processo %d pegou o recurso Q e aguarda pelo recurso S!!\n", i);
  return;
}

void leaveSCQ (){
  sem_post(&semaphore);
  return;
}

void enterSCS(int i){ //Função para pegar o recurso S
  sem_wait(&semaphore2);
  printf("O processo %d pegou o recurso S e aguarda pelo recurso Q!!\n", i);
  return;
}

void leaveSCS (){
  sem_post(&semaphore2);
  return;
}

void * pi (void *arg){
  int *aux = (int *)arg; //Índice
  enterSCS(*aux);  //Tenta alocar o recruso S
  sleep(1);
  enterSCQ(*aux);  //Tenta alocar o recurso Q
  printf("\nPi: A região crítica é minha!!!\n");
  counter++;
  printf("\n\nPi: counter = %d\n\n", counter);
  leaveSCS();
  leaveSCQ();
  return NULL;
}

void * pj (void *arg){
  int *aux = (int *)arg; //Índice
  enterSCQ(*aux);  //Tenta alocar o recruso Q
  sleep(1);
  enterSCS(*aux);  //Tenta alocar o recruso S
  printf("\nPj: A região crítica é minha!!!\n");
  counter++;
  printf("\n\nPj: counter = %d\n\n", counter);
  leaveSCQ();
  leaveSCS();
  return NULL;
}

int main (void){
  pthread_t thi, thj; //Variáveis para a criação de threads

  //Iniciação de semáforos
  sem_init(&semaphore, 0, 1);
  sem_init(&semaphore2, 0, 1);

  //Verificação se as threads foram criadas corretamente
  if((pthread_create (&thi, NULL, pi, (void *)0)) != 0){
    printf("Algum erro ocorreu!\n");
    exit(1);
  }
  if((pthread_create (&thj, NULL, pj, (void *)1)) != 0){
    printf("Algum erro ocorreu!\n");
    exit(1);
  }

  //Iniciando as threads
  pthread_join (thi, NULL);
  pthread_join (thj, NULL);

  //Destruindo os semáforos
  sem_destroy(&semaphore);
  sem_destroy(&semaphore2);

  return 0;
}
