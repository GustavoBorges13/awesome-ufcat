#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigchld(int sig) {
    pid_t pid;
    int status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("PAI: Processo filho com PID %d terminou.\n", pid);
    }
}

int main(void) {
    pid_t pids[5];
    int i;
    printf("PAI: Aqui esta meu PID: %d\n", getpid());

    // Configura o sinal SIGCHLD para ser tratado pela função handle_sigchld
    signal(SIGCHLD, handle_sigchld);

    for (i = 4; i >= 0; --i) {
        pids[i] = fork();
        if (pids[i] == 0) {
        	 sleep(2); // Pausa de 2 segundos
            printf("FILHO: O PID do meu PAI eh: %d\n", getppid());
            printf("FILHO: Meu PID eh: %d\n", getpid());
            _exit(0);
        }
    }
    
    // Espera pelos processos filhos antes de terminar
    for (i = 4; i >= 0; --i) {
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}
