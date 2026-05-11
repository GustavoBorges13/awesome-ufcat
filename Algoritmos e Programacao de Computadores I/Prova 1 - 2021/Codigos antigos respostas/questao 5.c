#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    char nome[60];
    float nota1,nota2,nota3,media;

    //NOME DO ALUNO
    printf("Digite o nome do aluno: ");
    gets(nome);

    //NOTAS
    printf("\nDigite a 1° Nota como por exemplo 4,56: "); //TEM QUE USAR VIRGULA.
    scanf("%f", &nota1);
    printf("\nDigite a 1° Nota: ");
    scanf("%f", &nota2);
    printf("\nDigite a 1° Nota: ");
    scanf("%f", &nota3);
    printf("\nNotas: %1.2f %1.2f %1.2f", nota1,nota2,nota3);

    //LIMPA TELA E PRINTA OS DADOS
    system("cls");
    printf("***********************************\n");
    printf("Aluno (a): %s",nome);

    //VERIFICA SE FOI APROVADO OU REPROVADO
    media = (nota1 + nota2 + nota3)/3;

    if (media >= 6){
        printf("\nNota 1: %1.2f\tNota 2: %1.2f\tNota 3: %1.2f\tMédia Final:%1.2f\t Situação: APROVADO!\n",nota1,nota2,nota3,media);
        printf("Parabéns alunos pela sua aprovação.");
    }
    if (media < 5){
        printf("\nNota 1: %1.2f\tNota 2: %1.2f\tNota 3: %1.2f\tMédia Final:%1.2f\t Situação: REPROVADO!\n",nota1,nota2,nota3,media);
        printf("Infelizmente você foi reprovado, nos vemos semestre que vem.");
    }
    if (media >= 5 && media < 6){
        printf("Nota 1: %1.2f\tNota 2: %1.2f\tNota 3: %1.2f\tMédia Final:%1.2f\t Situação: ESTÁ EM RECUPERAÇÃO!\n",nota1,nota2,nota3,media);
    }
    printf("\n***********************************\n");
}
