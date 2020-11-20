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
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    for (aux=lista; aux != NULL; aux=aux->proximo) {
        printf("Registro:\n\t id: %d, \n\t nome: %s, \n\t nasc: %d/%d/%d, \n\t salario: %lf\n\n",
                aux->id, aux->nome, aux->nascimento.dia,
                aux->nascimento.mes, aux->nascimento.ano, aux->salario);
    }
}

Funcionario* deleta_elemento(Funcionario *lista, int key) {
    Funcionario *aux, *anterior;
    for (aux=lista; aux != NULL; aux=aux->proximo) {
        if (aux->id == key) {
            if (aux == lista) {
                lista = lista->proximo;
                if (lista == NULL) return NULL;
            }
            else {
                printf("Exclui\n\n");
                anterior->proximo = aux->proximo;
            }
            free(aux);
            aux = anterior;
        }
        anterior = aux;
    }
    return lista;
}

void limpa_toda_lista(Funcionario *lista) {
    Funcionario *aux;
    while (aux != NULL) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

int main() {
    int i, n;
    Funcionario *primeiro = NULL, *aux;

    printf("Digite o número de funcionários: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        aux = malloc(sizeof(Funcionario));
        
        printf("\nDigite o ID: \n");
        scanf("%d%*c", &aux->id); //o %*c representa ler um caractere mas não gravar, só outra forma de eliminar o '\n', pois ele atrapalha o fgets
        
        printf("\nDigite o nome: ");
        fgets(aux->nome, sizeof(aux->nome), stdin);
        aux->nome[strcspn(aux->nome, "\n")] = '\0'; //Trocando o \n por \0;

        printf("\nDigite a data nascimento (formato dd/mm/yyyy): ");
        scanf("%d/%d/%d", &aux->nascimento.dia, &aux->nascimento.mes, &aux->nascimento.ano);
        
        printf("\nDigite o salario: ");
        scanf("%lf", &aux->salario);
        aux->proximo = NULL;
        
        if (!primeiro) { //ele é o primeiro
            primeiro = aux;
        }
        else { //Faz o encadeamento
            aux->proximo = primeiro;    
            primeiro = aux;
        }
    }

    imprime_lista(primeiro);

    printf("\nExcluindo elemento com id 2\n");
    primeiro = deleta_elemento(primeiro, 2);

    printf("\nImprimindo a lista após a exclusão: \n");
    imprime_lista(primeiro);


    limpa_toda_lista(primeiro);

    printf("\nTerminamos!\n");

    return 0;
}