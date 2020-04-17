#include <stdio.h>
#include <stdlib.h>


void big(double bigger[]) {
    double out = 0;
    double list[5];

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (bigger[i] > bigger[j]) {
                out = bigger[i];
            }
        }
        for (int l=0; l<5; l++){
            if (out > list[l+1]) {
                list[l] = out;
            }
            else {
                list[i+1] = out;
            }
        }
    }
    for (int k=0; k<5; k++){
        printf("%.0f\n", list[k]);
    }
    
}

double fat(int soma) {
    double fat;
    int i = 2;

    fat = soma * (soma - 1);

    while (i != soma) {
        fat *= (soma - i);
        i++;
    }

    return fat;
}

int sum(int algarismos[]){
    int soma;

    soma = algarismos[0] + algarismos[1] + algarismos[2];

    return soma;
}

void read() {
    int numero;
    int algarismos[3];
    double bigger[5];

    for (int i=0; i<5; i++) {
        scanf("%d", &numero);
        algarismos[0] = numero / 100;
        algarismos[1] = numero % 100;
        algarismos[1] = algarismos[1] / 10;
        algarismos[2] = numero % 10;
        bigger[i] = fat(sum(algarismos));
    }
    big(bigger);

    return;
}

int main (void) {
    read();

    return 0;
}