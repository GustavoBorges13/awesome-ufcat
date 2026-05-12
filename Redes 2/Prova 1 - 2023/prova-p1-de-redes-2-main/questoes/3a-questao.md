    
## 3a Questão

Considere dois processos em duas estações **A** e **B** conversando pela rede, utilizando TCP, e trocando um volume grande de informações e transmitindo a uma vazão **V** em bytes/s. Responda:

  1. Se um outro processo TCP é iniciado em **A** para transmitir para outro processo em **B**, qual é a vazão de transmissão que esse processo atinge? Justifique.
  2. Se no caso anterior, a transmissão ocorre em UDP, é possível que essa aplicação transmita pacotes na mesma velocidade ou maior que na outra conexão TCP? No caso do UDP, considere a velocidade efetiva em que os pacotes são entregues. **JUSTIFIQUE** a sua resposta.
  3. As transmissões indicadas nas letras (a) e (b) afetam a transmissão original? **Justifique**.

### Resposta (Q.3)
<!---- RESPOSTA ----->

1. *texto da sua resposta do item (1)*
Se um novo processo TCP é iniciado em A para transmitir para B enquanto uma transmissão TCP existente já ocorre entre os processos originais em A e B, devido a natureza orientada à conexão do TCP, ele tenta dividir justamente a largura de banda disponível entre a conexão do novo processo com o processo TCP existente.  A vazão do novo processo dependerá do mecanismo de controle de congestionamento do TCP, que ajusta dinamicamente a taxa de transmissão, geralmente, o novo processo TCP terá uma parte da largura de banda, mas não atingirá a vazão completa se a largura de banda total for limitada.

2. *texto da sua resposta do item (2)*
No caso do UDP, é possível que essa aplicação transmita pacotes na mesma velocidade ou em uma taxa maior em comparação com a conexão TCP. Isso ocorre devido a natureza não orientada a conexão do UDP, que não possui mecanismos de controle de congestionamento, ao contrário do TCP, o que significa que a aplicação pode enviar pacotes a uma taxa mais elevada do que a permitida pelo controle de congestionamento do TCP. Porem é importante notar que a velocidade efetiva em que os pacotes são entregues pode ser menor do que a velocidade de transmissão, devido a congestionamentos na rede ou perda de pacotes.

3. *texto da sua resposta do item (3)*
As transmissões indicadas em (a) e (b) podem afetar a transmissão original.
- No caso (a), a adição de um novo processo TCP na estação A resultará em uma divisão da largura de banda disponível entre os dois processos TCP. Cada um deles terá uma vazão menor em comparação com a transmissão original.
- No caso (b), se a transmissão em UDP estiver ocorrendo simultaneamente com a transmissão original, a natureza do UDP pode causar congestão na rede, impactando negativamente a transmissão original.

<!------------------->

  
