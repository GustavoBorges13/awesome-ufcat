# Laboratório: DNS

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


## Tarefas

Para as tarefas deste laboratório, utilize os seguintes endereços de domínio: 

| Identificador | Endereço                               |
+---------------+----------------------------------------+
| 1             | `ufcat.edu.br`                         |
| 2             | `gov.br`                               |
| 3             | `www.uol.com.br`                       |
| 4             | `www.uol.com`                          |
| 5             | `nytimes.com`                          |
| 6             | `www.youtube.com`                      |
| 7             | `i.ytimg.com`                          |
| 8             | `rr4---sn-jucj-0qps.googlevideo.com`   |


1. Qual é o endereço IP do servidor de DNS que a sua estação (onde esses experimentos estão sendo realizados) utiliza? Informe o endereço efetivo do servidor responsável pela resolução?

nameserver 127.0.0.53

2. Como o servidor de DNS é/foi atribuído à sua estação?

Ele foi atribuído pelo DHCP (Protocolo de Configuração Dinâmica de Host).

3. Para os domínios ou endereços indicados, faça os seguintes tipos de consulta DNS
   * ``A``
- Consulta A para endereço ufcat.edu.br:
a)Comando dig: dig ufcat.edu.br A


b) A resposta retorna os registros de endereço (IPv4) associados ao domínio "ufcat.edu.br", que são 172.67.138.245 e 104.21.48.246.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> ufcat.edu.br A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 43143
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;ufcat.edu.br.                  IN      A

;; ANSWER SECTION:
ufcat.edu.br.           299     IN      A       172.67.138.245
ufcat.edu.br.           299     IN      A       104.21.48.246

;; Query time: 42 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:06 -03 2023
;; MSG SIZE  rcvd: 77



- Consulta A para endereço gov.br:
a) Comando dig: dig gov.br A


b) A resposta retorna o registro de endereço (IPv4) associado ao domínio "gov.br", que é 161.148.164.31.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> gov.br A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 61711
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;gov.br.                        IN      A

;; ANSWER SECTION:
gov.br.                 59      IN      A       161.148.164.31

;; Query time: 39 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:06 -03 2023
;; MSG SIZE  rcvd: 54


- Consulta A para endereço www.uol.com.br:
Consulta A para endereço www.uol.com.br:

a) Comando dig: dig www.uol.com.br A


b)A resposta retorna os registros de endereço (IPv4) associados ao domínio "www.uol.com.br", que são dftex7xfha8fh.cloudfront.net, 108.158.122.115, 108.158.122.46, 108.158.122.120, 108.158.122.45.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com.br A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 5212
;; flags: qr rd ra; QUERY: 1, ANSWER: 5, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.br.                IN      A

;; ANSWER SECTION:
www.uol.com.br.         60      IN      A       dftex7xfha8fh.cloudfront.net.
www.uol.com.br.         60      IN      A       108.158.122.115
www.uol.com.br.         60      IN      A       108.158.122.46
www.uol.com.br.         60      IN      A       108.158.122.120
www.uol.com.br.         60      IN      A       108.158.122.45

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:07 -03 2023
;; MSG SIZE  rcvd: 161


Consulta A para endereço www.uol.com:
a)Comando dig: dig www.uol.com A


b) A resposta retorna o registro de endereço (IPv4) associado ao domínio "www.uol.com", que é amazonas.uol.com.br, com o endereço IP 200.147.35.224.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 5212
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.                   IN      A

;; ANSWER SECTION:
www.uol.com.            60      IN      A       amazonas.uol.com.br.

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:07 -03 2023
;; MSG SIZE  rcvd: 70


Consulta A para endereço nytimes.com:
a) Comando dig: dig nytimes.com A

b) A resposta retorna os registros de endereço (IPv4) associados ao domínio "nytimes.com", que são 151.101.65.164, 151.101.1.164, 151.101.193.164, e 151.101.129.164.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> nytimes.com A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 58774
;; flags: qr rd ra; QUERY: 1, ANSWER: 4, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;nytimes.com.                   IN      A

