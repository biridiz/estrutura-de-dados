#include <stdio.h>

int main() {
    int i, j, linha, coluna;
    int maior = 0;
    int mat[4][4];

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                linha = (i + 1);
                coluna = (j + 1);
            }
        }
    }
    printf("O maior é: %d\nNa linha: %d\nNa coluna: %d\n", maior, linha, coluna);

    return 0;
}