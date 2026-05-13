# Laboratório 3.3: Multimidia: Streaming de Conferência em Tempo Real com WebRTP

## Identificação

* Aluno: "COLOQUE O SEU NOME AQUI"

## Formato das respostas

Exceto quando informando explicitamente, todos os resultados devem ser formatados usando a formatação de código no Markdown, conforme já feito nos laboratórios anteriores. Respostas em texto livre devem ser escritas em **texto normal**, sem formatação.

* Documentação do formato de tabelas no Markdown Github: <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables>


## Requisitos mínimos de entrega deste relatório

Conforme indicado no plano da disciplina, para obter nota mínima de 6,0 do relatório será necessário que ele atenda a **todos** os requisitos abaixo indicados:

1. Todas as tarefas na seção "Resultados" devem ser respondidas e devem seguir o formato solicitado.
2. Não deve haver qualquer tipo de cópia deste relatório ou do código produzido com o de outro aluno, **independentemente do semestre**. Os experimentos e o relatório são individuais.
3. O seu relatório deverá ser submetido pelo Github Classroom.

A complementação da nota pela avaliação qualitativa do relatório, considerará as respostas das questões abertas (em texto livre) e **sobretudo** o código produzido.

A seção [**"Feedback"**](#Feedback) ao fim deste relatório conterá uma descrição da avaliação do professor.


## Objetivos

* Compreender o funcionamento e arquitetura do webRTP para streaming interativo em tempo real
* Verificar o efeito dos atrasos, erros e jitter em multimídia em tempo real, sobretudo as adaptações. 

## Recursos e Referências

+ webRTC
   + <https://webrtc.org/native-code/logging/>
   + <http://stackoverflow.com/questions/17530197/how-to-do-network-tracking-or-debugging-webrtc-peer-to-peer-connection>
   + <https://webrtc.org/architecture/> - Arquitetura
   + <https://hpbn.co/webrtc/> - Funcionamento Detalhado
+ [Depuração do webRTP no Chrome](depuracao-webrtp-chrome.md)
   

## Tarefas 

Neste laboratório executaremos uma aplicação webRTC dentro de um navegador web e verificaremos o desempenho da comunicação e dos protocolos de multimídia, quando em diferentes cenários de atraso, jitter e erros.

Este laboratório deverá utilizar o **Chrome/Chromium** como navegador web, devido ao suporte mais simples à depuração de interações webrtc. No Chrome/Chromium, para abrir uma aba de depuração do webrtc deve-se digitar na aba de endereços: `chrome://webrtc-internals/`.

Afim de facilitar o cenário de experimentação, utilizaremos o **Google Meet** como aplicação baseada em webRTC e acompanharemos o funcionamento.

* [Configuração do ambiente mininet](configuracao-mininet.md) (mesmos passos e preocupações feitos no laboratório 3.1)
* [Depuração do webRTP no Chrome](depuracao-webrtp-chrome.md) - apresentação da interface de depuração do protocolo webRTP do Chrome que será utilizada neste laboratório. 


1. Execute o Chrome/Chromium na VM do mininet, tal como feito no laboratório "Multimidia e DASH", de maneira que o navegador possa acessar a Internet **e** você possa configurar parâmetros de rede emulados como atraso e taxa de transmissão. 
2. Estabeleça um par para comunicação no Google Meet. Você pode considerar as seguintes alternativas:
   * Se comunicar com você mesmo, com duas contas diferentes. Em uma delas você pode utilizar o seu celular ou a sua estação onde a VM está em execução. É importante que em uma delas haja um video sendo transmitido.
   * Estabecer um par com um aluno da disciplina para realização do teste conjunto.
3. Estabeleça uma conferência Google Meet com o par definido. 
4. Analise a qualidade da transmissão, particularmente em termos de tempo de resposta do video (sincronização).
5. Modifique os valores de **atraso**, **taxa de transmissão**, **jitter** e **erros** para os valores abaixo e reexecute o experimento. Ao variar a taxa de transmissão, mantenha o atraso em `0`.
   * Atraso: `100`, `400ms` e `1500ms`
   * Taxa de transmissão (bandwidth): `100kbps`, `500kbps`, `2000kbps`
   * Jitter: `50ms`, apenas para a taxa de `500kbps` e atraso de `400ms`.
   * Erros: `1` ou `2%`, apenas para a taxa de `500kbps` e atraso de `400ms`.
6. Em todos os casos, colete os gráficos de: 
   * RTT medido
   * Pacotes perdidos
   * Largura de Banda (`googAvailableReceiveBandwidth`)
   * `googFrameRateReceived` - taxa de frames recebida, que já é resultado da adaptação do protocolo
   * `googFrameWidthReceived` - tamanho do frame (pixels) recebida, que já é resultado da adaptação do protocolo (consistente com o dado anterior)

### Resultados 

1. Gráficos (mantidos em arquivos no diretório `graficos`)

2. Percepção do usuário: travamentos do video, atrasos na reprodução, piora na qualidade.

   *texto livre sobre a percepção do funcionamento da aplicação nos casos mencionados.*
