# Laboratório 1.2: Comunicação com Sockets e Arquitetura do HTTP

## Identificação

* Aluno: "COLOQUE O SEU NOME AQUI"

## Formato das respostas

Exceto quando informando explicitamente, todos os resultados devem ser formatados usando a formatação de código no Markdown, conforme já feito nos laboratórios anteriores. Respostas em texto livre devem ser escritas em **texto normal**, sem formatação.

* Documentação do formato de tabelas no Markdown Github: <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables>


## Requisitos mínimos de entrega deste relatório

Conforme indicado no plano da disciplina, para obter nota mínima de 6,0 do relatório será necessário que ele atenda a **todos** os requisitos abaixo indicados:

1. Todas as tarefas na seção "Resultados" devem ser respondidas e devem seguir o formato solicitado.
2. Não deve haver qualquer tipo de cópia deste relatório com o que outro aluno. Os experimentos e o relatório são individuais.
3. O seu relatório deverá ser submetido pelo Github Classroom.

A complementação da nota pela avaliação qualitativa do relatório, considerará as respostas das questões abertas (em texto livre).

A seção [**"Feedback"**](#Feedback) ao fim deste relatório conterá uma descrição da avaliação do professor.


## Resultados

As indicações **ref. X**, indicam de qual atividade do enunciado do laboratório a tarefa faz referência. 

1. Descreva o cenário para o experimento utilizado para o laboratório, conforme seção "Cenário de Experimentação no Mininet". 
   Descreva o cenário utilizado em termos de largura de banda (vazão) e atrasos. (texto livre)
   Indique o comando mininet utilizado para estabelecer o cenário do ambiente.

Para estimar a latência, foi utilizado o comando ping para enviar pacotes ao site "ufcat.edu.br" e medir o tempo de ida e volta (RTT - Round-Trip Time) para os pacotes enviados. Os resultados do ping indicaram uma latência variável entre 16.6 ms e 23.6 ms. Para estimar a taxa de transmissão, o comando wget foi usado com a opção -p para baixar a página web do site, incluindo todos os elementos referenciados, como imagens. Durante o download, o wget indicou uma taxa de transmissão de aproximadamente 308 KB/s (para 94.49 K enviados).

Foi utilizado o comando "sudo mn --link tc,bw=308,delay=20ms" para configurar a largura de banda para 308 KB/s, para refletir a taxa de transmissão estimada com o site. Além disso, um atraso de 20 ms foi introduzido para simular a latência entre o Mininet e o site.

Dentro do mininet utilizo "xterm h1 h2", crio um servidor em h2 utilizando o Netcat e em h1 dou um ping em h2. O ping entre os sockets possuem uma latencia variável entre 81.0 ms e 82.7 ms. Ao rodar o wget em 10.0.0.2:8888 uma solicitação de conexão hattp é enviada e ao enviar mensagens do servidor, o wget indicou uma taxa de transmissão de 2.7 B/s (para 16 bits enviados).



2. (**ref. 3.1**) Identifique o cabeçalho recebido pelo a uma requisição simples HTTP.

GET / HTTP/1.1
Host: 127.0.0.1:8888
User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:88.0) Gecko/20100101 Firefox/88.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,/;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Connection: keep-alive
Upgrade-Insecure-Requests: 1

3. (**ref. 3.2**) Qual é o valor do cabeçalho `USER-AGENT`?

Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:88.0) Gecko/20100101 Firefox/88.0

4. (**ref. 3.5**) Identifique o cabeçalho HTTP das seguintes respostas:

   * Requisição 1`/1.html`:
   
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.5.2
Date: Thu, 02 Nov 2023 18:55:44 GMT
Content-type: text/html
Content-Length: 170
Last-Modified: Mon, 07 Jun 2021 22:30:40 GMT
   
   * Requisição 2`/1.txt`
   
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.5.2
Date: Thu, 02 Nov 2023 18:58:52 GMT
Content-type: text/plain
Content-Length: 77
Last-Modified: Mon, 07 Jun 2021 22:30:40 GMT
   
   * Requisição 3 `/1.pdf`
   
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.5.2
Date: Thu, 02 Nov 2023 19:00:00 GMT
Content-type: application/pdf
Content-Length: 14630
Last-Modified: Mon, 07 Jun 2021 22:30:40 GMT

   * Requisição 4 `/1.png`
   
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.5.2
Date: Thu, 02 Nov 2023 19:03:42 GMT
Content-type: image/png
Content-Length: 1466
Last-Modified: Mon, 07 Jun 2021 22:30:40 GMT