;; ANSWER SECTION:
nytimes.com.            29      IN      A       151.101.65.164
nytimes.com.            29      IN      A       151.101.1.164
nytimes.com.            29      IN      A       151.101.193.164
nytimes.com.            29      IN      A       151.101.129.164

;; Query time: 4 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 04:07:11 -03 2023
;; MSG SIZE  rcvd: 102

Consulta A para endereço www.youtube.com:
a) Comando dig: dig www.youtube.com A

b) A resposta retorna os registros de endereço (IPv4) associados ao domínio "www.youtube.com", que são youtube-ui.l.google.com, 172.217.162.110, 142.251.128.142, 172.217.29.14, 172.217.30.174, 142.250.219.14, 142.250.219.142, 142.250.218.238, 172.217.28.14, 142.251.129.174, 142.251.129.110, 142.251.129.142, 142.251.129.46, 142.250.218.206, 142.250.219.46, 172.217.28.238, 142.251.129.206.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.youtube.com A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 11023
;; flags: qr rd ra; QUERY: 1, ANSWER: 16, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.youtube.com.               IN      A

;; ANSWER SECTION:
www.youtube.com.        300     IN      A       youtube-ui.l.google.com.
www.youtube.com.        300     IN      A       172.217.162.110
www.youtube.com.        300     IN      A       142.251.128.142
www.youtube.com.        300     IN      A       172.217.29.14
www.youtube.com.        300     IN      A       172.217.30.174
www.youtube.com.        300     IN      A       142.250.219.14
www.youtube.com.        300     IN      A       142.250.219.142
www.youtube.com.        300     IN      A       142.250.218.238
www.youtube.com.        300     IN      A       172.217.28.14
www.youtube.com.        300     IN      A       142.251.129.174
www.youtube.com.        300     IN      A       142.251.129.110
www.youtube.com.        300     IN      A       142.251.129.142
www.youtube.com.        300     IN      A       142.251.129.46
www.youtube.com.        300     IN      A       142.250.218.206
www.youtube.com.        300     IN      A       142.250.219.46
www.youtube.com.        300     IN      A       172.217.28.238
www.youtube.com.        300     IN      A       142.251.129.206

;; Query time: 14 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 04:10:38 -03 2023
;; MSG SIZE  rcvd: 452

Consulta A para endereço i.ytimg.com:
a) Comando dig: dig i.ytimg.com A

b) A resposta retorna os registros de endereço (IPv4) associados ao domínio "i.ytimg.com", que são 142.251.129.246, 142.251.132.22, 142.251.132.54, 142.251.132.246, 172.217.173.118, 142.250.79.214, 142.250.218.22, 142.250.218.86, 142.250.218.182, 142.250.219.182, 142.251.128.150, 142.251.129.54, 172.217.28.246, 142.251.129.150, 142.251.129.182, 142.251.129.214.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> i.ytimg.com A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 26235
;; flags: qr rd ra; QUERY: 1, ANSWER: 17, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;i.ytimg.com.                   IN      A

;; ANSWER SECTION:
i.ytimg.com.            35      IN      A       142.251.129.246
i.ytimg.com.            35      IN      A       142.251.132.22
i.ytimg.com.            35      IN      A       142.251.132.54
i.ytimg.com.            35      IN      A       142.251.132.246
i.ytimg.com.            35      IN      A       172.217.173.118
i.ytimg.com.            35      IN      A       142.250.79.214
i.ytimg.com.            35      IN      A       142.250.218.22
i.ytimg.com.            35      IN      A       142.250.218.86
i.ytimg.com.            35      IN      A       142.250.218.182
i.ytimg.com.            35      IN      A       142.250.219.182
i.ytimg.com.            35      IN      A       142.251.128.150
i.ytimg.com.            35      IN      A       142.251.129.54
i.ytimg.com.            35      IN      A       172.217.28.246
i.ytimg.com.            35      IN      A       142.251.129.150
i.ytimg.com.            35      IN      A       142.251.129.182
i.ytimg.com.            35      IN      A       142.251.129.214

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 04:13:15 -03 2023
;; MSG SIZE  rcvd: 484

