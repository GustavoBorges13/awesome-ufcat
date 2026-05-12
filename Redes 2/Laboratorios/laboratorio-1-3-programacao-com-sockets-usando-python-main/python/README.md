# Clientes e Servidores do Laboratório 1.3

## Parte A e B

explique aqui como executar o seu cliente e o servidor. caso seja necessário a instalação de alguma biblioteca não padrão do Python (não inclusa por default), informe também.

Parte A
Código do Cliente:
O código do cliente estabelece uma conexão TCP/IP com um servidor usando o módulo socket em Python. Aqui está uma breve explicação de cada parte do código:

1. Importações:

import socket: Importa o módulo de soquetes para comunicação de rede.
import time: Adiciona a capacidade de introduzir atrasos no código.

2. Configuração do Cliente:

cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM): Cria um objeto de soquete usando IPv4 (AF_INET) e TCP (SOCK_STREAM).
Tratamento de Erros na Conexão:

3. O código inclui um bloco try e except para tratar exceções do tipo socket.error (também conhecido como OSError). Ele lida com erros na tentativa de conexão, como falha ao conectar a um endereço IP ou porta inacessível.

4.Função ler_linhas:

ler_linhas(sock, recv_buffer=4096, delim='\n'): Uma função que lê linhas de dados do soquete até encontrar o caractere de nova linha (\n). Isso é usado para processar as mensagens recebidas.

5. Loop Principal:

 Um loop enquanto uma condição é verdadeira, que envia números para o servidor em intervalos regulares (time.sleep(5)).

Parte B

Código do Servidor:
O código do servidor é responsável por aceitar conexões, receber uma lista de inteiros do cliente e calcular a média dos números. Aqui está uma explicação de cada parte:

1. Importações:

import socket: Importa o módulo de soquetes para comunicação de rede.
from statistics import mean: Importa a função mean do módulo statistics para calcular a média dos números.

2. Configuração do Servidor:

servidor_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM): Cria um objeto de soquete do servidor usando IPv4 (AF_INET) e TCP (SOCK_STREAM).
servidor_socket.bind(('localhost', 7779)): Liga o soquete a um endereço e porta específicos.

3. Aguardando Conexão:

servidor_socket.listen(1): Aguarda por uma conexão. O número 1 especifica o número máximo de conexões pendentes.

4. Aceitando Conexão:

cliente_socket, endereco = servidor_socket.accept(): Aceita a conexão quando um cliente tenta se conectar e retorna um novo soquete para comunicação e o endereço do cliente.

5.Função ler_linhas:

Uma função semelhante à do cliente, usada para ler as linhas de dados do soquete.

6. Processamento dos Dados:

O servidor lê os números recebidos até que -1 seja encontrado, calcula a média usando a função mean e envia a média de volta ao cliente.

7. Tratamento de Erros:

Um bloco try e except captura exceções do tipo BrokenPipeError e OSError, lidando com problemas de comunicação e encerrando o soquete adequadamente.
