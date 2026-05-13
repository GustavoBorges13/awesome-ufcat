#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define PACKET_SIZE 100

typedef struct {
    char message[PACKET_SIZE];
    pid_t writer_pid;
} PACKET;

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    PACKET packet;

    // Criando socket TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Erro ao abrir o socket");
        exit(EXIT_FAILURE);
    }

    // Configurando endereço do servidor
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Erro, host não encontrado\n");
        exit(EXIT_FAILURE);
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Conectando ao servidor
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erro ao conectar");
        exit(EXIT_FAILURE);
    }

    // Preenchendo a estrutura de pacote com uma mensagem
    strcpy(packet.message, "Mensagem do escritor");
    packet.writer_pid = getpid();

    // Enviando mensagem para o servidor
    write(sockfd, &packet, sizeof(PACKET));

    close(sockfd);

    return 0;
}