Consulta A para endereço rr4---sn-jucj-0qps.googlevideo.com:
a) Comando dig: dig rr4---sn-jucj-0qps.googlevideo.com A

b) A resposta retorna o registro de endereço (IPv4) associado ao domínio "rr4---sn-jucj-0qps.googlevideo.com", que é 201.48.53.15.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> rr4---sn-jucj-0qps.googlevideo.com A
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 61607
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;rr4---sn-jucj-0qps.googlevideo.com. IN A

;; ANSWER SECTION:
rr4---sn-jucj-0qps.googlevideo.com. 59 IN A 201.48.53.15

;; Query time: 43 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:07 -03 2023
;; MSG SIZE  rcvd: 90

   
   * ``NS``
- Consulta NS para endereço ufcat.edu.br:
a) Comando dig: dig ufcat.edu.br NS

b) A resposta retorna os servidores de nomes (NS) associados ao domínio "ufcat.edu.br", que são cash.ns.cloudflare.com e gina.ns.cloudflare.com.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> ufcat.edu.br NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 22652
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;ufcat.edu.br.                  IN      NS

;; ANSWER SECTION:
ufcat.edu.br.           299     IN      NS      cash.ns.cloudflare.com.
ufcat.edu.br.           299     IN      NS      gina.ns.cloudflare.com.

;; Query time: 42 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:07 -03 2023
;; MSG SIZE  rcvd: 116

- Consulta NS para endereço gov.br:
a) Comando dig: dig gov.br NS

b) A resposta retorna os servidores de nomes (NS) associados ao domínio "gov.br", que são c.dns.br, b.dns.br, d.dns.br, f.dns.br, e.dns.br, a.dns.br.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> gov.br NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 18466
;; flags: qr rd ra; QUERY: 1, ANSWER: 6, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;gov.br.                        IN      NS

;; ANSWER SECTION:
gov.br.                 3600    IN      NS      c.dns.br.
gov.br.                 3600    IN      NS      b.dns.br.
gov.br.                 3600    IN      NS      d.dns.br.
gov.br.                 3600    IN      NS      f.dns.br.
gov.br.                 3600    IN      NS      e.dns.br.
gov.br.                 3600    IN      NS      a.dns.br.

;; Query time: 39 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 196

- Consulta NS para endereço www.uol.com.br:
a) Comando dig: dig www.uol.com.br NS

b) A resposta retorna os servidores de nomes (NS) associados ao domínio "www.uol.com.br", que são dftex7xfha8fh.cloudfront.net, ns-47.awsdns-05.com, ns-1021.awsdns-63.net, ns-1434.awsdns-51.org, ns-1917.awsdns-47.co.uk.

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com.br NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 25436
;; flags: qr rd ra; QUERY: 1, ANSWER: 5, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.br.                IN      NS

;; ANSWER SECTION:
www.uol.com.br.         60      IN      NS      dftex7xfha8fh.cloudfront.net.
www.uol.com.br.         60      IN      NS      ns-47.awsdns-05.com.
www.uol.com.br.         60      IN      NS      ns-1021.awsdns-63.net.
www.uol.com.br.         60      IN      NS      ns-1434.awsdns-51.org.
www.uol.com.br.         60      IN      NS      ns-1917.awsdns-47.co.uk.

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 194

- Consulta NS para endereço www.uol.com:
a) Comando dig: dig www.uol.com NS

b) A resposta retorna os servidores de nomes (NS) associados ao domínio "www.uol.com", que é amazonas.uol.com.br.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 30674
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.                   IN      NS

;; ANSWER SECTION:
www.uol.com.            60      IN      NS      amazonas.uol.com.br.

