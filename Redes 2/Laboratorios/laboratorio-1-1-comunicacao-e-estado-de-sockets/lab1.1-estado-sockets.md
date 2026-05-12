# Laboratório 1.1 - Comunicação com Sockets e Estados de Sockets (2021.2)

## Identificação

* Aluno: "COLOQUE O SEU NOME AQUI"

## Formato das respostas

Exceto quando informando explicitamente, todos os resultados devem ser formatados usando a formatação de código no Markdown, conforme já feito no laboratório 0.1.

* Documentação do formato de tabelas no Markdown Github: <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables>


## Requisitos mínimos de entrega deste relatório

Conforme indicado no plano da disciplina, para obter nota mínima de 6,0 do relatório será necessário que ele atenda a **todos** os requisitos abaixo indicados:

1. Todas as tarefas na seção "Resultados" devem ser respondidas e devem seguir o formato solicitado.
2. Não deve haver qualquer tipo de cópia deste relatório com o que outro aluno. Os experimentos e o relatório são individuais.
3. O seu relatório deverá ser submetido pelo Github Classroom.

A complementação da nota pela avaliação qualitativa do relatório, considerará as respostas das questões abertas (em texto livre).

A seção **"Feedback"** ao fim deste relatório conterá uma descrição da avaliação do professor.


## Resultados

As indicações **ref. X**, indicam de qual atividade do enunciado do laboratório a tarefa faz referência. 

1. (**ref. 3**) Identifique os endereços IPs das estações a serem utilizadas como cliente e como servidor nos seu experimento.

- IP da máquina cliente: 10.0.0.1
- IP da máquina servidor: 10.0.0.2

2. (**ref. 4.1**) Identifique os pares que formam cada sessão de comunicação TCP.

* 10.0.0.1:47920 - 10.0.0.2:8888

3. (**ref. 4.2**) Identifique os comandos utilizados para obter a informação anterior.

- sudo mn
- xterm h1 h2
- em h2: nc -lk 8888
- em h1: nc 10.0.0.2 8888
- h1 wireshark

4. (**ref. 4.4**) Indique a ordem dos estados das conexões no cliente e no servidor, na forma de uma tabela em que cliente e servidor são as colunas e cada linha indica o respectivo estado na conexão em certo instante. Observe que, se o estado de um dos lados não modificar, você pode simplesmente informar **`-`** (como no exemplo abaixo) ou repetir o estado da linha anterior. Você deverá utilizar o [formato de tabelas do Markdown Github](https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables).

| Cliente         | Servidor        |
| --------------- | --------------- |
| Nada        | Nada        |
| Established        | Nada |
| Established        | Established  |
|    Time_wait | Nada |
| Nada        | Nada        |




5. (**ref. 4.5**) Indique **todos** os pacotes TCP enviados pelo cliente conforme exibido pelo Wireshark/tshark, desde o início até o fim da conexão.  Inicie cada linha com um número para a mensagem (1, 2, 3 ...) . *Coloque no formato textual de código Markdown*

* "1","0.000000000","10.0.0.1","10.0.0.2","TCP","74","47920 → 8888 [SYN] Seq=0 Win=29200 Len=0 MSS=1460 SACK_PERM=1 TSval=261356 TSecr=0 WS=512"

* "3","0.000469871","10.0.0.1","10.0.0.2","TCP","66","47920 → 8888 [ACK] Seq=1 Ack=1 Win=29696 Len=0 TSval=261356 TSecr=261356"

* "8","10.088309314","10.0.0.1","10.0.0.2","TCP","73","47920 → 8888 [PSH, ACK] Seq=1 Ack=1 Win=29696 Len=7 TSval=263878 TSecr=261356"

* "11","15.465228029","10.0.0.1","10.0.0.2","TCP","66","47920 → 8888 [ACK] Seq=8 Ack=12 Win=29696 Len=0 TSval=265223 TSecr=265223"

