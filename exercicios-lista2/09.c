#include <stdio.h>
#include <stdlib.h>


int main(void){
    double media = 100000;
    double litros_ano;
    double preco_atual = 2.93;
    double preco_final, aux;

    scanf("%.2f", &litros_ano);
    if (litros_ano <= media) {
        aux = (preco_atual / 100) * 20;
        preco_final = preco_atual + aux;
    }
    else {
        aux = (preco_atual / 100) * 12;
        preco_final = preco_atual + aux;
    }
    printf("%.2f\n", preco_final);

    return 0;
}