;; Query time: 14 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 74

- Consulta NS para endereço nytimes.com:
a) Comando dig: dig nytimes.com NS

b) A resposta retorna os servidores de nomes (NS) associados ao domínio "nytimes.com", que são dns4.p06.nsone.net, dns2.p06.nsone.net, dns3.p06.nsone.net, dns1.p06.nsone.net, ns-635.awsdns-15.net, ns-1652.awsdns-14.co.uk, ns-1328.awsdns-38.org, ns-244.awsdns-30.com.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> nytimes.com NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 36687
;; flags: qr rd ra; QUERY: 1, ANSWER: 8, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;nytimes.com.                   IN      NS

;; ANSWER SECTION:
nytimes.com.            600     IN      NS      dns4.p06.nsone.net.
nytimes.com.            600     IN      NS      dns2.p06.nsone.net.
nytimes.com.            600     IN      NS      dns3.p06.nsone.net.
nytimes.com.            600     IN      NS      dns1.p06.nsone.net.
nytimes.com.            172800  IN      NS      ns-635.awsdns-15.net.
nytimes.com.            172800  IN      NS      ns-1652.awsdns-14.co.uk.
nytimes.com.            172800  IN      NS      ns-1328.awsdns-38.org.
nytimes.com.            172800  IN      NS      ns-244.awsdns-30.com.

;; Query time: 55 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 297

- Consulta NS para endereço www.youtube.com:
a) Comando dig: dig www.youtube.com NS

b) A resposta retorna o servidor de nomes (NS) associado ao domínio "www.youtube.com", que é youtube-ui.l.google.com.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.youtube.com NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 22669
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.youtube.com.               IN      NS

;; ANSWER SECTION:
www.youtube.com.        300     IN      NS      youtube-ui.l.google.com.

;; Query time: 14 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 76

- Consulta NS para endereço i.ytimg.com:
a) Comando dig: dig i.ytimg.com NS

b) A resposta não retorna registros NS para o domínio "i.ytimg.com".

c) Resposta não-autoritativa

d)
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> i.ytimg.com NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 55761
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;i.ytimg.com.                   IN      NS

;; AUTHORITY SECTION:
ytimg.com.             3600    IN      SOA     ns1.google.com. dns-admin.google.com. 394965729 900 900 1800 60

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 117

- Consulta NS para endereço rr4---sn-jucj-0qps.googlevideo.com:
a) Comando dig: dig rr4---sn-jucj-0qps.googlevideo.com NS

b) A resposta não contém registros de servidores de nomes (NS) para o domínio "rr4---sn-jucj-0qps.googlevideo.com".

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> rr4---sn-jucj-0qps.googlevideo.com NS
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 32451
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;rr4---sn-jucj-0qps.googlevideo.com. IN NS

;; Query time: 2 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:07 -03 2023
;; MSG SIZE  rcvd: 69
   
   * ``MX``

- Consulta MX para endereço ufcat.edu.br:
a) Comando dig: dig ufcat.edu.br MX

b) A resposta retorna os registros de servidores de e-mail (MX) associados ao domínio "ufcat.edu.br", que são 1 aspmx.l.google.com, 10 alt3.aspmx.l.google.com, 5 alt1.aspmx.l.google.com e 5 alt2.aspmx.l.google.com.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> ufcat.edu.br MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 50601
;; flags: qr rd ra; QUERY: 1, ANSWER: 4, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;ufcat.edu.br.                  IN      MX

;; ANSWER SECTION:
ufcat.edu.br.           300     IN      MX      1 aspmx.l.google.com.
ufcat.edu.br.           300     IN      MX      10 alt3.aspmx.l.google.com.
ufcat.edu.br.           300     IN      MX      5 alt1.aspmx.l.google.com.
ufcat.edu.br.           300     IN      MX      5 alt2.aspmx.l.google.com.

;; Query time: 46 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 154

- Consulta MX para endereço gov.br:
a) Comando dig: dig gov.br MX

