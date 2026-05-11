% Nome: Fulano de tal
% Matricula: XXXXXXXXXXX
% Questão 1
% (A) ->A variavel anonima (_) do functor após a igualdade seria "a",pois ela é o head da lista, 
% 		porem devido a ser anonima seu valor não ira importar,sendo assim sobrando o resto
% 		da lista [[b], c, [d]], no caso taill. A partir da cauda será selecionado o 
% 		novo head o qual é "X" que sera igual a "[b]", e sendo assim o resto da lista será "X", o qual teria que
% 		ser igual ao novo Head porem ele sera [c, [d]], o que ira resultar na resposta false.  
% (B) -> Ele ira se unificar as duas listas onde o X ira pegar o primeiro elemento da lista que no caso é 1, 
% 		após o Y ira pegar o segundo elemento da lista que no caso é 2 , depois o Z ira pegar o 3 e 
% 		o resto da lista ira se unificar com o taill no caso o D, o qual tera os seguintes valores [4,5,6,7].
% (C) -> Ele ira resultar em false, pois as constantes na primeira posição de ambas as listas são diferentes, 
% 		no caso "vale" e "sinos".
% (D) -> Uva ira se unificar com 1, Sapoti ira se unificar com 2, o 3 ira se unificar com ele mesmo 
% 		e Quiabo ira se unificar com 4, e isso ocorre porque são variaveis se unificando com constantes ou
%		constantes se unificando com elas mesmas.

% Questão 2
ordenada([A]).
ordenada([A,B]):- A =< B.
ordenada([A,B|C]):- A =< B, ordenada([B|C]).

%Questão 3
divide_lista(Corte, [], [], []).
divide_lista(Corte, [X|Y], [X|Y1], Y2):- 
    		X=<Corte, 
    		divide_lista(Corte, Y, Y1, Y2).
divide_lista(Corte, [X|Y], Y1, [X,Y2]):- 
    		X>Corte, 
    		divide_lista(Corte, Y, Y1, Y2).
    
%Questão 4
numero([1,2,3,4,5,6,7,8,9]).

gerar(L):- numero(Numero),
 			gera_linha(Numero,L).
gera_linha(L,[X,Y,W,Z]):- 
            select(X,L,L1),
            select(Y,L1,L2),
            select(W,L2,L3),
            select(Z,L3,_).
testar([X,7,W,Z]):-
    		X>W,
    		X<7,    		 
    		Z =:= W+7,
    		1 =:= (X mod 2),
            X =:= W+1.	
cofre(L):- gerar(L), testar(L).

%gerar([X, Y, W, Z]).
%testar([3,7,2,9]).
%cofre([3,7,2,9]).