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

void imprime_lista(Funcionario *lista) {
    Funcionario *aux;
    for (aux=lista; aux != NULL; aux=aux->proximo) {
        printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n",
                aux->id, aux->nome, aux->nascimento.dia, 
                aux->nascimento.mes, aux->nascimento.ano, aux->salario);    
    }
}

int main() {
    Funcionario *primeiro, *segundo;

    primeiro = malloc(sizeof(Funcionario));
    primeiro->id = 1;
    snprintf(primeiro->nome, sizeof(primeiro->nome), "%s", "Luiz Dendena");
    primeiro->salario = 2100.00;
    primeiro->nascimento.dia = 25;
    primeiro->nascimento.mes = 8;
    primeiro->nascimento.ano = 1997;
    primeiro->proximo = NULL;

    segundo = malloc(sizeof(Funcionario));
    segundo->id = 2;
    snprintf(segundo->nome, sizeof(segundo->nome), "%s", "Luiz Roberto");
    segundo->salario = 1800.00;
    segundo->nascimento.dia = 2;
    segundo->nascimento.mes = 12;
    segundo->nascimento.ano = 1999;
    segundo->proximo = NULL;

    primeiro->proximo = segundo;

    imprime_lista(primeiro);

    free(primeiro);
    free(segundo);

    return 0;
}