b) A resposta retorna que o domínio "gov.br" não possui registros de servidores de e-mail (MX).

c) Resposta não-autoritativa

d)


; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> gov.br MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 64644
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;gov.br.                        IN      MX

;; AUTHORITY SECTION:
br.                     3600    IN      SOA     a.dns.br. hostmaster.registro.br. 2024019252 1800 900 604800 900

;; Query time: 25 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 120

- Consulta MX para endereço www.uol.com.br:
a) Comando dig: dig www.uol.com.br MX

b) A resposta retorna que o domínio "www.uol.com.br" não possui registros de servidores de e-mail (MX).

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com.br MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 58574
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.br.                IN      MX

;; AUTHORITY SECTION:
com.br.                 3600    IN      SOA     a.dns.br. hostmaster.registro.br. 2024019373 1800 900 604800 900

;; Query time: 28 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 119

- Consulta MX para endereço www.uol.com:
a) Comando dig: dig www.uol.com MX

b) A resposta retorna que o domínio "www.uol.com" não possui registros de servidores de e-mail (MX).

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 6172
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.                   IN      MX

;; AUTHORITY SECTION:
com.                    3600    IN      SOA     a.gtld-servers.net. nstld.verisign-grs.com. 1637230174 1800 900 604800 86400

;; Query time: 21 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 115

- Consulta MX para endereço nytimes.com:
a) Comando dig: dig nytimes.com MX

b) A resposta retorna os registros de servidores de e-mail (MX) associados ao domínio "nytimes.com", que são 10 alt3.aspmx.l.google.com, 10 alt4.aspmx.l.google.com, 1 aspmx.l.google.com, 5 alt1.aspmx.l.google.com e 5 alt2.aspmx.l.google.com.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> nytimes.com MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 20127
;; flags: qr rd ra; QUERY: 1, ANSWER: 5, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;nytimes.com.                   IN      MX

;; ANSWER SECTION:
nytimes.com.            60      IN      MX      10 alt3.aspmx.l.google.com.
nytimes.com.            60      IN      MX      10 alt4.aspmx.l.google.com.
nytimes.com.            60      IN      MX      1 aspmx.l.google.com.
nytimes.com.            60      IN      MX      5 alt1.aspmx.l.google.com.
nytimes.com.            60      IN      MX      5 alt2.aspmx.l.google.com.

;; Query time: 42 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 163


- Consulta MX para endereço www.youtube.com:
a) Comando dig: dig www.youtube.com MX

b) A resposta retorna que o domínio "www.youtube.com" não possui registros de servidores de e-mail (MX).

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.youtube.com MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 44534
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.youtube.com.               IN      MX

;; AUTHORITY SECTION:
com.                    3600    IN      SOA     a.gtld-servers.net. nstld.verisign-grs.com. 1637230174 1800 900 604800 86400

;; Query time: 25 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 119

- Consulta MX para endereço i.ytimg.com:
a) Comando dig: dig i.ytimg.com MX

b) A resposta retorna que o domínio "i.ytimg.com" não possui registros de servidores de e-mail (MX).

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> i.ytimg.com MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NXDOMAIN, id: 3519
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;i.ytimg.com.                   IN      MX

;; AUTHORITY SECTION:
com.                    3600    IN      SOA     a.gtld-servers.net. nstld.verisign-grs.com. 1637230174 1800 900 604800 86400

;; Query time: 4 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:10 -03 2023
;; MSG SIZE  rcvd: 117
   
- Consulta MX para endereço rr4---sn-jucj-0qps.googlevideo.com:
a) Comando dig: dig rr4---sn-jucj-0qps.googlevideo.com MX

b) A resposta não contém registros de servidores de e-mail (MX) para o domínio "rr4---sn-jucj-0qps.googlevideo.com".

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> rr4---sn-jucj-0qps.googlevideo.com MX
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 35813
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;rr4---sn-jucj-0qps.googlevideo.com. IN MX

