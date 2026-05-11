%Primeira Prova de PFL 2020/2
%Fulano de tal - XXXXXXXXX - 29/06/21

%1
%a)no termo 'lista([_|[X|X]).' falta fechar o segundo colchete aberto, deveria ser 'lista([_|[X|X]]).', mas mesmo com esta correção a igualdade apresentada não é válida
%b)X = 1, Y = 2, Z = 3, D = [4,5,6,7]
%c)esta igualdade é inválida a menos que façamos a troca do membro 'sinos' do termo a direita para o final da lista, assim temos: X = vale, Y = dos
%d)a igualdade é válida, e suas variáveis recebem: quiabo = 4, sapoti = 2, uva = 1

%2
maior(A,B):- A>B. %para saber se uma lista está ordenada antes precisamos de uma regra para saber se um número é maior que outro
ordenada([A]). %caso base, se uma lista tiver apenas um item, então ela está ordenada
ordenada([A,B|C]):- %a ordenação que iremos fazer é usando sempre os dois primeiros elementos da lista
    maior(B,A), %temos que verificar se B é maior que A, se não for verdade então a lista já não está ordenada
    ordenada([B|C]). %se o caso anterior for verdadeiro então devemos comparar o B com o seu sucessor que está na cauda da lista

%3
divideLista(_,[],[],[]). %caso base, se a nossa lista for vazia, as sublistas também serão
divideLista(N,[Cabeca|Cauda],[Cabeca|M1],M2):- %se a cabeça da lista for menor ou igual a N, devemos inserir ela em M1 que irá conter os números menores ou iguais a N
	Cabeca =< N,
	divideLista(N,Cauda,M1,M2).
divideLista(N,[Cabeca|Cauda],M1,[Cabeca|M2]):- %se a cabeça da lista for maior a N, devemos inserir ela em M2 que irá conter os números maiores a N
	Cabeca > N,
	divideLista(N,Cauda,M1,M2).

%4
numero([1,2,3,4,5,6,7,8,9]). %devemos declarar os números possíveis para a combinação do cofre
pegaNums(L,[N1,N2,N3,N4]):- %aqui usamos o select para retirar um número de uma determinada lista
    select(N1,L,L1), %retiramos o N1 da lista L e devolvemos a lista sem o número em L1
    select(N2,L1,L2), %retiramos o N2 da lista L1 e devolvemos a lista sem o número em L2
    select(N3,L2,L3), %retiramos o N3 da lista L2 e devolvemos a lista sem o número em L3
    select(N4,L3,_). %retiramos o N4 da lista L3 e não há necessidade de retornar uma lista
gerar(L):-
    numero(N),
    pegaNums(N,L).
testar([N1,7,N3,N4]):-
    N1>N3, %primeiro número é maior que o terceiro
    N1<7, %primeiro número é menor que o segundo
    1 is N1 mod 2, %primeiro número é impar
    N4 is N3+7, %quarto número é igual a soma do terceiro com o segundo
    N1 is N3+1. %primeiro número é igual o terceiro + 1    
combinacao(L):- gerar(L), testar(L).