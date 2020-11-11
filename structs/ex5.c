#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor;

Vetor soma(Vetor v1, Vetor v2) {
    Vetor vetor;
    vetor.x = v1.x + v2.x;
    vetor.y = v1.y + v2.y;
    vetor.z = v1.z + v2.z;
    return vetor;
}

int main() {
    Vetor vetor_one = {3, 5.0, 7.6};
    Vetor vetor_two = {2, 9.4, 0};
    Vetor vetor;

    vetor = soma(vetor_one, vetor_two);

    printf("%lf %lf %lf\n", vetor.x, vetor.y, vetor.z);

    return 0;
}