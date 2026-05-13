
import sys
import socket



def createArrayAsc(size):
   ref = '1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0p;-=[]/|1QAZ2WSX3EDC4RFV5TG'
   arrayChars = bytearray(size)
   for i in range(0,size//len(ref)):
      arrayChars[i*len(ref):] = ref.encode()
   return arrayChars


ARRAY_CHARS_1024 = createArrayAsc(1024)


# Codigo cliente de envio de bytes. substitua as variaveis pelo endereco do
# socket destino
IP = '127.0.0.1'    # IP do destino
PORTA = 8888  # porta do destino

if IP == '' or PORTA == 0:
   print("Porta ou ip de destino indefinido.")
   sys.exit(1)


socket_cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket_cliente.connect((IP, PORTA))

LIMITE_MEM = 104857600

total_transmitidos = 0

while True:
   strBytesEnviar = input('Tamanho em bytes da estrutura: ')
   bytesEnviar = max(1,int(strBytesEnviar)//1024)*1024
   if bytesEnviar > LIMITE_MEM:
      print("Limite superior de 100 Mbytes estourado. Considerando 100 Mbytes")
      bytesEnviar = LIMITE_MEM
   #b = bytearray(bytesEnviar)
   b = createArrayAsc(bytesEnviar)

   print('Escolhido multiplo de 1024: ',bytesEnviar//1024,'kb')
   print('Enviando para ' + IP + ':' + str(PORTA) + '...')
   socket_cliente.sendall(b)
   total_transmitidos = total_transmitidos + len(b)
   print('...ok (total=' + str(total_transmitidos//1024) + ' kb)')



