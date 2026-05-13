#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PACKET_SIZE 100

typedef struct {
    char message[PACKET_SIZE];
    pid_t writer_pid;
} PACKET;

void writer(int fd) {
    PACKET packet;
    packet.writer_pid = getpid();

    strcpy(packet.message, "Mensagem do escritor");
    write(fd, &packet, sizeof(PACKET));
}

void reader(int fd) {
    PACKET packet;
    int bytes_read;

    while ((bytes_read = read(fd, &packet, sizeof(PACKET))) > 0) {
        printf("Mensagem recebida: %s, escritor PID: %d\n", packet.message, packet.writer_pid);
    }
}

int main() {
    int fd;
    pid_t pid;

    // Criar o FIFO (pipe nomeado)
    mkfifo("fifo_pipe", 0666);

    // Criar processo leitor
    if ((pid = fork()) == 0) {
        fd = open("fifo_pipe", O_RDONLY);
        reader(fd);
        close(fd);
        exit(0);
    }

    // Criar processo escritor 1
    if ((pid = fork()) == 0) {
        fd = open("fifo_pipe", O_WRONLY);
        writer(fd);
        close(fd);
        exit(0);
    }

    // Criar processo escritor 2
    if ((pid = fork()) == 0) {
        fd = open("fifo_pipe", O_WRONLY);
        writer(fd);
        close(fd);
        exit(0);
    }

    // Esperar pelos processos filhos
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    // Remover o FIFO
    unlink("fifo_pipe");

    return 0;
}
