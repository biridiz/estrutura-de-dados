#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char Item;

typedef struct valores {
    Item item;
    struct valores *proximo;
} Valores;

typedef struct {
    Valores *topo;
} Pilha;


void inicializa_pilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilha_vazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void insere_pilha(Pilha *pilha, Item item) {
    Valores *aux = malloc(sizeof(Valores));

    aux->item = item;

    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void remove_pilha(Pilha *pilha,  Item *item) {
    Valores  *aux = malloc(sizeof(Valores ));

    *item = pilha->topo->item;

    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(aux);
}

void libera_pilha(Pilha *pilha) {
    Valores *aux;

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
    }
}

char and(Item valor1, Item valor2) {
    if ((valor1 == 'v') & (valor2 == 'v'))
        return 'v';

    if ((valor1 == 'v') & (valor2 == 'f'))
        return 'f';

    if ((valor1 == 'f') & (valor2 == 'v'))
        return 'f';

    if ((valor1 == 'f') & (valor2 == 'f'))
        return 'f';

    return 'x';
}

char or(Item valor1, Item valor2) {
    if ((valor1 == 'v') & (valor2 == 'v'))
        return 'v';

    if ((valor1 == 'v') & (valor2 == 'f'))
        return 'v';

    if ((valor1 == 'f') & (valor2 == 'v'))
        return 'v';

    if ((valor1 == 'f') & (valor2 == 'f'))
        return 'f';
        
    return 'x';
}

char xor(Item valor1, Item valor2) {
    if ((valor1 == 'v') & (valor2 == 'v'))
        return 'f';

    if ((valor1 == 'v') & (valor2 == 'f'))
        return 'v';

    if ((valor1 == 'f') & (valor2 == 'v'))
        return 'v';

    if ((valor1 == 'f') & (valor2 == 'f'))
        return 'f';
        
    return 'x';
}

char not(Item valor) {
    if (valor == 'v')
        return 'f';

    if (valor == 'v')
        return 'f';

    if (valor == 'f')
        return 'v';

    if (valor == 'f')
        return 'v';
        
    return 'x';
}

int main() {
    Pilha pilha;
    Item item, itemValor, resultado;
    
    char pulaLinha;
    char entrada;
    int nOperacoes;
    int contValores=0, contOperadores=0;

    inicializa_pilha(&pilha);

    scanf("%d%c", &nOperacoes, &pulaLinha);

    if ((nOperacoes >= 1) & (nOperacoes <= 500)) {
        for (int i=0; i<nOperacoes; i++) {
            scanf("%c%c", &entrada, &pulaLinha);

            if ((entrada == 'v') | (entrada == 'f')) {
                contValores++;
                insere_pilha(&pilha, entrada);
            }
            else if ((entrada == 'E') | (entrada == 'O') | (entrada == 'X') | (entrada == 'N')) {
                contOperadores++;
                
                if (!pilha_vazia(&pilha)) {
                    remove_pilha(&pilha, &item);
                }
                if (entrada == 'E') {
                    remove_pilha(&pilha, &itemValor);
                    resultado = and(item, itemValor);
                    insere_pilha(&pilha, resultado);
                }
                if (entrada == 'O') {
                    remove_pilha(&pilha, &itemValor);
                    resultado = or(item, itemValor);
                    insere_pilha(&pilha, resultado);
                }
                if (entrada == 'X') {
                    remove_pilha(&pilha, &itemValor);
                    resultado = xor(item, itemValor);
                    insere_pilha(&pilha, resultado);
                }
                if (entrada == 'N') {
                    resultado = not(item);
                    insere_pilha(&pilha, resultado);
                }
            }
            else return 1;
        }
        
        libera_pilha(&pilha);
        printf("Valores: %d\nOperadores: %d\nResultado: %c\n", contValores, contOperadores, item);
    }

    return 0;
}



