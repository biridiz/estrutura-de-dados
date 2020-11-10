#include <stdio.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;

Complexo cria_complexo(double real, double imaginario) {
    Complexo complexo = {real, imaginario};
    return complexo;
}

Complexo soma_complexo(Complexo *f, Complexo *s) {
    Complexo complexo;
    complexo.real = f->real + s->real;
    complexo.imaginario = f->imaginario + s->imaginario;
    return complexo;
}

int main(){

    Complexo one;
    Complexo two;
    Complexo complexo;
    double real = 5.5;
    double imaginario = 9.9;

    one = cria_complexo(real, imaginario);
    two = cria_complexo(real+1, imaginario-2);
    
    complexo = soma_complexo(&one, &two);
    printf("%.2lf %.2lf\n", complexo.real, complexo.imaginario);

    return 0;
}