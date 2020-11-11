#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    double n1;
    double n2;
    double n3;
} Aluno;

int main() {
    int i;
    Aluno alunos[5];

    for (i=0; i<5; i++) {
        printf("Digite o número de matrícula: ");
        scanf("%d\n", &alunos[i].matricula);

        printf("Digite o nome do aluno: \n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite as 3 notas: ");
        scanf("%lf %lf %lf", &alunos[i].n1, &alunos[i].n2, &alunos[i].n3);
    }

    return 0;
}