* "12","22.335126760","10.0.0.1","10.0.0.2","TCP","78","47920 → 8888 [PSH, ACK] Seq=8 Ack=12 Win=29696 Len=12 TSval=266940 TSecr=265223"

* "15","33.084656732","10.0.0.1","10.0.0.2","TCP","66","47920 → 8888 [ACK] Seq=20 Ack=25 Win=29696 Len=0 TSval=269627 TSecr=269627"

* "16","36.764045539","10.0.0.1","10.0.0.2","TCP","66","47920 → 8888 [FIN, ACK] Seq=20 Ack=25 Win=29696 Len=0 TSval=270547 TSecr=269627"

* "18","36.764433334","10.0.0.1","10.0.0.2","TCP","66","47920 → 8888 [ACK] Seq=21 Ack=26 Win=29696 Len=0 TSval=270548 TSecr=270548"


6. (**ref. 4.6**) Indique os pacotes TCP trocados pela outra conexão (servidor), conforme indicado pelo Wireshark/tshark. Inicie cada linha com um número para a mensagem (1, 2, 3 ...) . *Coloque no formato textual de código Markdown*

* "2","0.000463500","10.0.0.2","10.0.0.1","TCP","74","8888 → 47920 [SYN, ACK] Seq=0 Ack=1 Win=28960 Len=0 MSS=1460 SACK_PERM=1 TSval=261356 TSecr=261356 WS=512"

* "9","10.088585652","10.0.0.2","10.0.0.1","TCP","66","8888 → 47920 [ACK] Seq=1 Ack=8 Win=29184 Len=0 TSval=263878 TSecr=263878"

* "10","15.465212230","10.0.0.2","10.0.0.1","TCP","77","8888 → 47920 [PSH, ACK] Seq=1 Ack=8 Win=29184 Len=11 TSval=265223 TSecr=263878"

* "13","22.335163780","10.0.0.2","10.0.0.1","TCP","66","8888 → 47920 [ACK] Seq=12 Ack=20 Win=29184 Len=0 TSval=266940 TSecr=266940"

* "14","33.084635352","10.0.0.2","10.0.0.1","TCP","79","8888 → 47920 [PSH, ACK] Seq=12 Ack=20 Win=29184 Len=13 TSval=269627 TSecr=266940"

* "17","36.764421743","10.0.0.2","10.0.0.1","TCP","66","8888 → 47920 [FIN, ACK] Seq=25 Ack=21 Win=29184 Len=0 TSval=270548 TSecr=270547"

7. Construa uma tabela descrevendo o significado/objetivo de cada mensagem dos itens anteriores. A sua tabela deve ter três colunas: **Número da mensagem**, **Cliente ou servidor** e **Descrição**. Use o formato de tabela indicado anteriormente.

| Número da Mensagem | Cliente ou Servidor | Descrição                                                                       |
|--------------------|---------------------|-----------------------------------------------------------------------------------|
| 1                  | Cliente             | Cliente inicia uma conexão com o servidor usando um pacote SYN.                   |
| 2                  | Servidor            | Servidor responde ao cliente com um pacote SYN, ACK confirmando a conexão.         |
| 3                  | Cliente             | Cliente confirma o pacote SYN, ACK do servidor com um pacote ACK.                   |
| 8                  | Cliente             | Cliente envia dados (Payload) para o servidor junto com um pacote PSH, ACK.        |
| 9                  | Servidor            | Servidor confirma a recepção dos dados do cliente com um pacote ACK.               |
| 10                 | Servidor            | Servidor envia dados (Payload) de resposta para o cliente com um pacote PSH, ACK.  |
| 11                 | Cliente             | Cliente confirma a recepção dos dados do servidor com um pacote ACK.               |
| 12                 | Cliente             | Cliente envia mais dados (Payload) para o servidor junto com um pacote PSH, ACK.   |
| 13                 | Servidor            | Servidor confirma a recepção dos dados adicionais do cliente com um pacote ACK.    |
| 14                 | Servidor            | Servidor envia mais dados (Payload) de resposta para o cliente com um pacote PSH, ACK. |
| 15                 | Cliente             | Cliente confirma a recepção dos dados adicionais do servidor com um pacote ACK.    |
| 16                 | Cliente             | Cliente solicita o encerramento da conexão enviando um pacote FIN, ACK para o servidor. |
| 17                 | Servidor            | Servidor confirma o pedido de encerramento da conexão com um pacote FIN, ACK.       |
| 18                 | Cliente             | Cliente confirma o encerramento da conexão com um pacote ACK.                       |


