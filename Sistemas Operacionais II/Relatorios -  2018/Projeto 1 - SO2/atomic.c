#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>  //Biblioteca atomic

int counter;
atomic_flag lock = ATOMIC_FLAG_INIT;  //Variável atômica

void enterSC (){ //Função para entrar na seção crítica
  atomic_flag_test_and_set(&lock);  //Trava a seção crítica
  return;
}

void leaveSC (){ //Função para deixar a seção crítica
  atomic_flag_clear(&lock); //Libera a seção crítica
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

  return 0;
}
