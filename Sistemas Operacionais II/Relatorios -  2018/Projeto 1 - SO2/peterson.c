#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  //Bilbioteca de threads

#define true 1
#define false 0

pthread_t flag[2] = {false, false};
int turn;
int counter = 0;

void enterSC (int i){ //Função para entrar na seção crítica
  int j = 1 - i;  //J sempre vai ser oposto de i: caso i == 0, j == 1 e vice versa
  flag[i] = true; //O vetor flag recebe na posição i (thread que solicita entrada na seção crítica)
  turn = j;
  while(flag[j] && turn == j);  //Laço para segurar a seção crítica
  return;
}

void leaveSC (int i){ //Função para sair da seção crítica
  flag[i] = false;  //O vetor flag recebe na posição i (thread que solicita sair da seção crítica)
  return;
}

void * cria (void *arg){  //Função para a thread
  int *aux = (int *)arg;  //Pegar o índice da thread
  enterSC(*aux);  //Chamada da função para entrar na seção crítica
  printf("\nP%d: A região crítica é minha!!!\n", *aux);
  counter++;
  printf("\n\nP%d: counter = %d\n\n", *aux, counter);
  leaveSC(*aux);  //Função para sair da seção crítica
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
