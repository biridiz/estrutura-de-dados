#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 40

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct funcionario {
    int id;
    char nome[TAM_NOME+1];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
} Funcionario;

int main() {
    int i;
    Funcionario *primeiro;
    Funcionario *aux;

    primeiro = malloc(sizeof(Funcionario));

    primeiro->id = 0;
    snprintf(primeiro->nome, sizeof(primeiro->nome), "%s", "Luiz Dendena");
    primeiro->salario = 2100.00;
    primeiro->nascimento.dia = 25;
    primeiro->nascimento.mes = 8;
    primeiro->nascimento.ano = 1997;
    primeiro->proximo = NULL;

    for (i=0; i<3; i++) {
        Funcionario *aux;
        aux = malloc(sizeof(Funcionario));

        aux->id = (i+1);
        snprintf(primeiro->nome, sizeof(primeiro->nome), "%s", "Luiz Dendena");
        aux->salario = 2100.00;
        aux->nascimento.dia = 25;
        aux->nascimento.mes = 8;
        aux->nascimento.ano = 1997;
        aux->proximo = NULL;
        
        if (primeiro) {
            aux->proximo = primeiro;
            primeiro = aux;
        }
    }

    for (aux=primeiro; aux != NULL; aux=aux->proximo) {
        printf("Id do funcionário: %d\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Salário: %.2lf\n\n\n", aux->salario);
    }

    free(primeiro);
    free(aux);

    return 0;
}