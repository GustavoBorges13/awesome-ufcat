# Laboratório 1.3: Programação com Sockets TCP e UDP com Python

## Identificação

* Aluno: "COLOQUE O SEU NOME AQUI"

## Formato das respostas

Exceto quando informando explicitamente, todos os resultados devem ser formatados usando a formatação de código no Markdown, conforme já feito nos laboratórios anteriores. Respostas em texto livre devem ser escritas em **texto normal**, sem formatação.

* Documentação do formato de tabelas no Markdown Github: <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables>

Todo o código produzido deve ser colocado no diretório `python`. Dentro desse diretório, você poderá utilizar a organização que preferir.


## Requisitos mínimos de entrega deste relatório

Conforme indicado no plano da disciplina, para obter nota mínima de 6,0 do relatório será necessário que ele atenda a **todos** os requisitos abaixo indicados:

1. Todas as tarefas na seção "Resultados" devem ser respondidas e devem seguir o formato solicitado.
2. Não deve haver qualquer tipo de cópia deste relatório ou do código produzido com o de outro aluno, **independentemente do semestre**. Os experimentos e o relatório são individuais.
3. O seu relatório deverá ser submetido pelo Github Classroom.

A complementação da nota pela avaliação qualitativa do relatório, considerará as respostas das questões abertas (em texto livre) e **sobretudo** o código produzido.

