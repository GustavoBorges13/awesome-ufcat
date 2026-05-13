#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define QTD_WRITERS 2
#define BUFFER 256

typedef struct{
	int id, lastone;
	char data[BUFFER];
}PACKET;

int main(){
	pid_t pid;
	int fd[2], i;
	if(pipe(fd) < 0){
		perror("pipe");
		return -1;
	}
	for(i = 0; i < QTD_WRITERS; i++){
		if((pid = fork()) < 0){
			perror("fork");
			exit(1);
		}
		if(pid > 0){
			close(fd[0]);
			PACKET escritor;
			escritor.id = getpid();
			strcpy(escritor.data,"escrevendo......");
			if(i == QTD_WRITERS-1)
				escritor.lastone = 1;
			else
				escritor.lastone = 0;
			write(fd[1], &escritor, sizeof(escritor));
			exit(0);
		}
	}
	PACKET leitor;
	close(fd[1]);
	do{
		read(fd[0], &leitor, sizeof(leitor));
		printf("\n\nEscritor %d - Mensagem:\n%s\n",leitor.id,leitor.data);
		sleep(3);
	}while(!leitor.lastone);
	exit(0);
}