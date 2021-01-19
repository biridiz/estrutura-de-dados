#include <stdio.h>
#include <stdlib.h>

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
    int cont = 0;
    ElementoDeque *aux = malloc(sizeof(ElementoDeque));

    while (dequeVazio(deque) == 0) {
        aux = deque->primeiro;
        deque->primeiro = deque->primeiro->proximo;
        free(aux);
        cont++;
    }

    deque->ultimo = NULL;
    printf("%d\n", cont);
}

int main() {
    int n, operacao, valor, *guardaValor;
    int cont = 0;
    char pulaLinha;
    Deque deque;
    
    scanf("%d", &n);
    guardaValor = malloc(sizeof(int)*((n-2)/2));

    if (n >= 2) {
        scanf("%d", &operacao);
        if (operacao == 1) {
            inicializaDeque(&deque);
            for (int i=0; i<(n-2); i++) {
                scanf("%d%c", &operacao, &pulaLinha);
                if (operacao == 2) {
                    scanf("%d", &valor);
                    insereInicioDeque(&deque, &valor);
                }
                if (operacao == 3) {
                    scanf("%d", &valor);
                    insereFimDeque(&deque, &valor);
                }
                if (operacao == 4) {
                    removeInicioDeque(&deque, &guardaValor[cont]);
                    cont++;
                }
                if (operacao == 5) {
                    removeFimDeque(&deque, &guardaValor[cont]);
                    cont++;
                }
            }
            scanf("%d", &operacao);
            if (operacao == 6) {
                for (int j=0; j<cont; j++) {
                    printf("%d\n", guardaValor[j]);
                }     
                liberaDeque(&deque);
            }
        }
    }

    return 0;
}