;; Query time: 2 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 69
  
   * ``TXT``
   
- Consulta TXT para endereço ufcat.edu.br:
a) Comando dig: dig ufcat.edu.br TXT

b) A resposta retorna os registros TXT associados ao domínio "ufcat.edu.br", que incluem informações de SPF (Sender Policy Framework) e verificação de domínio.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> ufcat.edu.br TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 63540
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;ufcat.edu.br.                  IN      TXT

;; ANSWER SECTION:
ufcat.edu.br.           300     IN      TXT     "v=spf1 include:_spf.google.com ~all"
ufcat.edu.br.           300     IN      TXT     "globalsign-domain-verification=--2W6PUGtZWxebJkwClHY4dOii-VbokkMRMdEDSVv"

;; Query time: 38 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:08 -03 2023
;; MSG SIZE  rcvd: 122

- Consulta TXT para endereço gov.br:
a) Comando dig: dig gov.br TXT

b) A resposta retorna o registro TXT associado ao domínio "gov.br", que contém informações de SPF.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> gov.br TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 35227
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;gov.br.                        IN      TXT

;; ANSWER SECTION:
gov.br.                 300     IN      TXT     "v=spf1 -all"

;; Query time: 26 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 52

- Consulta TXT para endereço www.uol.com.br:
a) Comando dig: dig www.uol.com.br TXT

b) A resposta retorna o registro TXT associado ao domínio "www.uol.com.br", que parece conter informações relacionadas à configuração do servidor.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com.br TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 6379
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.br.                IN      TXT

;; ANSWER SECTION:
www.uol.com.br.         60      IN      TXT     "dftex7xfha8fh.cloudfront.net."

;; Query time: 17 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 83

- Consulta TXT para endereço www.uol.com:
a) Comando dig: dig www.uol.com TXT

b) A resposta retorna o registro TXT associado ao domínio "www.uol.com", que indica o servidor "amazonas.uol.com.br".

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.uol.com TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 14574
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.uol.com.                   IN      TXT

;; ANSWER SECTION:
www.uol.com.            60      IN      TXT     "amazonas.uol.com.br."

;; Query time: 16 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:10 -03 2023
;; MSG SIZE  rcvd: 83

- Consulta TXT para endereço nytimes.com:
a) Comando dig: dig nytimes.com TXT

b) A resposta retorna vários registros TXT associados ao domínio "nytimes.com", que incluem verificações de propriedade, segurança e políticas de e-mail.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> nytimes.com TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 64644
;; flags: qr rd ra; QUERY: 1, ANSWER: 11, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;nytimes.com.                   IN      TXT

;; ANSWER SECTION:
nytimes.com.            60      IN      TXT     "google-site-verification=NIqXa_F8IaqdPJhTtexgR0NYbzVLD_-X-uRUvyf4GyQ"
nytimes.com.            60      IN      TXT     "adobe-idp-site-verification=5ce4d99c-af0a-4b76-9217-bd49d3336df0"
nytimes.com.            60      IN      TXT     "onetrust-domain-verification=dee1266d6a984549b43a1bd101957a8f"
nytimes.com.            60      IN      TXT     "miro-verification=ee856857f05022ca58c04ab6f8e4014e564b3d6b"
nytimes.com.            60      IN      TXT     "google-site-verification=ZsySMeZ_SRbJZFu-53ptepytP7h5pxHO0qAg8Z2bKug"
nytimes.com.            60      IN      TXT     "MS=ms22827202"
nytimes.com.            60      IN      TXT     "ZOOM_verify_ClSSgAI2bqqZQA66rT4Z1x"
nytimes.com.            60      IN      TXT     "segment-site-verification=Z6wALFPYli6z0AlPlgjZXpMVRLZ2KiRb"
nytimes.com.            60      IN      TXT     "google-site-verification=ZTCMdpSKM7HwqTvGUf_00Ef008JhOnbzGgCSUGYfsro"
nytimes.com.            60      IN      TXT     "dropbox-domain-verification=4ld3jahx0psi"
nytimes.com.            60      IN      TXT     "klaviyo-site-verification=NsTtn9"

