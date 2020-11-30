#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elementoFila {
    Item item;
    struct elementoFila *proximo;
} ElementoFila;

typedef struct {
    ElementoFila *primeiro;
    ElementoFila *ultimo;
} Fila;

void insere_fila(Fila *fila, Item *item) {
    ElementoFila *aux = malloc(sizeof(ElementoFila));
    
    aux->item = *item;
    aux->proximo = NULL;

    if (fila->primeiro == NULL) {
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else {
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}

void remove_fila(Fila *fila, Item *item) {
    ElementoFila *aux = malloc(sizeof(ElementoFila));

    *item = fila->primeiro->item;
    aux = fila->primeiro;

    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->primeiro = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }

    free(aux);
}

void inicializa_fila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int fila_vazia(Fila *fila) {
    return (fila->primeiro == NULL);
}

void libera_fila(Fila *fila) {
    ElementoFila *aux = malloc(sizeof(ElementoFila));

    while (fila->primeiro == NULL) {
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
        free(aux);
    }

    fila->ultimo = NULL;
}

int qntd_itens_fila(Fila *fila) {
    int cont = 0;

    if (fila_vazia(fila)) {
        return cont;
    }
    else {
        while (fila_vazia(fila) == 0) {
            remove_fila(fila, &cont);
            printf("Item %d removido da fila.\n", cont);
            cont++;
        }
        return cont;
    }
}

int fila_ordem_crescente(Fila *fila) {
    Item item;
    Item proxItem;
    int ordemCrescente = 1;

    if (fila_vazia(fila) != 0)
        return 1;

    remove_fila(fila, &item);
    
    while (fila_vazia(fila) == 0) {
        remove_fila(fila, &proxItem);

        if (item <= proxItem)
            ordemCrescente = 0;
        
        item = proxItem;
    }

    return ordemCrescente;
}

Fila copia_fila(Fila *fila) {
    Fila filaCopiaAux;
    Fila filaCopia;
    Item item;

    inicializa_fila(&filaCopiaAux);

    while (fila_vazia(fila) == 0) {
        remove_fila(fila, &item);
        insere_fila(&filaCopiaAux, item);
    }

    inicializa_fila(&filaCopia);

    while (fila_vazia(&filaCopiaAux) == 0) {
        remove_fila(&filaCopiaAux, &item);
        insere_fila(fila, item);
        insere_fila(&filaCopia, item);
    }

    libera_fila(&filaCopiaAux);

    return filaCopia;
}


int main() {

    return 0;
}



