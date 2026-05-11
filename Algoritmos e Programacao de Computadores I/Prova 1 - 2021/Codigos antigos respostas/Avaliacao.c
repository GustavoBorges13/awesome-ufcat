#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
    setlocale(LC_ALL,"Portuguese");
    int valor_1,valor_2,multiplo_1,multiplo_2,aux_1,aux_2, multiplo;
    char nome[15];

    //PARTE 1 - Coleta de dados e valores.
    printf("Digite o seu nome: ");
    gets(nome);

    printf("Digite o valor do multiplo: ");
    scanf("%d", &multiplo);

    printf("Digite o valor de X: ");
    scanf("%d", &valor_1);

    printf("Digite o valor de Y: ");
    scanf("%d", &valor_2);


    system("cls");

    //PARTE 2 - ANALISE E FEEDBACK.
    multiplo_1 = valor_1 % multiplo;
    multiplo_2 = valor_2 % multiplo;
    //Analisando o primeiro numero.
    if(multiplo_1 == 0){ //Se o valor_1 é multiplo de 5.
        aux_1=1; //Booleano...
    } else {
        aux_1=0;
    }
    //Analisando o segundo numero.
    if(multiplo_2 == 0){ //Se o valor_2 é multiplo de 5.
        aux_2=1; //Booleano...
    } else {
        aux_2=0;
    }

    //Colocar o resultado...
    if(aux_1 && aux_2 == 1){
        printf("%s, os números %d e %d SÃO múltiplos de %d!",nome,valor_1,valor_2,multiplo);
    } else {
        if (aux_1 == 0 && aux_2 == 1){
            printf("%s, o número %d não é múltiplo de %d, mas o número %d é múltiplo de %d!\n",nome,valor_1,multiplo,valor_2,multiplo);
        }
        if (aux_1 == 1 && aux_2 == 0){
            printf("%s, o número %d é múltiplo de %d, mas o número %d não é múltiplo de %d!\n",nome,valor_1,multiplo,valor_2,multiplo);
        }
        if (aux_1 == 0 && aux_2 == 0){
            printf("%s, os números %d e %d NÃO SÃO múltiplos de %d!\n",nome,valor_1,valor_2,multiplo);
        }
    }
    return 0;
}
