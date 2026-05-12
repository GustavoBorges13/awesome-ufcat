# Laboratório 2.1: Efeito de Atrasos e Erros no Desempenho da Camada de Transporte

## Identificação

* Aluno: "COLOQUE O SEU NOME AQUI"

## Formato das respostas

Exceto quando informando explicitamente, todos os resultados devem ser formatados usando a formatação de código no Markdown, conforme já feito nos laboratórios anteriores. Respostas em texto livre devem ser escritas em **texto normal**, sem formatação.

* Documentação do formato de tabelas no Markdown Github: <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting/organizing-information-with-tables>

**Observe** que neste laboratório você deverá incluir arquivos externos com os dados coletados no experimento, além dos gráficos gerados. Eles devem seguir o seguinte padrão:

* Os arquivos com os dados devem ser arquivos CSV (dados separados por ponto e vírgula) e devem ser mantidos no diretório `resultados`. Nesse diretório você encontrará um exemplo de arquivo.
* Os gráficos devem ser gerados com a ferramenta **gnuplot** e as figuras devem ser mantidas em formato PNG também no diretório `resultados`. Os gráficos gerados serão incorporados neste relatório por tags HTML, como no exemplo, e há ainda um gráfico de exemplo gerado a partir do CSV de exemplo. 

Há uma seção sobre a instalação do [**gnuplot**](#gnuplot) e uso para geração dos gráficos deste laboratório.

## Requisitos mínimos de entrega deste relatório

Conforme indicado no plano da disciplina, para obter nota mínima de 6,0 do relatório será necessário que ele atenda a **todos** os requisitos abaixo indicados:

1. Todas as tarefas na seção "Resultados" devem ser respondidas e devem seguir o formato solicitado.
2. Não deve haver qualquer tipo de cópia deste relatório ou do código produzido com o de outro aluno, **independentemente do semestre**. Os experimentos e o relatório são individuais.
3. O seu relatório deverá ser submetido pelo Github Classroom.

A complementação da nota pela avaliação qualitativa do relatório, considerará as respostas das questões abertas (em texto livre) e **sobretudo** os resultado do experimento.

Na seção [**"Feedback"**](#Feedback) ao fim deste relatório, o professor incluirá a avaliação do seu relatório.

<p id="gnuplot" />

## Usando o gnuplot

O **gnuplot** é um software de para geração de gráficos que você precisará usar neste laboratório. O laboratório foi planejado para você fazer o uso dessa ferramento, com o mínimo de dificuldade. O **gnuplot** não vem pré-instalado na VM mininet e você deve instalá-lo com o seguinte comando: 

        sudo apt install gnuplot-x11
  
Para executar o **gnuplot** da maneira como esse laboratório está preparado, utilize os arquivos de configuração fornecidos para o experimento que os gráficos serão gerados sem nenhuma complicação adicional. Certifique-se de fazer isso com tempo, para evitar problemas/dificuldades no uso do ambiente. Para gerar um gráfico usando o arquivo de configuração `gera-grafico-1-gnuplot.txt`, considerando que o arquivo está no diretório corrente, execute do terminal o seguinte comando (de dentro do diretório `resultados`): 

        gnuplot gera-grafico-1-gnuplot.txt 
        
Caso você execute o gnuplot sem parâmetros e entre do prompt da ferramenta (aparecerá `gnuplot> ` no terminal), basta digitar ctrl-D para sair e voltar ao terminal.

## Resultados

1. (**ref. 2**) Indique o desempenho do TCP obtido na comunicação entre duas estações, em termos de largura de banda, nos seguintes casos:

   * Transmissão sem limitação de comunicação nos nós (atraso mínimo e banda máxima). (texto livre)
   
      *33.5Mbits/sec*
   
   * Transmissão com largura de banda de 70 Mbps. (texto livre)
   
      *67.1Mbps/sec*
      
2. (**ref. 3**) Meça o desempenho do TCP com taxas de erros variando entre 0 e 15%, escolhendo 20 valores (mínimo) nessa faixa, sendo 10 deles entre 0 e 3%. No experimento, basta executar o `iperf`, medir os valores e anotar no respectivo arquivo com os resultados.

   1. Descreva todos os valores obtido em uma tabela (utilize a tabela abaixo como modelo). Tenha particular **atenção** aos valores em Mbps, pois caso o valor produzido no experimento será em Kbps você terá que fazer a devida conversão.
   
| Taxa de Erros (%) | Largura de Banda (Mbps) |
| ----------------- | ----------------------- |
| 0.1               | 66.5                    |
| 0.3               | 66.1                    |
| 0.5               | 66.2                    |
| 0.7               | 59.5                    |
| 1                 | 58.3                    |
| 1.5               | 52.36                   |
| 2                 | 44.97                   |
| 2.5               | 26.53                   |
| 2.7               | 22.26                   |
| 3                 | 17.0                    |
| 4                 | 6.3                     |
| 4.5               | 8.19                    |
| 5                 | 4.58                    |
| 5.5               | 3.24                    |
| 6                 | 1.73                    |
| 6.5               | 602 kb                  |
| 7                 | 1.82                    |
| 7.5               | 268 kb                  |
| 8                 | 229 kb                  |
| 9                 | 681 kb                  |

    
   2. Armazene todos os valores obtidos no arquivo CSV `resultados/banda-por-erros-70mbps.csv`. Há um arquivo de exemplo no respectivo diretório, que deve ser a base para você armazenar os valores. Observe com cuidado o separador de ponto flutuate que é "." e não ",".
   
   3. Gere o gráfico de **Largura de Banda** por **Taxa de Erros**. O seu gráfico deverá ser incluído logo a seguir, da mesma maneira como o gráfico de exemplo utilizado (armazenado no arquivo `resultados/grafico-banda-por-erros-70mbps.png`). 
   
      O arquivo `gera-grafico-1-gnuplot.txt` contém a configuração gnuplot para geração do gráfico deste experimento. Se você não introduziu nenhum dado errado no arquivo anterior, bastará que execute `gnuplot gera-grafico-1-gnuplot.txt` que o arquivo será gerado e incorporado neste arquivo.
   
      <img src="resultados/grafico-banda-por-erros-70mbps.png" />
    
   4. Discuta o resultado obtido no experimento, o seu significado, e **sobretudo** a sua explicação para o resultado do gráfico, baseando-se no funcionamento do TCP. É fundamental que você explique por que o fenômeno observado ocorre. (texto livre)
   
O experimento realizado consistiu na medição do desempenho de uma conexão TCP em termos de largura de banda, variando a taxa de erros nos enlaces entre as estações no Mininet. Os resultados apresentam uma relação inversamente proporcional entre a taxa de erros e a largura de banda, o que pode ser compreendido considerando o funcionamento do TCP.

Quando a taxa de erros é baixa, ou seja, nos primeiros valores até 3%, a largura de banda permanece relativamente estável, indicando que o TCP consegue lidar eficientemente com a correção de pacotes perdidos ou corrompidos. Nesse cenário, o TCP utiliza mecanismos como retransmissões e controle de fluxo para manter a integridade da comunicação, minimizando o impacto na largura de banda.

No entanto, à medida que a taxa de erros aumenta, observa-se uma queda significativa na largura de banda. Isso se deve ao fato de que o TCP interpreta a perda de pacotes como congestionamento na rede e, em resposta, reduz a taxa de transmissão para evitar uma sobrecarga ainda maior. O TCP adota uma abordagem conservadora para garantir a confiabilidade, sacrificando a largura de banda em prol da estabilidade da comunicação.

Nos casos em que a taxa de erros ultrapassa um limiar crítico, a largura de banda praticamente se torna inviável, chegando a valores extremamente baixos. Isso ocorre porque o TCP interpreta esses erros como indicativos de uma rede instável, e as estratégias de controle de congestionamento são mais agressivas, reduzindo drasticamente a taxa de transmissão.
   
2. (**ref. 4**) Meça o desempenho do TCP em um cenário sem erros, variando o atraso dos enlaces entre 0 e 1250 ms, escolhendo 10 valores nessa faixa. 

   1. Descreva todos os valores obtido em uma tabela (utilize a tabela abaixo como modelo)
   
| Atraso dos Enlaces (ms) | Largura de Banda (Mbps) |
| ----------------------- | ----------------------- |
| 0                       | 66.1                      |
| 100                       | 53.8                       |
| 200                       | 29.0                      |
| 300                       | 11.2                       |
| 400                       | 3.74                       |
| 500                       | 1.26                       |
| 600                       | 1.05                       |
| 750                       | 536 kb                       |
| 1000                       | 349 kb                       |
| 1250                       | 210 kb                      |
    
   2. Armazene todos os valores obtidos no arquivo CSV `resultados/banda-por-atraso-70mbps.csv`. Há um arquivo de exemplo no respectivo diretório, que deve ser a base para você armazenar os valores. Observe com cuidado o separador de ponto flutuate que é "." e não ",".
   
   3. Gere o gráfico de **Largura de Banda** por **Taxa de Erros**. O seu gráfico deverá ser incluído logo a seguir, da mesma maneira como o gráfico de exemplo utilizado (armazenado no arquivo `resultados/grafico-banda-por-erros-70mbps.png`). 
   
      O arquivo `gera-grafico-2-gnuplot.txt` contém a configuração gnuplot para geração do gráfico deste experimento. Se você não introduziu nenhum dado errado no arquivo anterior, bastará que execute `gnuplot gera-grafico-2-gnuplot.txt` que o arquivo será gerado e incorporado neste arquivo.
   
      <img src="resultados/grafico-banda-por-atraso-70mbps.png" />
    
   4. Discuta o resultado obtido no experimento, o seu significado, e **sobretudo** a sua explicação para o resultado do gráfico, baseando-se no funcionamento do TCP. É fundamental que você explique por que o fenômeno observado ocorre. (texto livre)

Em condições ideais, sem atrasos (0 ms), o TCP atinge uma largura de banda próxima ao seu limite máximo. Entretanto, à medida que introduzimos atrasos crescentes de 100 ms a 600 ms, observamos uma queda gradual e consistente na largura de banda. Essa redução é uma manifestação do TCP interpretando o atraso como um possível sinal de congestionamento na rede. O TCP é um protocolo projetado para ajustar dinamicamente sua taxa de transmissão com base em feedbacks recebidos. A presença de atrasos mais extensos leva o TCP a implementar estratégias mais agressivas de controle de congestionamento, reduzindo a taxa de transmissão para evitar potenciais congestões. Essa resposta graduada ao aumento dos atrasos reflete a natureza sensível do TCP à latência na rede.

À medida que atingimos a marca de 750 ms, 1000 ms e 1250 ms de atraso, a largura de banda experimenta uma diminuição drástica. Nessas situações, o TCP enfrenta timeout mais frequente devido ao aumento no tempo necessário para confirmar a entrega bem-sucedida de pacotes. O controle de congestionamento do TCP torna-se mais proeminente, resultando em taxas de transmissão muito reduzidas.A capacidade do protocolo em fornecer largura de banda eficiente é comprometida à medida que os atrasos aumentam, destacando a importância crítica do gerenciamento eficaz da rede para assegurar um desempenho otimizado das aplicações. 


<p id="Feedback" />

## Feedback do Professor

*Esta seção será escrita pelo professor ao final da avaliação do seu relatório*.

