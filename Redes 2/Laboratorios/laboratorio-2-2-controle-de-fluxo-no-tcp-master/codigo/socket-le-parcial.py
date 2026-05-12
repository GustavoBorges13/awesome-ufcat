## AINDA FALTA AJUSTAR O TAMANHO DO BUFFER PARA RESOLVER O PROBLEMA DO LABORATORIO

import sys

IP = '127.0.0.1'
PORTA = 8888

if IP == '' or PORTA == 0:
   print("Porta ou ip de destino indefinido.")
   sys.exit(1)

import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# supondo H2 com ip 10.0.0.2 como endereco local do servidor
serversocket.bind((IP, PORTA))

serversocket.listen(1)

# servidor aceita conexao, mas nao interage com cliente
# deixando buffer de recepcao ser livremente preenchido
print('Esperando conexao TCP na porta ',PORTA)
(conexao, endereco) = serversocket.accept()
print('Conexao estabelecida com',endereco)

total_lido = 0

while True:
   strBytesLer = input('Numero de kbytes para ler: ')
   bytesLer = max(1,int(strBytesLer)//1024)*1024

   b = conexao.recv(bytesLer)
   total_lido = total_lido + len(b)
   print('... lidos ',len(b),'bytes (total='+str(total_lido//1024)+' kb)')



