#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define NFORKS 10

void do_nothing() {
    pid_t parent_pid = getppid(); // Obter o PID do processo pai
    pid_t child_pid = getpid(); // Obter o PID do processo filho
    printf("PID do processo pai: %d, PID do processo filho: %d\n", parent_pid, child_pid);
    fflush(stdout); // Limpar o buffer de saída para garantir que a mensagem seja exibida imediatamente
}

int main(int argc, char *argv[]) {
    int pid, j, status;

    printf("Iniciando o programa...\n");

    // Loop para criar NFORKS processos filhos
    for (j = 0; j < NFORKS; j++) {
        // Tentativa de criar um processo filho
        if ((pid = fork()) < 0) {
            // Se a chamada fork() falhou, exibe uma mensagem de erro e sai do programa
            printf("fork falhou com o código de erro= %d\n", pid);
            exit(0);
        } else if (pid == 0) {
            // Se a chamada fork() retornar 0, estamos no processo filho
            printf("Processo filho %d iniciado\n", getpid());
            // Chama a função do_nothing() no processo filho
            do_nothing();
            printf("Processo filho %d concluído\n", getpid());
            // Sai do processo filho
            exit(0);
        }
    }

    // O processo pai espera pelo término dos processos filhos com waitpid()
    for (j = 0; j < NFORKS; j++) {
        wait(&status);
    }

    printf("Todos os processos filhos concluídos\n");

    return 0;
}