#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct elementoPilha {
    Item item;
    struct elementoPilha *proximo;
} ElementoPilha;

typedef struct {
    ElementoPilha *topo;
} Pilha;



void inicializa_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

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

void libera_pilha(Pilha *pilha) {
    ElementoPilha *aux;

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
    }
}

void inverte_letras(char frase[]) {
    int i = 0;
    int j = 1;
    char mat[5][30];
    Pilha pilha;
    Item item;

    inicializa_pilha(&pilha);

    mat[0][0] = ' ';

    do {
        mat[0][j] = frase[i];
        i++;
        j++;
    } while (frase[i] != ' ');
    mat[0][j+1] = '\0';
    j = 0;

    do {
        mat[1][j] = frase[i];
        i++;
        j++;
    } while (frase[i] != ' ');
    mat[1][j+1] = '\0';
    j = 0;
    
    do {
        mat[2][j] = frase[i];
        i++;
        j++;
    } while (frase[i] != ' ');
    mat[2][j+1] = '\0';
    j = 0;
    
    do {
        mat[3][j] = frase[i];
        i++;
        j++;
    } while (frase[i] != ' ');
    mat[3][j+1] = '\0';
    j = 0;
    
    while (frase[i] != '.') {
        mat[4][j] = frase[i];
        i++;
        j++;
    }
    mat[4][j+1] = '\0';
    
    
    i = 0;
    while (mat[4][i] != '\0') {
        insere_pilha(&pilha, mat[4][i]);
        i++;
    }
    
    i = 0;
    while (mat[3][i] != '\0') {
        insere_pilha(&pilha, mat[3][i]);
        i++;
    }
    
    i = 0;
    while (mat[2][i] != '\0') {
        insere_pilha(&pilha, mat[2][i]);
        i++;
    }

    i = 0;
    while (mat[1][i] != '\0') {
        insere_pilha(&pilha, mat[1][i]);
        i++;
    }

    i = 0;
    while (mat[0][i] != '\0') {
        insere_pilha(&pilha, mat[0][i]);
        i++;
    }
    
    while (pilha_vazia(&pilha) == 0) {
        remove_pilha(&pilha, &item);
        printf("%c ", item);
    }
    printf("\n");
}


int main() {
    char frase[30] = "ESTE EXERCICIO E MUITO FACIL.\0";
    inverte_letras(frase);


    return 0;
}