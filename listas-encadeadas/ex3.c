#include <stdio.h>
#include <stdlib.h>

typedef struct lista_int {
    int n;
    struct lista_int *proximo;
} ListaInt;

ListaInt* constroi_lista(int n, int *v) {
    int i;
    ListaInt *vetor_lista, *aux;

    vetor_lista = malloc(sizeof(ListaInt));
    vetor_lista->n = v[3];
    vetor_lista->proximo = NULL;

    for (i=2; i>=0; i--) {
        aux = malloc(sizeof(ListaInt));

        aux->n = v[i];
        aux->proximo = NULL;

        if (vetor_lista) {
            aux->proximo = vetor_lista;
            vetor_lista = aux;
        }
    }
    return vetor_lista;
}

int main() {
    int v[4] = {1, 21, 4, 6};
    ListaInt *vetor_lista, *aux;

    vetor_lista = malloc(sizeof(ListaInt));
    vetor_lista = constroi_lista(4, v);

    for (aux=vetor_lista; aux != NULL; aux=aux->proximo) {
        printf("%d\n", aux->n);
    }

    free(vetor_lista);
    return 0;
}