#include <stdio.h>

int main(){
    int i;
    int vetor[] = {1,2,3,3,4,6,6,7,5,7,1,3};

    for (i=0; i<12; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}