8. (**ref. 4.8**) Quais as diferenças nos pacotes enviados pelo cliente e servidor? (texto livre)

Quando o cliente deseja estabelecer uma conexão com o servidor, ele envia um pacote SYN indicando seu desejo de se conectar. Esse pacote é como um aperto de mão virtual, sinalizando a vontade do cliente de iniciar a comunicação. Em resposta, o servidor envia um pacote SYN, ACK confirmando a solicitação do cliente e indicando sua própria disposição para se conectar. É como se o servidor respondesse ao aperto de mão do cliente, aceitando a conexão.

Após o estabelecimento da conexão, o cliente envia pacotes contendo dados (denominados pacotes PSH, ACK), solicitando que o servidor os processe. O servidor, por sua vez, confirma a recepção desses dados enviando pacotes ACK de volta ao cliente. Esta troca contínua de pacotes de dados e confirmação assegura que a informação seja transmitida de forma confiável entre as partes.

Quando a comunicação é concluída, seja porque todas as informações foram trocadas ou porque o cliente ou o servidor decidiram encerrar a conexão, são enviados pacotes FIN (Finish) e ACK. Primeiro, uma das partes envia um pacote FIN indicando seu desejo de encerrar a conexão. A outra parte responde com um pacote FIN, ACK confirmando o pedido de encerramento. Por fim, a parte inicial envia um pacote ACK para confirmar o recebimento do pedido de encerramento. Esse processo garante um encerramento ordenado e adequado da comunicação entre o cliente e o servidor.

9. (**ref. 5.1**) (UDP) Identifique os pares que formam cada sessão de comunicação TCP.

- 10.0.0.1:49650  -  10.0.0.2:8888.

10. (**ref. 5.2**) (UDP) Identifique os comandos utilizados para obter a informação anterior.

- sudo mn
- xterm h1 h2
- em h2: nc -ul 8888
- em h1: nc -u 10.0.0.2 8888
- h1 netstat -u

11. (**ref. 5.4**) (UDP) Indique a ordem dos estados das conexões.

| Cliente         | Servidor        |
| --------------- | --------------- |
| Nada        | Nada        |
| Established        | Nada |
| Established        | Established  |
|    Nada | Nada |


12. (**ref. 5.5**) (UDP) Indique os pacotes UDP trocados conforme indicado pelo Wireshark/tshark.

- "1","0.000000000","10.0.0.1","10.0.0.2","UDP","45","55354 → 8888 Len=3"
- "7","15.006351371","10.0.0.1","10.0.0.2","UDP","52","55354 → 8888 Len=10"

13. (**ref. 5.6**) (UDP) Indique os pacotes UDP trocados pela outra conexão, conforme indicado pelo Wireshark/tshark.

- "4","7.891348060","10.0.0.2","10.0.0.1","UDP","50","8888 → 55354 Len=8"

14. (**ref. 5.8**) (UDP) Quais as diferenças nas trocas de pacotes quando se trata de uma conexão TCP e uma conversa UDP? (texto livre)

