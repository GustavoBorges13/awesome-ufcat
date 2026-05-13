#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5	//Número de filósofos
#define LEFT (i+N-1)%N	//Filosofo à esquerda de i
#define RIGHT (i+1)%N	//Filosofo à direita de i
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_t tid[N];	//Uma thread para cada filósofo
int state[N];	//Estado de cada filósofo
sem_t mutex;
sem_t s[N];

void test(int i){	//Testa se o filósofo pode pegar os garfos
	if(state[LEFT] == 0)
		printf("O filosofo a esquerda de %d está pensando!!\n", i+1);
	else if (state[LEFT] == 1)
		printf("O filosofo a esquerda de %d está com fome!!\n", i+1);
	else if (state[LEFT] == 2)
		printf("O filosofo a esquerda de %d está comendo!!\n", i+1);

	if(state[RIGHT] == 0)
		printf("O filosofo a direita de %d está pensando!!\n", i+1);
	else if (state[RIGHT] == 1)
		printf("O filosofo a direita de %d está com fome!!\n", i+1);
	else if (state[RIGHT] == 2)
		printf("O filosofo a direita de %d está comendo!!\n", i+1);

	//Testa se o filósofo pode pegar os garfos
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[i] = EATING;
		printf("O filosofo %d pegou os garfos %d e %d\n", i+1, LEFT+1, i+1);
		sem_post(&s[i]);
	}
}

void take_forks(int i){	//Função para pegar os garfos
	sem_wait(&mutex);	//Trava o semáforo mutex
	state[i] = HUNGRY;	//Muda o estado do filósofo para "Faminto"
	printf("O filosofo %d está com fome!!\n", i+1);
	test(i);	//Chama a função para testar a situação dos garfos à direita e esquerda
	sem_post(&mutex);	//Libera o semáforo mutex
	sem_wait(&s[i]);	//Trava o semáforo do filósofo i
}

void put_forks(int i){	//Função para devolver os garfos
	sem_wait(&mutex);	//Trava o semáforo mutex
	state[i] = THINKING;	//Altera o estado do filósofo i para "Pensando"
	printf("O filosofo %d devolveu os garfos %d e %d e está pensando!!\n", i+1, LEFT+1, i+1);
	test(LEFT);	//Verifica a situação do filósofo à esquerda
	test(RIGHT);	//Verifica a situação do filósofo à direita
	sem_post(&mutex);	//Libera o semárofo mutex
}

void *philosopher(void *arg){	//Função do filósofo
	int *i = (int *) arg;	//Índice do filósofo
	while(1){
		sleep(2);
		take_forks(*i);	//O filósofo tenta pegar os garfos
		printf("O filosofo %d comeu.\n", *i+1);	//O filósofo conseguiu os garfos para comer
		put_forks(*i);	//O filósofo i devolve os garfos
	}
}

int main (void){
	int i;
  sem_init(&mutex, 0, 1);	//Iniciando a variável de semáforo mutex

	//Iniciando as variáveis de semáforo para cada filósofo
	for(i = 0; i < N; i++)
		sem_init(&s[i], 0, 0);

	//Criando uma thread para cada filósofo
  for(i=0;i<N;i++)
  	pthread_create (&(tid[i]), NULL, philosopher, &i);

	//Iniciando cada thread criada
  for(i=0;i<N;i++)
  	pthread_join (tid[i], NULL);

	//Ao final, destruindo os semáforos criados anteriormente
	for(i=0;i<N;i++)
  	sem_destroy(&s[i]);
	sem_destroy(&mutex);

  return 0;
}
