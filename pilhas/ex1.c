#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct elementoPilha {
    Item item;
    struct elementoPilha *proximo;
} ElementoPilha;

typedef struct {
    ElementoPilha *topo;
} Pilha;

void insere_pilha(Pilha *pilha, Item item) {
    ElementoPilha *aux = malloc(sizeof(ElementoPilha));

    aux->item = item;

    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void remove_pilha(Pilha *pilha, Item *item) {
    ElementoPilha *aux = malloc(sizeof(ElementoPilha));

    *item = pilha->topo->item;

    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(aux);
}

void inicializa_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void libera_pilha(Pilha *pilha) {
    ElementoPilha *aux;

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
    }
}

int main() {
    Pilha pilha;
    Item item;
    int i;

    inicializa_pilha(&pilha);

    for (i=0; i<10; i++) {
        item = i;

        printf("Inserindo na pilha o item %d. \n", item);
        insere_pilha(&pilha, item);
    }

    while (pilha_vazia(&pilha) == 0) {
        remove_pilha(&pilha, &item);
        printf("Item %d removido da pilha\n", item);
    }

    libera_pilha(&pilha);

    return 0;
}