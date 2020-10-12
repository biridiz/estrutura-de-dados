#include <stdio.h>

int main(){
    int i;
    int vet[6];

    for (i=0; i<6; i++) {
        scanf("%d", &vet[i]);
    }

    for (i=0; i<6; i++) {
        if (vet[i] % 2 == 0) {
            printf("Este é par: %d\nNa posição: %d\n", vet[i], i);
            printf("==================\n");
        }
    }

    return 0;
}