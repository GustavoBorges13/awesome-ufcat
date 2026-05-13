#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<locale.h>

pthread_t tid[2];
int counter;

void 
enterSC (int i)
{
  // Código aqui
}

void 
leaveSC (int i)
{
   // Código aqui
}

void * pi (void *arg){
  enterSC(0); // Entra na região crítica
  printf("\nPi: A região crítica é minha!!!\n");
  counter++;
  printf("\n\nPi: counter = %d\n\n", counter);
  leaveSC(0);
  
  return NULL;
}

void * pj (void *arg){
  
  enterSC(1); // Entra na região crítica
  printf("\nPj: A região crítica é minha!!!\n");
  counter++;
  printf("\n\nPj: counter = %d\n\n", counter);
  leaveSC(1);
  
  return NULL;
}

void testThread(int err){
  if (err != 0) {
    printf ("\ncan't create thread :[%s]", strerror (err));
    exit(0); // Se não conseguir criar alguma thread, cai fora.
  }
}

int
main (void)
{
  int err;
  setlocale(LC_ALL, "pt_BR.UTF-8");
  
  err = pthread_create (&(tid[0]), NULL, pi, NULL); // Tenta criar a thread
  testThread(err);  // Verifica se realmente criou a thread
  err = pthread_create (&(tid[1]), NULL, pj, NULL);
  testThread(err);  

  pthread_join (tid[0], NULL);
  pthread_join (tid[1], NULL);

  return 0;
}
