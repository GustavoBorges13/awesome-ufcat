#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NFORKS 10

/*
 * void waitkey (void) { printf("Press |ENTER| to continue ...\n"); fflush
 * (stdout); getchar(); }
 */

void
do_nothing(void)
{
	printf("Parent: %d || Child pid: %d\n", getppid(), getpid());
	sleep(20);
	exit(0);
}

int
main(int argc, char *argv[])
{
	pid_t           whichone, pid[NFORKS];
	int             j, status, howmany;

	for (j = 0; j < NFORKS; j++) {

		if ((pid[j] = fork()) < 0) {
			printf("fork failed with error code= %d\n", pid[j]);
			exit(1);
		}
		if (pid[j] == 0) {
			do_nothing();
		}
	}

	howmany = 0;
	while (howmany < NFORKS) {
		/*
		 * waitpid (pid[j], &status, 0);
		 */
		whichone = wait(&status);
		howmany++;

		printf("Child exited (%d).\n", whichone);
	}
}
