#include <stdio.h>


int main(){
    int i;
    int vet[5];
    for (i=0; i<5; i++) {
        scanf("%d", &vet[i]);
    }
    printf("==================\n");
    for (i=0; i<5; i++) {
        printf("%d\n", vet[i]);
    }
    return 0;
}