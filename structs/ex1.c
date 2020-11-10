#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int extrai_dia(Data data) {
    return data.dia;
}

int compara_datas(Data *date_one, Data *date_two) {
    if (date_one == date_two) return 0;
    if (date_one > date_two) return 1;
    else return -1;
}

int main() {
    
    Data data = {25, 8, 1997};
    Data ferias = {28, 12, 2020};
    int dia;

    dia = extrai_dia(data);
    printf("O dia é %d\n", dia);
    printf("%d\n", compara_datas(&data, &ferias));

    return 0;
}