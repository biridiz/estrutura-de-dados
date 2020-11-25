#include <stdio.h>
#include <stdlib.h>

typedef struct val {
    int valor;
    struct val *next;
    struct val *prev;
} ListaInt;

void limpa_toda_lista(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));

    while (lista != NULL) {
        aux = lista;
        lista = lista->prev;
        free(aux);
    }
}

void imprime_lista(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));

    for (aux=lista; aux != NULL; aux=aux->next) {
        printf("%d\n", aux->valor);
    }
}

ListaInt* cria_lista(int n) {
    ListaInt *primeiro, *ultimo, *aux;
    int i;

    primeiro = malloc(sizeof(ListaInt));
    primeiro->valor = 0;
    primeiro->next = NULL;
    primeiro->prev = NULL;
    ultimo = primeiro;
    
    for (i=1; i<n; i++) {
        aux = malloc(sizeof(ListaInt));
        aux->valor = i*(n);
        aux->next = NULL;
        aux->prev = NULL;

        if (primeiro) {
            aux->prev = ultimo;
            ultimo->next = aux;
            ultimo = aux;
        }
    }
    return ultimo;
}

void imprime_maior_e_menor(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));
    int maior = 0;
    int menor = 0;

    for (aux=lista; aux != NULL; aux=aux->prev) {
        if (aux->valor > maior) {
            maior = aux->valor;
        }
        if (aux->valor < menor) {
            menor = aux->valor;
        }
    }

    printf("Maior: %d\nMenor: %d\n", maior, menor);
}

void busca_menor_troca_primeiro(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));
    int menor = 0;

    for (aux=lista; aux != NULL; aux=aux->next) {
        if (aux->valor < menor) {
            menor = aux->valor;
        }
    }
    for (aux=lista; aux != NULL; aux=aux->prev) {
        if (aux->prev == NULL) {
            aux->valor = menor;
        }
    }
}

void busca_maior_troca_ultimo(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));
    int maior = 0;

    for (aux=lista; aux != NULL; aux=aux->next) {
        if (aux->valor < maior) {
            maior = aux->valor;
        }
    }
    for (aux=lista; aux != NULL; aux=aux->next) {
        if (aux->next == NULL) {
            aux->valor = maior;
        }
    }
}

ListaInt* copia_lista(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));
    ListaInt *copia = malloc(sizeof(ListaInt));

    copia->valor = 0;
    copia->next = NULL;
    copia->prev = NULL;

    for (aux=lista; aux != NULL; aux=aux->next) {
        aux->prev = copia;
        copia->next = aux;
        copia = aux;
    }

    return copia;
}

double media(ListaInt *lista) {
    ListaInt *aux = malloc(sizeof(ListaInt));
    int cont = 0, ac;
    double media;

    for (aux=lista; aux != NULL; aux=aux->prev) {
        ac += aux->valor;
        cont ++;
    }

    media = ac / cont;
    return media;
}

int main() {
    int n;
    ListaInt *lista;

    printf("Tamanho da lista: ");
    scanf("%d", &n);

    lista = cria_lista(n);

    imprime_lista(lista);

    imprime_maior_e_menor(lista);

    printf("%.2lf\n", media(lista));

    imprime_lista(copia_lista(lista));

    limpa_toda_lista(lista);

    return 0;
}