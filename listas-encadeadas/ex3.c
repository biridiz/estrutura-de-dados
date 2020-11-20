#include <stdio.h>
#include <stdlib.h>

typedef struct lista_int {
    int valor;
    struct lista *proximo;
} ListaInt;

void imprime_lista(ListaInt *lista) {
    ListaInt *aux;
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    for (aux=lista; aux != NULL; aux=aux->proximo) {
        printf("Valor:%d ", aux->valor);
    }
}

ListaInt* constroi_lista(int n, int *v) {
    /*Vamos utilizar o ultimo para encadear os elementos na forma correta.
    Uma opção seria encadear tudo com o primeiro, mas andando na lista de tras para frente.*/
    ListaInt *primeiro, *ultimo, *aux;
    int i;
    primeiro = malloc(sizeof(ListaInt));
    primeiro->valor = v[0];
    primeiro->proximo = NULL;
    ultimo = primeiro;

    for (i=1; i<n; i++) {
        aux = malloc(sizeof(ListaInt));
        aux->valor = v[i];
        aux->proximo = NULL;
        // Faz o encademamento do novo elemento no fim da lista
        ultimo->proximo = aux;
        ultimo = aux; // Torna o novo elemento (aux) o último
    }

/* Faz a mesma coisa mais sem usar o aux
    for (i=1, i<n; i++) {
        ultimo->proximo = malloc(sizeof(ListaInt));
        ultimo = ultimo->proximo;

        ultimo->valor = v[i];
        ultimo->proximo = NULL;
    } */

    return primeiro;
}

void limpa_toda_lista(ListaInt *primeiro) {
    ListaInt *aux;
    while (primeiro != NULL) {
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);
    }
}

int main() {
    ListaInt *primeiro = NULL;
    int i, n, *vet;

    printf("Digite o número de valores: ");
    scanf("%d", &n);

    vet = malloc(sizeof(int)*n); // Aloca vetor dinâmicamente
    printf("\nDigite todos os valores separados por ',' sem espaços. (Ex: 1,2,3)\n");

    for (i=0; i<n; i++) {
        scanf("%d", &vet[i]);
    }

    primeiro = constroi_lista(n , vet);

    imprime_lista(primeiro);
    
    limpa_toda_lista(primeiro);
    free(vet);

    printf("\nTerminamos\n");

    return 0;
}