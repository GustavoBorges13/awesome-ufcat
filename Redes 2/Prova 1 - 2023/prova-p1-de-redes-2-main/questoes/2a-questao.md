
## 2a Questão

Escreva uma expressão para a vazão máxima de uma conexão TCP. Se necessário, considere  os parâmetros abaixo e que a taxa de transmissão é a mesma em todos os enlaces de comunicação. 

* Tamanho da janela de congestionamento - **W**
* Tempo de ida e volta - **RTT**
* Taxa transmissão disponível no enlace - **R**
* Tamanho da janela de controle de fluxo - **F** 
* Timeout - **T**

### Resposta (Q.2)
<!---- RESPOSTA ----->

VazãoMax = mínimo (W/RTT , F/RTT, R)
<!------------------->
