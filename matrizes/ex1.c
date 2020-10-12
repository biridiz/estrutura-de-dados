#include <stdio.h>S

int main() {
    int mat[4][4];
    int i, j;
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i=0; i<4; i++) {
        printf("\n");
        for (j=0; j<4; j++) {
            if (i == j) {
                printf("| %d |", mat[i][j]);
            }
            else {
                printf("| * |");
            }
        }
    }
    printf("\n");

    return 0;
}