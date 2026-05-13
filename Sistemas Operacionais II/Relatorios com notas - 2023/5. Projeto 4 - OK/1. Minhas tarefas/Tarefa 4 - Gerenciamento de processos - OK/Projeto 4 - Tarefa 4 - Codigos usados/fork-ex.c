#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // Incluir a biblioteca para a função waitpid

#define NFORKS 50000

void do_nothing () {
  int i;
  i = 0;
}

int main (int argc, char *argv[]) {
  int pid, j, status;

  // Loop para criar NFORKS processos filhos
  for (j = 0; j < NFORKS; j++) {
      // Tentativa de criar um processo filho
      if ((pid = fork ()) < 0) {
	  // Se a chamada fork() falhou, exibe uma mensagem de erro e sai do programa
	  printf ("fork falhou com o código de erro= %d\n", pid);
	  exit (0);
	}

      // Se a chamada fork() retornar 0, estamos no processo filho
      else if (pid == 0) {
	  // Chama a função do_nothing() no processo filho
	  do_nothing ();
	  // Sai do processo filho
	  exit (0);
	}

      // Se a chamada fork() retornar um valor positivo, estamos no processo pai
      else	{
	  // O processo pai espera pelo término do processo filho com waitpid()
	  waitpid (pid, &status, 0);
	}
    }
}