No contexto das trocas de pacotes entre TCP e UDP, o processo de estabelecimento de conexão e confirmação de recebimento desempenha um papel fundamental. No TCP, uma conexão é meticulosamente estabelecida por meio de um intricado processo de três vias entre o cliente e o servidor. Esse protocolo de handshake assegura que ambas as partes estejam prontas e dispostas a iniciar a transmissão de dados, garantindo uma troca de informações confiável e ordenada. Além disso, após enviar dados, o remetente aguarda uma confirmação de recebimento (ACK) do destinatário. Se essa confirmação não é recebida dentro de um tempo especificado, o remetente retransmite os dados para garantir a integridade da transmissão. Em contraste, o UDP adota uma abordagem mais simples e direta. Não há nenhum processo de handshake de conexão; os pacotes UDP são enviados sem qualquer procedimento prévio de estabelecimento de conexão. Além disso, o UDP não oferece confirmação de recebimento. Os pacotes são enviados para o destinatário, mas não há garantia de que serão entregues ou recebidos na ordem correta.

15. Por que o TCP estabelece precisamente diversos estados em uma conexão, enquanto que isso não ocorre com o UDP? (texto livre)

O TCP estabelece diversos estados em uma conexão devido à sua natureza orientada à conexão e seu objetivo principal de proporcionar uma comunicação confiável. Essa precisão nos estados da conexão TCP é necessária para garantir a integridade dos dados transmitidos.O processo de estabelecimento de conexão, conhecido como handshake de três vias, é projetado para assegurar que ambos os extremos da comunicação estejam cientes da intenção de iniciar a troca de dados. Cada estado em uma conexão TCP, desde o estabelecimento até o término, é crucial para manter a comunicação robusta.Por outro lado, o UDP não estabelece esses estados precisos porque adota uma abordagem mais simples. O UDP é uma comunicação não orientada à conexão, o que significa que ele não impõe o mesmo processo rigoroso de estabelecimento e manutenção de uma conexão. Em vez disso, ele permite que os dados sejam enviados sem a necessidade de uma confirmação de recebimento formal. Essa simplicidade auxilia em cenários onde a latência mínima é mais crítica do que a garantia absoluta da entrega dos dados, como em transmissões de vídeo ao vivo ou jogos online em tempo real. Portanto, a falta de estados precisos em uma conexão UDP permite uma comunicação mais rápida e eficiente, embora às custas da garantia da ordem e integridade dos dados transmitidos.

16. Quais são os estados de uma conexão TCP e qual é o significado de cada uma delas? (texto livre)
- **Em ordem: **

* Estado CLOSED (Fechado): Neste estado, a conexão TCP não está estabelecida. É o estado inicial antes do início do processo de estabelecimento de conexão.

* Estado LISTEN (Escuta): Quando um servidor TCP está esperando por uma solicitação de conexão, ele entra no estado de escuta. Ele aguarda ativamente por pedidos de conexão de clientes.

* Estado SYN-SENT (Sincronização Enviada): Após enviar uma solicitação de conexão (SYN) para o servidor, o cliente entra neste estado. Ele está aguardando a confirmação do servidor para estabelecer a conexão.

* Estado SYN-RECEIVED (Sincronização Recebida): Quando o servidor recebe uma solicitação de conexão (SYN) e responde com sua própria solicitação de sincronização (SYN), ele entra neste estado. Ele está esperando a confirmação do cliente para estabelecer a conexão.

* Estado ESTABLISHED (Estabelecida): A conexão foi estabelecida com sucesso. Os dispositivos podem agora trocar dados de forma confiável. É o estado onde a transmissão e a recepção de dados ocorrem normalmente.

* Estado FIN-WAIT-1 (Aguardando o Primeiro Segmento FIN): Este estado ocorre quando um dispositivo local (cliente ou servidor) decidiu encerrar a conexão e enviou um segmento FIN, indicando que não enviará mais dados.

* Estado FIN-WAIT-2 (Aguardando o Segundo Segmento FIN): O dispositivo local ainda pode receber dados do outro lado, mas não pode mais enviar dados. Ele está aguardando o segmento FIN do outro lado para confirmar o encerramento total da conexão.