5. (**ref. 3.6**) Explique o comportamento do browser na ocorrência da troca dos cabeçalhos (o que ocorreu e por que ocorreu). (texto livre)

Ao realizar a troca dos cabeçalhos, enviando solicitações para um recurso específico e recebendo o cabeçalho de outro, observouse que: Quando o browser solicitava um recurso específico, como o HTML em /1.html, mas recebia o cabeçalho de outra resposta, como o /1.txt, o navegador ainda interpretava e exibia o conteúdo como se fosse o recurso originalmente solicitado. Isso ocorreu porque os cabeçalhos HTTP não correspondiam ao corpo da resposta, confundindo o navegador.

Esse comportamento é resultado da forma como os navegadores interpretam os dados recebidos. Eles confiam principalmente nos cabeçalhos HTTP para determinar o tipo de conteúdo e como exibi-lo. Quando os cabeçalhos não coincidem com o corpo da resposta, o navegador continua a interpretar o conteúdo com base nos cabeçalhos fornecidos, levando a uma exibição incorreta dos recursos.

6. (**ref. 3.6**) Explique em detalhes como o browser faz utilização do cache durante o acesso ao conteúdo (em termos de uso de cabeçalhos HTTP **no seu experimento**) e indique a diferença no tempo de carregamento da página obtido no experimento. 

Durante o acesso ao conteúdo no experimento, os cabeçalhos HTTP desempenharam um papel fundamental na interação com o cache do navegador, onde:

- O cabeçalho Cache-Control é utilizado para controlar o comportamento do cache no navegador. Se um recurso possui o cabeçalho Cache-Control com o valor max-age, indica que o recurso pode ser armazenado em cache no navegador por um determinado período de tempo, especificado em segundos. Recursos com um max-age positivo são armazenados no cache do navegador e reutilizados para solicitações subsequentes dentro do período de validade, reduzindo a necessidade de buscar o recurso novamente do servidor.

- O cabeçalho Etag é uma identificação única atribuída a uma versão específica de um recurso no servidor. Quando um navegador solicita um recurso, ele verifica se a versão armazenada em cache possui o mesmo Etag que a versão no servidor. Se os Etags coincidirem, o navegador utiliza a cópia em cache, economizando a transferência de dados desnecessária.

- O cabeçalho Last-Modified informa a data e hora da última modificação do recurso no servidor. Quando o navegador possui uma cópia do recurso em cache, ele pode enviar um cabeçalho If-Modified-Since na próxima solicitação. Se o servidor identificar que o recurso não foi modificado desde a data indicada pelo cabeçalho If-Modified-Since, ele responde com um status 304 Not Modified e o navegador utiliza a versão em cache.

No experimento, a diferença no tempo de carregamento da página ocorre devido à forma como o cache é gerenciado pelos cabeçalhos HTTP. Quando os recursos são armazenados em cache e reutilizados, o navegador economiza tempo e reduz a latência da rede, resultando em tempos de carregamento mais rápidos. Por outro lado, se os recursos não são armazenados em cache ou se o navegador precisa validar a versão em cache com o servidor devido a mudanças, isso pode levar a um aumento no tempo de carregamento, pois o navegador precisa buscar os recursos novamente do servidor.

7. (**ref. 5.1 e 5.6**) Indique os tempos de carregamento da página `fig/grafite.html` obtido nos experimentos com e sem conexões simultâneas. (texto livre)

* 5.1: 4.48 segundos.
* 5.6: 6.05

8. Explique o resultado obtido no experimento anterior. (texto livre)

No experimento anterior, a modificação da propriedade network.http.max-connections para 1 limitou o número de conexões HTTP simultâneas no navegador Firefox para apenas uma. Isso significava que o navegador podia fazer apenas uma solicitação HTTP por vez, em vez de buscar múltiplos recursos simultaneamente. Ao acessar a página fig/grafite.html, que contém diversas imagens, o navegador teve que esperar que cada recurso fosse baixado sequencialmente, um após o outro.Esse comportamento resultou em um aumento significativo no tempo de carregamento da página. Como os recursos não podiam ser buscados simultaneamente, o navegador levou mais tempo para carregar todos os elementos da página. O tempo de carregamento aumentou de 4.48 segundos no experimento com conexões simultâneas para 6.05 segundos no experimento com apenas uma conexão por vez.


## Feedback do Professor

*Esta seção será escrita pelo professor ao final da avaliação do seu relatório*.