;; Query time: 16 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:10 -03 2023
;; MSG SIZE  rcvd: 483

- Consulta TXT para endereço www.youtube.com:
a) Comando dig: dig www.youtube.com TXT

b) A resposta retorna múltiplos registros TXT associados ao domínio "www.youtube.com". Os registros incluem informações de verificação, como "google-site-verification" e "adobe-idp-site-verification", entre outros.

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.youtube.com TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 29031
;; flags: qr rd ra; QUERY: 1, ANSWER: 15, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.youtube.com.               IN      TXT

;; ANSWER SECTION:
www.youtube.com.        40      IN      TXT     "youtube-ui.l.google.com"
www.youtube.com.        40      IN      TXT     "google-site-verification=NIqXa_F8IaqdPJhTtexgR0NYbzVLD_-X-uRUvyf4GyQ"
www.youtube.com.        40      IN      TXT     "adobe-idp-site-verification=5ce4d99c-af0a-4b76-9217-bd49d3336df0"
www.youtube.com.        40      IN      TXT     "onetrust-domain-verification=dee1266d6a984549b43a1bd101957a8f"
www.youtube.com.        40      IN      TXT     "miro-verification=ee856857f05022ca58c04ab6f8e4014e564b3d6b"
www.youtube.com.        40      IN      TXT     "google-site-verification=ZsySMeZ_SRbJZFu-53ptepytP7h5pxHO0qAg8Z2bKug"
www.youtube.com.        40      IN      TXT     "MS=ms22827202"
www.youtube.com.        40      IN      TXT     "ZOOM_verify_ClSSgAI2bqqZQA66rT4Z1x"
www.youtube.com.        40      IN      TXT     "segment-site-verification=Z6wALFPYli6z0AlPlgjZXpMVRLZ2KiRb"
www.youtube.com.        40      IN      TXT     "google-site-verification=ZTCMdpSKM7HwqTvGUf_00Ef008JhOnbzGgCSUGYfsro"
www.youtube.com.        40      IN      TXT     "dropbox-domain-verification=4ld3jahx0psi"
www.youtube.com.        40      IN      TXT     "klaviyo-site-verification=NsTtn9"
www.youtube.com.        40      IN      TXT     "klaviyo-site-verification=PkxYaQ"
www.youtube.com.        40      IN      TXT     "atlassian-sending-domain-verification=1b4b110f-a2dd-4853-8b13-de36c831aa81"
www.youtube.com.        40      IN      TXT     "MS=A1BFCA84E21B7011CA98DF9DC251CDDF90E0174B"

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:09 -03 2023
;; MSG SIZE  rcvd: 780

- Consulta TXT para endereço i.ytimg.com:
a) Comando dig: dig i.ytimg.com TXT

b) A resposta retorna um registro TXT associado ao domínio "i.ytimg.com", contendo a informação "rr4.sn-jucj-0qps.googlevideo.com".

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> i.ytimg.com TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 44285
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;i.ytimg.com.                   IN      TXT

;; ANSWER SECTION:
i.ytimg.com.            3600    IN      TXT     "rr4.sn-jucj-0qps.googlevideo.com"

;; Query time: 17 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:10 -03 2023
;; MSG SIZE  rcvd: 95

- Consulta TXT para endereço rr4---sn-jucj-0qps.googlevideo.com:
a) Comando dig: dig rr4---sn-jucj-0qps.googlevideo.com TXT

b) A resposta não contém registros TXT para o domínio "rr4---sn-jucj-0qps.googlevideo.com".

c) Resposta não-autoritativa

d)

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> rr4---sn-jucj-0qps.googlevideo.com TXT
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 49302
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;rr4---sn-jucj-0qps.googlevideo.com. IN TXT