* Estado CLOSE-WAIT (Aguardando o Segmento FIN do Cliente): O servidor está aguardando o segmento FIN do cliente. Isso ocorre após o cliente ter enviado um segmento FIN indicando que não enviará mais dados.

* Estado LAST-ACK (Aguardando Confirmação do Segundo Segmento FIN): O dispositivo local (cliente ou servidor) enviou o segmento FIN em resposta ao segmento FIN do outro lado. Ele está aguardando a confirmação do recebimento do segundo segmento FIN.

* Estado TIME-WAIT (Aguardando o Tempo de Espera): Após enviar o último segmento FIN e receber a confirmação do outro lado, o dispositivo entra neste estado por um período de tempo. Isso garante que todos os segmentos relacionados ao encerramento da conexão sejam descartados antes de a conexão ser considerada totalmente encerrada.

* Closed novamente.

17. Se há mais de uma conexão TCP estabelecida para um mesmo servidor, de que maneira o TCP diferencia uma conexão de outra? (texto livre)

Comunicações TCP combinação única de endereços IP e números de porta de origem e destino permite que o TCP diferencie várias conexões que estão sendo feitas para o mesmo servidor. Cada conexão terá uma tupla (combinação de IP's e portas) de conexão única, garantindo que os dados sejam entregues à aplicação correta no servidor, mesmo quando várias conexões estão ativas simultaneamente.

18. Provoque o seguinte problema de conversa entre sockets TCP: **O cliente tenta se conectar um servidor que não existe**. Indique os pacotes TCP enviados pelo cliente, conforme recuperados pelo Wireshark.

- "3","0.001090436","10.0.0.1","10.0.0.2","TCP","74","52080 → 8888 [SYN] Seq=0 Win=29200 Len=0 MSS=1460 SACK_PERM=1 TSval=973452 TSecr=0 WS=512"
- "4","0.001601924","10.0.0.2","10.0.0.1","TCP","54","8888 → 52080 [RST, ACK] Seq=1 Ack=1 Win=0 Len=0"

19. Explique o comportamento do TCP no caso anterior (texto livre).

O servidor que o cliente está tentando alcançar não existe ou não está ativo na porta especificada (8888). Portanto, não há resposta positiva para o segmento SYN do cliente. Em resposta ao segmento SYN, o sistema na rede (10.0.0.2) envia um segmento TCP com a flag RST ativada, indicando ao cliente que a conexão não foi estabelecida e foi rejeitada. O flag ACK é ativado para confirmar a recepção do segmento SYN, mas o servidor inexistente não aceita a conexão e, assim, termina abruptamente a tentativa de estabelecer a comunicação.

20. Provoque o seguinte problema de conversa entre sockets TCP: **Com uma conexão estabelecida entre um cliente e o servidor, um dos lados parar de se comunicar**. Para simular isso, termine o processo **servidor** do netcat com a combinação **ctrl-C**. É **importante** que seja o servidor, porque no cliente netcat o efeito não será de interrupção abrupta na conexão. Indique os pacotes TCP enviados pelo cliente, conforme recuperados pelo Wireshark.

- Pacotes do three-way-handshake
- "5","4.050076788","10.0.0.1","10.0.0.2","TCP","66","52106 → 8888 [FIN, ACK] Seq=1 Ack=2 Win=29696 Len=0 TSval=1144699 TSecr=1144699"


21. Explique o comportamento do TCP no caso anterior (texto livre).

- O cliente enviou um segmento FIN para iniciar o processo de encerramento da conexão. O servidor recebeu o segmento FIN, confirmou o recebimento enviando um segmento ACK de volta ao cliente. No entanto, como o servidor foi encerrado abruptamente, então não houve mais comunicação após este ponto.

## Feedback do Professor

*Esta seção será escrita pelo professor ao final da avaliação do seu relatório*.

