import socket
from statistics import mean

def servidor():
    servidor_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    servidor_socket.bind(('localhost', 7779))
    servidor_socket.listen(1)

    print('Aguardando conexão...')
    cliente_socket, endereco = servidor_socket.accept()
    print(f'Conectado a {endereco}')

    lista_inteiros = []

    try:
        leitor = ler_linhas(cliente_socket)
        for valor in leitor:
            if valor == '-1':
                break
            lista_inteiros.append(int(valor))

        # Calcular a média dos inteiros recebidos
        media = mean(lista_inteiros)

        # Enviar a soma dos números de volta para o cliente
        resultado = f'A média dos números é: {media}\n'
        cliente_socket.sendall(resultado.encode())
    
    except (BrokenPipeError, OSError) as e:
        print(f"Erro durante a comunicação: {e}")

    finally:
        cliente_socket.close()
        servidor_socket.close()

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

if __name__ == "__main__":
    servidor()
