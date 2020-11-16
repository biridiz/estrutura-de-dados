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

Funcionario* delete(Funcionario *lista, int id) {
    Funcionario *aux, *anterior;
    aux = malloc(sizeof(Funcionario));
    anterior = malloc(sizeof(Funcionario));
    for (aux=lista; aux != NULL; aux=aux->proximo) {
        if (aux->id == id) {
            if (aux==lista) {
                lista = lista->proximo;
                anterior = lista;
            }
            else {
                anterior->proximo = aux->proximo;
            }
            free(aux);
            break;
        }
        anterior = aux;
    }
    return anterior;
}

int main() {
    int i, n;
    Funcionario *funcionarios;
    Funcionario *aux;

    funcionarios = malloc(sizeof(Funcionario));

    printf("Digite o número de funcionários: ");
    scanf("%d\n", &n);

    for (i=0; i<n; i++) {
        aux = malloc(sizeof(Funcionario));
        aux->id = (i+1);

        fgets(aux->nome, sizeof(aux->nome), stdin);
        aux->nome[strcspn(aux->nome, "\n")] = '\0';
        printf("Digite o salário: ");
        scanf("%lf", &aux->salario);
        if (i==(n-1)){
            printf("Digite a data de nascimento: ");
            scanf("%d %d %d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        }
        else {
            printf("Digite a data de nascimento: "); 
            scanf("%d %d %d\n", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        }
        aux->proximo = NULL;
        
        if (funcionarios) {
            aux->proximo = funcionarios;
            funcionarios = aux;
        }
    }

    printf("ID a ser deletado: \n");
    scanf("%d", &n);
    funcionarios = delete(funcionarios, n);
    printf("O primeiro da lista: %d\n", aux->id);

    printf("*** LISTA DE FUNCIONÁRIOS ***\n");
    for (aux=funcionarios; aux != NULL; aux=aux->proximo) {
        printf("\nId do funcionário: %d\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Salário: %.2lf\n", aux->salario);
        printf("Data de nascimento: %d/%d/%d\n", aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
    }

    free(funcionarios);
    free(aux);

    return 0;
}