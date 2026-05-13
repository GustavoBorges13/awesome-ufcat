#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define NFORKS 10

void
do_nothing()
{
	int	i;
	i = 0;
	printf("Processo pai = %d - Processo filho = %d\n", getppid(), getpid());
}

int
main(int argc, char *argv[])
{
	int j, status,pid[NFORKS];

	for (j = 0; j < NFORKS; j++) {

		if ((pid[j] = fork()) < 0) {
			printf("fork falhou com o codigo de erro= %d\n", pid[j]);
			exit(0);
		} else if (pid[j] == 0) {
			do_nothing();
			exit(0);
		}
	}

	system("pstree -p | grep fork-ex");
	sleep(10);
	system("pstree -p | grep fork-ex");
	//system("kill %d", getppid());
	//system("pstree | grep fork-ex");


	for(j = 0; j < NFORKS; j++){
		waitpid(pid[j], status, 0);
	}
}
