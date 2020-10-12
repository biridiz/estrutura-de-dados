#include <stdio.h>


int main(){
    int i, aux; 
    int maior = 0;
    int menor = 0;
    int vet[5];

    for (i=0; i<5; i++) {
        scanf("%d", &vet[i]);
    }

    printf("==================\n");

    for (i=0; i<5; i++) {
        aux = vet[i];
        if (maior < aux) {
            maior = aux;
        }
        if (menor > aux || menor == 0) {
            menor = aux;
        }
    }

    printf("Maior: %d\nMenor: %d\n", maior, menor);
    
    return 0;
}