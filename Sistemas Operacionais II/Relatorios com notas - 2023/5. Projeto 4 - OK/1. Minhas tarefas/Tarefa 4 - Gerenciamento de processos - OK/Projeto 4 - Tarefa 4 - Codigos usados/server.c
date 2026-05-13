#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define PACKET_SIZE 100

typedef struct {
    char message[PACKET_SIZE];
    pid_t writer_pid;
} PACKET;

int main() {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    PACKET packet;

    // Criando socket TCP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Erro ao abrir o socket");
        exit(EXIT_FAILURE);
    }

    // Configurando endereço do servidor
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Ligando o socket ao endereço do servidor
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erro ao fazer bind");
        exit(EXIT_FAILURE);
    }

    // Aguardando conexões
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Aceitando conexão do escritor
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("Erro ao aceitar conexão");
        exit(EXIT_FAILURE);
    }

    // Recebendo mensagem do escritor
    read(newsockfd, &packet, sizeof(PACKET));
    printf("Mensagem recebida: %s, escritor PID: %d\n", packet.message, packet.writer_pid);

    close(newsockfd);
    close(sockfd);

    return 0;
}
