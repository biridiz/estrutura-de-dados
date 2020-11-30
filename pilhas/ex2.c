#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STR_PAR 

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

    aux->item - item;
    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void remove_pilha(Pilha *pilha, Item *item) {
    ElementoPilha *aux = malloc(sizeof(ElementoPilha));

    if (pilha_vazia(pilha) != 0) {
        printf("Erro na operacao remove_pilha: pilha vazia!\n");
        return;
    }

    *item = pilha->topo->item;
    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(aux);
}

void libera_pilha(Pilha *pilha) {
    ElementoPilha *aux = malloc(sizeof(ElementoPilha));

    while (pilha->topo != NULL) {
        aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;

        free(aux);
    }
}


int main() {
    char seqParent[TAM_MAX_STR_PAR + 1];
    Pilha pilha;
    int parentNaoEmpar;
    int i;
    Item item;
    Item itemEsperado;

    printf("Digite a sequencia de parenteses a ser avaliada: ");

    fgets(seqParent, sizeof(seqParent), stdin);
    seqParent[strcspn(seqParent, "\n")] = '\0';

    printf("Sequencia de parenteses a ser avaliada:\n%s\n", seqParent);

    inicializa_pilha(&pilha);

    parentNaoEmpar = 0;

    for (i=0; i < strlen(seqParent); i++) {
        item = seqParent[i];

        if ((item == '(') || (item == '[') || (item == '{')) {
            insere_pilha(&pilha, item);
        }
        else {
            if (item == ')') {
                itemEsperado = '(';
            }
            else if (item == ']') {
                itemEsperado = '[';
            }
            else if (item == '}') {
                itemEsperado = '{';
            }
            else {
                printf("Erro no processamento da sequencia de parenteses: "
                        "caractere invalido!\n");
                liberaPilha(&pilha);
                return 1;
            }

            if (pilha_vazia(&pilha) != 0) {
                parentNaoEmpar = 1;
                break;
            }
            
            remove_pilha(&pilha, &item);
            if (item != itemEsperado) {
                parentNaoEmpar = 1;
                break;
            }
        }
    }

    if ((parentNaoEmpar != 0) ||
            (pilhaVazia(&pilha) == 0) /* a pilha nao esta vazia */) {
        printf("Incorreto\n");
    }
    else {
        printf("Correto\n");
    }

    liberaPilha(&pilha);

    return 0;
}