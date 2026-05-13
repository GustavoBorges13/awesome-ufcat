#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 
int main(void) {
    pid_t pids[5];
    int i;
    printf("PAI: Aqui esta meu PID: %d\n", getpid());
    for (i = 4; i >= 0; --i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            printf("FILHO: O PID do meu PAI eh: %d\n", getppid());
            printf("FILHO: Meu PID eh: %d\n", getpid());
            _exit(0);
        }
    }
    sleep(10); // Pausa de 10 segundos
    return 0;
}
