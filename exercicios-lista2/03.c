#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int n;
    int i = 1;
    int cont = 0;

    scanf("%d", &n);
    while (i <= n) { 
        if ((n % i) == 0) {
            cont ++;
        }
        i++;
    }
    if (cont == 2 || n == 1) {
        printf("É primo!\n");
    }
    else {
        printf("Não é primo!\n");
    }

    return 0;
}