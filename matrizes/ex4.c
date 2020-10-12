#include <stdio.h>

int main() {
    int i, j, prod;
    int mat[5][5];

    for (i=0; i<5; i++) {
        printf("\n");
        for (j=0; j<5; j++) {
            prod = (i * j);
            mat[i][j] = prod;
            printf("| %d |", mat[i][j]);
        }
    }
    printf("\n");

    return 0;
}