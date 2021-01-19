#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct elementoDeque {
    Item item;
    struct elementoDeque *proximo;
    struct elementoDeque *anterior;
} ElementoDeque;

typedef struct {
    ElementoDeque *primeiro;
    ElementoDeque *ultimo;
} Deque;


void inicializaDeque(Deque *deque) {
    deque->primeiro = NULL;
    deque->ultimo = NULL;
}

int dequeVazio(Deque *deque) {
    return (deque->primeiro == NULL);
}

void insereInicioDeque(Deque *deque, Item *item) {
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));
    
    aux->item = *item;
    aux->proximo = NULL;
    aux->anterior = NULL;

    if (deque->primeiro == NULL) {
        deque->primeiro = aux;
        deque->ultimo = aux;
    }
    else {
        aux->proximo = deque->primeiro;
        deque->primeiro->anterior = aux;
        deque->primeiro = aux;
    }
}

void insereFimDeque(Deque *deque, Item *item) {
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));
    
    aux->item = *item;
    aux->proximo = NULL;
    aux->anterior = NULL;

    if (deque->ultimo == NULL) {
        deque->primeiro = aux;
        deque->ultimo = aux;
    }
    else {
        aux->anterior = deque->ultimo;
        deque->ultimo->proximo = aux;
        deque->ultimo = aux;
    }
}

void removeInicioDeque(Deque *deque, Item *item) {
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));

    *item = deque->primeiro->item;
    aux = deque->primeiro;

    if (deque->primeiro == deque->ultimo) {
        deque->primeiro = NULL;
        deque->ultimo = NULL;
    }
    else {
        deque->primeiro = deque->primeiro->proximo;
        deque->primeiro->anterior = NULL;
    }

    free(aux);
}

void removeFimDeque(Deque *deque, Item *item) {
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));

    *item = deque->ultimo->item;
    aux = deque->ultimo;

    if (deque->ultimo == deque->primeiro) {
        deque->primeiro = NULL;
        deque->primeiro = NULL;
    }
    else {
        deque->ultimo = deque->ultimo->anterior;
        deque->ultimo->proximo = NULL;
    }

    free(aux);
}

void liberaDeque(Deque *deque) {
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));

    while (dequeVazio(deque) == 0) {
        aux = deque->primeiro;
        deque->primeiro = deque->primeiro->proximo;
        free(aux);
    }

    deque->ultimo = NULL;
}


int main() {
    int n = -1;
    int valor, valorInicio, valorFim;
    int contFila=0, contPilha=0;
    char operacao;

    Deque deque;
    inicializaDeque(&deque);

    while (n) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if ((n >= 1) & (n <= 1000)) {
            for (int i=0; i<n; i++) {
                scanf("%c %d", &operacao, &valor);
                
                if (operacao == 'I') {
                    insereInicioDeque(&deque, &valor);
                }

                if (operacao == 'R') {                    
                    if (!dequeVazio(&deque)) {
                        removeFimDeque(&deque, &valorFim);
                    }

                    if (!dequeVazio(&deque)) {
                        removeInicioDeque(&deque, &valorInicio);
                    }
                    
                    if ((valor != valorFim) & (valor != valorInicio)) {
                        contPilha = 0;
                        contFila = 0;
                        break;
                    }
                    if (valor == valorFim) {
                        contPilha++;
                        contFila = 0;
                        insereInicioDeque(&deque, &valorInicio);
                    }
                    if (valor == valorInicio) {
                        contFila++;
                        contPilha = 0;
                        insereFimDeque(&deque, &valorFim);
                    }
                }
            }
        }

        if ((contPilha == 0) & (contFila != 0)) {
            printf("fila!\n");
        }
        if ((contPilha != 0) & (contFila == 0)) {
            printf("pilha!\n");
        }
        if ((contPilha == 0) & (contFila == 0)){
            printf("jokerBag!\n");
        }
        if ((contPilha != 0) & (contFila != 0)) {
            printf("nem Turing sabe!\n");
        }
    } 

    liberaDeque(&deque);

    return 0;
}