;; Query time: 1 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:10 -03 2023
;; MSG SIZE  rcvd: 80	

4. Quais dessas resoluções são autoritativas?
Resposta na 3

5. Refaça as consultas anteriormente, utilizando resolução interativa, **apenas** para a consulta do tipo `A`. 

* dig A ufcat.edu.br +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A ufcat.edu.br +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 19 ms

* dig A gov.br +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A gov.br +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 7 ms

* dig A www.uol.com.br +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A www.uol.com.br +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 4 ms

* dig A www.uol.com +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A www.uol.com +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 4 ms

* dig A nytimes.com +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A nytimes.com +trace
;; global options: +cmd
;; Received 28 bytes from 127.0.0.53#53(127.0.0.53) in 0 ms

* dig A www.youtube.com +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A www.youtube.com +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 7 ms

* dig A i.ytimg.com +trace

; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A i.ytimg.com +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 11 ms

* dig A rr4---sn-jucj-0qps.googlevideo.com +trace


; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> A rr4---sn-jucj-0qps.googlevideo.com +trace
;; global options: +cmd
;; Received 43 bytes from 127.0.0.53#53(127.0.0.53) in 3 ms


6. Considere as resoluções para os endereços 1, 3, 5 e 6. Quais das resoluções utilizam balanceamento de carga baseado em DNS?

O www.uol.com.br e o www.youtube.com mostram múltiplos endereços IP associados, indicando a possibilidade de balanceamento de carga.

7. Provoque uma atualização da ordem dos endereços retornados na resolução do item anterior. Qual foi o comando `dig` utilizado?

dig @8.8.8.8 www.uol.com.br

8. Quais são os servidores responsáveis pelo domínio `.br`? Como você obteve essa informação?
 
Os servidores do domínio '.br' são:
a.dns.br (IP: 200.219.148.10)
a.dns.br (IP: 200.219.154.10)
a.dns.br (IP: 200.192.233.10)
a.dns.br (IP: 200.229.248.10)
a.dns.br (IP: 200.189.41.10)
a.dns.br (IP: 200.219.159.10)

Obtive as informações sobre os servidores responsáveis pelo domínio .br consultando os servidores de nomes autoritativos para o domínio de nível superior (TLD) "br", utilizando o comando ``` dig +nssearch br ```. 



## Resultados

Descreva os resultados obtidos e respostas as questões dos itens da seção **Tarefas**, no formato indicado para 

1. Endereço
2. Como o servidor de DNS é/foi atribuído à sua estação?
3. Informe para cada uma das consultas feitas no item **(3)**: (a) o comando `dig` utilizado, (b) a interpretação da resposta (texto indicado o significado da resposta), (c) se a resposta é autoritativa e (d) a resposta literal obtida. Utilize o modelo abaixo em **todas** as respostas.

   1. Consulta `A` para endereço `teste.teste.com`
      1. Comando `dig`: `dig teste.teste.com`
      2. Interpretação da resposta
      
         *a resposta retorna o endereço XXX que representa ....*
         
      3. Resposta não-autoritativa 
      4. Resposta (sempre em comandos markdown para código)

```
; <<>> DiG 9.18.18-0ubuntu0.22.04.1-Ubuntu <<>> www.com
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 41960
;; flags: qr rd ra; QUERY: 1, ANSWER: 12, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;www.com.                       IN      A

;; ANSWER SECTION:
www.com.                114     IN      A       45.33.30.197

;; Query time: 15 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Fri Dec 15 03:59:06 -03 2023
;; MSG SIZE  rcvd: 228
```

      3. Resposta (sempre em comandos markdown para código)
      
   1. Consulta `A` para endereço `teste.teste.com`      

4. Comandos `dig` para consultas interativas em resposta ao item **(5)**. 
5. Resposta para o item **(6)**
5. Resposta para o item **(7)**
5. Resposta para o item **(8)**



## Feedback do Professor

*Esta seção será escrita pelo professor ao final da avaliação do seu relatório*.

