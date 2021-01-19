#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Letra;

typedef struct letras {
    Letra primeira;
    Letra segunda;
    Letra terceira;
    Letra quarta;
    struct letras *proximo;
} Letras;

typedef struct {
    Letras *topo;
} Pilha;



void inicializa_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void insere_pilha(Pilha *pilha, Letra letras[]) {
    Letras *aux = malloc(sizeof(Letras));

    aux->primeira = letras[0];
    aux->segunda = letras[1];
    aux->terceira = letras[2];
    aux->quarta = letras[3];

    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void remove_pilha(Pilha *pilha, Letra *letras) {
    Letras *aux = malloc(sizeof(Letras));

    letras[0] = pilha->topo->primeira;
    letras[1] = pilha->topo->segunda;
    letras[2] = pilha->topo->terceira;
    letras[3] = pilha->topo->quarta;

    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(aux);
}

void libera_pilha(Pilha *pilha) {
    Letras *aux;

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
    }
}

int compara_letras(Letra sequencia1[], Letra sequencia2[]) {
    int i, cont = 1, j=3;
    
    for (i=0; i<4; i++) {
        if (sequencia1[i] == sequencia2[j]) {
            cont++;
            j--;
        }
    }

    if (cont == 4) {
        return 1;
    }

    return 0;
}

int main() {
    int n, i,  cont = 0;
    Letra letras[4] = {'F', 'A', 'C', 'E'};
    Letra guardaLetras[4];
    Pilha pilha;

    inicializa_pilha(&pilha);
    insere_pilha(&pilha, letras);

    scanf("%d\n", &n);

    if ((n >= 1) & (n <= 100)) {
        for (i=0; i<n; i++) {
            scanf("%c %c %c %c\n", &letras[0], &letras[1], &letras[2], &letras[3]);
            remove_pilha(&pilha, guardaLetras);

            if (compara_letras(letras, guardaLetras)) {
                cont++;
                continue;
            }
            else {
                insere_pilha(&pilha, guardaLetras);
                insere_pilha(&pilha, letras);
            }
        }
    }

    printf("%d\n", cont);

    return 0;
}