A seção [**"Feedback"**](#Feedback) ao fim deste relatório conterá uma descrição da avaliação do professor.


## Resultados

### Parte A

O seu código deverá ser colocado no diretório `python/cliente`, caso tenha implementado em Python. Não esqueça de documentar o uso do seu programa no arquivo (`README.md`)[README.md].

1. (**ref. A.4.1 a 4**) Descreva os erros/problemas que ocorrem na execução do seu cliente, caso o servidor não tenha o comportamento esperado descrito nos cenários. Em cada uma das respostas você deverá indicar: (i) o problema percebido no cliente em termos de estado do socket (entre os estados possíveis de um socket); (ii) como o seu programa (seu código) percebe o problema e qual exceção é gerada pela biblioteca de sockets; (iii) o comportamento você implementou no seu código para reagir a esse problema (exemplo: *"escreve uma mensagem de erro e termina o programa"*).

   * Problema **E1**
"TimeoutError: [WinError 10060], significa que uma tentativa de conexão falhou,  ocorre quando o cliente tenta se conectar a um endereço IP inexistente ou inacessível. Isso é esperado, pois o teste envolve a comunicação com um host que não está disponível.

   * Problema **E2**
ConnectionRefusedError: [WinError 10061], significa que nenhuma conexão pôde ser feita, ocorre quando o cliente tenta se conectar a uma porta não utilizada ou diferente daquela utilizada pelo servidor. Isso é o esperado, pois foi simulado uma tentativa de conexão com uma porta não utilizada.
   
   * Problema **E3**
   
Erro: [WinError 10054] Foi forçado o cancelamento de uma conexão existente pelo host remoto, este erro ocorre quando o servidor é derrubado durante a conversa. Introduzir atrasos no servidor é uma maneira válida de simular esse comportamento. O cliente detecta que a conexão foi fechada abruptamente pelo servidor.
   
   * Problema **E4**
	
Erro: [WinError 10053] Uma conexão estabelecida foi anulada pelo software no computador host, este erro ocorre quando o servidor é derrubado após o envio de dados pelo cliente, mas antes que o cliente possa ler a resposta. Ocorreu como esperado, pois o cliente detecta que a conexão foi encerrada antes que pudesse concluir a leitura.
### Parte B

O seu código deverá ser colocado no diretório `python/servidor`, caso tenha implementado em Python.

>>> import socket
>>> socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
>>> socket.bind(('', 7770))
>>> socket.listen(1)
>>> conexao, endereco = socket.accept()
>>> endereco
('127.0.0.1', 39112)
>>> conexao
<socket.socket fd=4, family=AddressFamily.AF_INET, type=SocketKind.SOCK_STREAM, proto=0, laddr=('127.0.0.1', 7770), raddr=('127.0.0.1', 39112)>
>>> dados = conexao.recv(512)
>>> dados

1. (**ref. B.3**) Descreva os tratamento de erros e problemas feitos no código servidor e comente eventuais diferentes entre o feito no cliente. **Observe que** em caso de problemas na comunicação com o cliente, e possível término, o servidor deverá continuar executando e poder aceitar conexões de novos clientes (sempre um cliente por vez).

<p id="meucast" />

No código do servidor, implementamos tratamentos de erros específicos para lidar com situações adversas durante a execução. Utilizamos blocos try e except para capturar exceções do tipo OSError, o que nos permite gerenciar problemas de comunicação, como falhas na conexão, desconexões inesperadas ou encerramento do cliente.

Dentro do bloco try, há uma rotina para processar os dados recebidos do cliente. Caso ocorra um erro do tipo BrokenPipeError (indicando que a conexão foi encerrada pelo cliente), exibimos a mensagem "Servidor foi encerrado" e fechamos a conexão com o cliente. Importante ressaltar que, mesmo após esse evento, o servidor continua em execução, aguardando novas conexões.

Se ocorrer qualquer outra exceção do tipo OSError, exibimos a mensagem "Ocorreu um erro" e fechamos a conexão com o cliente. Novamente, o servidor permanece em execução, pronto para aceitar novas conexões.

A principal diferença em relação ao código do cliente está na capacidade do servidor de lidar com desconexões do cliente de maneira robusta, sem interromper sua execução geral mantendo sua disponibilidade para aceitar novas conexões, mesmo após problemas de comunicação com clientes anteriores.


### Parte C: meucast

Nesta atividade você deverá desenvolver um cliente e servidor, chamados de **`meucast`**, que simularão um protocolo de execução de mídia, misturando características do protocolo do Chromecast com do RTP/RTCP.

Todo o seu código deverá ficar no diretório `python/meucast` (nos respectivos diretórios `cliente` e `servidor`), ou 

O protocolo é bastante simples e por ele, um cliente deverá ser capaz de:

1. Encontrar um dispositivo (servidor) na sua rede local, disponível para responder aos comandos remotos (**DESCOBERTA**).
2. Solicitar a execução dos comandos remotos no servidor que deverá (**EXECUÇÃO**):

   * Abrir um arquivo local textual indicado pelo cliente
   * Exibir uma a uma as linhas do arquivo local, com um intervalo de tempo pré-estabelecido
   * Interromper e continuar a exibição das linhas
   * Pular para frente e para trás as linhas a serem exibidas.
   * Parar a exibição das linhas.
 
As funcionalidades indicadas em (2) simulam a manipulação de uma midia (audio ou video) em um servidor executor de midia. Nosso "executor de midia", entretanto, apenas mostra o conteúdo de um arquivo de texto, linha a linha.
 
Separaremos o protocolo em duas partes: DESCOBERTA e EXECUÇÃO, de acordo com as funcionalidades indicadas acima. No restante desta descrição, chamaremos o servidor simplesmente pelo nome TPLAY.

#### Protocolos de DESCOBERTA

O protocolo de DESCOBERTA é um protocolo pelo qual um cliente descobre se existe um servidor (uma instância de TPLAY) para execução na sua rede local em qual local (endereço IP e porta) este servidor (TPLAY) está. O TPLAY criará um socket servidor UDP esperando na porta **`11111`**. Essa porta **não** pode ser modificada.

Um cliente desejando encontrar um TPLAY na rede local, enviará uma mensagem UDP para todas as estações da rede local na porta indicada. Para isso, o cliente deverá enviar uma mensagem para o endereço de broadcast da rede (`255.255.255.255`), a qual será respondida apenas pelo TPLAY, indicando o endereço IP e a porta em que o TPLAY está esperando o recebimento de comandos de execução.

Todas as mensagens serão textuais, terminadas pelo caracter de nova linha (`\n`). No exemplo abaixo, consideramos que o TPLAY está disponível no IP `10.0.0.30` na porta `11112`. **Observe** que esse endereço e porta é aquele onde se encontra o servidor TCP responsável pela execução e descrito na seção seguinte.

| Cliente    | TPLAY                   | Significado                                                          |
| ---------- | ----------------------- | -------------------------------------------------------------------- |
| `SEARCH`   | -                       | Enviada para endereço de broacast da rede para procurar por um TPLAY |
| -          | `TPLAY 10.0.0.30 11112` | TPLAY responde a mensagem anterior com seu servidor TCP de execução  |


#### Protocolo de EXECUÇÃO

O protocolo de EXECUÇÃO determina como o TPLAY irá receber comandos de um cliente, uma vez que um cliente descobriu um servidor pelo protocolo discutido a seção anterior.

O protocolo de EXECUÇÃO utilizará TCP, então a sua implementação do TPLAY deverá ter um socket servidor adicional apenas para responder comandos de um cliente.

O "identificador de tmidia" é um nome que indica o nome do arquivo a ser reproduzido. Considere que o TPLAY procurará os arquivos dentro do diretório `tmidia/` da sua execução, onde eu já colocarei alguns arquivos de teste para auxiliar. Inicialmente, coloquei um arquivo `1.txt` (considere `1.txt` o nome dessa midia).

| Cliente      | TPLAY        | Significado                                                                                   |
| ------------ | ------------ | --------------------------------------------------------------------------------------------- |
| `PLAY midia` |              | TPLAY inicia a exibição das linhas do arquivo textual `midia`                                 |
| `PAUS`       |              | PAUSA: interrompe ou continua a exibição das linhas do arquivo textual                        |
| `STOP`       |              | para a exibição do arquivo, fazendo com que só `PLAY` tenha algum efeito                      |
| `BACK `      |              | retrocede a exibição do arquivo em 1 linha (pode estar em execução ou pausa)                  |
| `BACK 10`    |              | retrocede a exibição no número indicado (no exemplo 10 linhas)                                |
| `FORW `      |              | adianta a exibição do arquivo em 1 linha (pode estar em execução ou pausa)                    |
| `FORW 10`    |              | adianta a exibição no número indicado (no exemplo 10 linhas)                                  |
|              | `OK`         | indica para o cliente que o comando anterior foi executado com sucesso                        |
|              | `NOK erro`   | indica para o cliente erro no comando anterior, indicando um texto (`erro`) com causa do erro |

Uma mensagem `NOK` pode ser enviada em situações como:

* `PLAY` para arquivo que não existe
* `PAUS` sem que haja arquivo em exibição.

#### Funcionamento do TPLAY

Você **deve** adicionar um atraso na exibição de uma linha para outra. Eu sugiro colocar 0.1 segundos nos seus testes, e definir esse tempo em uma constante no inicio do programa. 

Não é obrigatório, mas eu sugiro colocar uma segunda temporização a ser utilizada a cada 24 linhas: cada vez que o programa exibir linhas múltiplas de 24 utilizar essa temporização adicional. Utilize o próprio número de linhas como um parâmetro definido no início do programa (com valor default de 24). Com isso será possível fazer brincadeiras legais com o seu código.

#### Precauções

Tenha cuidado para não misturar o funcionamento da aplicação, referente à exibição do conteúdo, com a parte que implementa o protocolo. Separe-as o máximo possível. Por exemplo, coloque as funções de exibição em funções que podem ser chamadas de dentro do laço principal do seu programa. Isso facilitará em muito a sua tarefa.

#### Simplificações

* Não se preocupe em fazer o seu protocolo funcionar com dois clientes simultâneos.
* Você pode implementar na linguagem de programação que preferir, desde que:
   1. O seu código satisfaça aos requisitos do protocolo indicado, pois seu servidor deve conversar com o cliente de outro aluno, e vice-versa. O seu servidor deve conversar com um cliente/servidor **nc**.
   2. A sua implementação não pode utilizar nenhuma construção, api ou framework para esconder o uso direto de sockets TCP/UDP.
* Não precisa se preocupar com perda de mensagens no protocolo UDP, por exemplo, quando cliente faz uma pesquisa e não recebe resposta. Não é necessário implementar nenhuma temporização para envio de novas de mensagens de tempo em tempo.
* A sua implementação do TPLAY pode ter dois códigos (arquivos) separados: um para cada protocolo. Isso vai evitar que você se preocupe com o funcionamento simultâneo dos dois protocolos, caso não tenha experiência em uso de threads em Python (ou em outra linguagem).

<p id="estrutura-servidor-sockets-naobloqueantes" />

### Estrutura Servidor e Sockets Não-bloqueantes

Apesar das simplificações indicadas na seção anterior, ainda há algumas preocupações necessárias na implementação do servidor TPLAY. Considerando que o servidor esta exibindo as linhas de um arquivo, no seu laço principal o servidor deveria:

1. Exibir uma linha do arquivo
2. Esperar um intervalo de tempo
3. Ler uma *possível* mensagem da rede
4. Voltar a (1)

Entretanto, ocorre que a leitura de mensagens do socket (primitiva `recv`) bloqueia a chamada até que chegue alguma mensagem. Então, se o cliente não enviasse nenhuma mensagem para o servidor, ele ficaria bloqueado no passo (3) e não continuaria a exibição das linhas do arquivo. Isso não funciona, como você deve imaginar, e é necessário uma chamada não-bloqueante da leitura de sockets. Eu explico como isso funciona no video abaixo.

[![Chamadas não-bloqueantes em sockets com Python](images/youtube-chamada-naobloqueante.png)](https://youtu.be/LAj6RyRC5w4)


Idealmente, um código deveria fazer isso de threads para gerenciar esse controle, mas, conforme mencionado, isso não será exigido nessa atividade. Eu então sugiro que você não tente introduzir threads, pois não é o objetivo desse laboratório e há várias sutilezas/problemas com que seu código teria que lidar.


<p id="Feedback" />

## Feedback do Professor

*Esta seção será escrita pelo professor ao final da avaliação do seu relatório*.
