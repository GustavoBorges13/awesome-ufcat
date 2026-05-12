import socket
import time

cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    cliente_socket.connect(('localhost', 7779))
    print('Conexão estabelecida')
except socket.error as erro:
    print(f"Não foi possível estabelecer conexão com o servidor informado: {erro}")
    cliente_socket.close()
    exit()

def enviar_inteiro_por_vez(sock, lista_inteiros):
    for numero in lista_inteiros:
        try:
            dado = str(numero) + '\n'
            sock.sendall(dado.encode())
            time.sleep(5)
        except (BrokenPipeError, OSError) as e:
            print(f"Erro durante o envio: {e}")
            sock.close()
            exit()

def ler_linhas(sock, recv_buffer=4096, delim='\n'):
    buffer = ''
    dados = True
    while dados:
        dados = sock.recv(recv_buffer).decode(encoding='UTF-8')
        if dados == '':
            print('Conexão encerrada.')
            sock.close()
            exit()
        else:
            buffer += str(dados)
            while buffer.find(delim) != -1:
                linha, buffer = buffer.split('\n', 1)
                yield linha

lista_inteiros = [4, 5, 89]

enviar_inteiro_por_vez(cliente_socket, lista_inteiros)

# Aguarde e exiba a resposta do servidor
leitor = ler_linhas(cliente_socket)
for valor in leitor:
    print(f"Resposta do servidor: {valor}")

cliente_socket.close()
