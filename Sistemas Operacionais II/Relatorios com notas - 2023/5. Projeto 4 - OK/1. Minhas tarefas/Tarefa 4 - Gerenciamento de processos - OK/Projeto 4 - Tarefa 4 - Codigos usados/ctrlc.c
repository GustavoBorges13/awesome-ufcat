#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig); /* Protótipo do handler */

int main(void) {
    char s[200];

    /* Instala o handler para SIGINT (Ctrl+C) */
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    printf("Entre uma string:\n");

    /* Lê a string com fgets */
    if (fgets(s, sizeof(s), stdin) == NULL) {
        perror("fgets");
    } else {
        printf("Você digitou: \"%s\"\n", s);
    }

    return 0;
}

/* Handler para SIGINT (Ctrl+C) */
void sigint_handler(int sig) {
    printf("Agora não!\n");
}
