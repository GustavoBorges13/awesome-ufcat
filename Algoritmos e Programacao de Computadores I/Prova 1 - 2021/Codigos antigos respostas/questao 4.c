#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    int num1,num2,aux;

    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    printf("Digite um número inteiro: ");
    scanf("%d", &num2);

    //TROCA DOS VALORES
    printf("Número 1 = %d\nNúmero 2 = %d\n",num1, num2); //print os valores digitados
    aux = num1;
    num1 = num2;
    num2 = aux;
    printf("\n----TROCA----\n");
    printf("\nNúmero 1 = %d\nNúmero 2 = %d\n",num1, num2); //print os valores trocados
}
