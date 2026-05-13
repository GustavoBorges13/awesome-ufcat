#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NFORKS 10

void do_nothing() {
    int i;
    i = 0;
}

int main(int argc, char *argv[]) {
    int pid, j, status;

    // Verifica se o número de argumentos é correto
    if (argc != NFORKS + 1) {
        printf("Uso: %s status1 status2 ... status%d\n", argv[0], NFORKS);
        exit(EXIT_FAILURE);
    }

    // Loop para criar NFORKS processos filhos
    for (j = 1; j <= NFORKS; j++) {
        // Criação do processo filho
        if ((pid = fork()) < 0) {
            printf("fork falhou com o código de erro= %d\n", pid);
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Código executado pelo processo filho
            do_nothing();
            // Sai do processo filho com o status fornecido pelo argumento correspondente
            exit(atoi(argv[j]));
        }
    }

    // Loop para esperar por todos os processos filhos
    for (j = 0; j < NFORKS; j++) {
        // Espera pelo término de um processo filho
        wait(&status);
        // Verifica se o processo filho terminou normalmente
        if (WIFEXITED(status)) {
            // Imprime o status de saída do processo filho
            printf("Processo filho %d finalizado com status de saída: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
