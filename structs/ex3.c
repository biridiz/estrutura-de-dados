#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

int extrai_dia(Data *data) {
    return data->dia;
}

int compara_datas(Data *date_one, Data *date_two) {
    if (date_one == date_two) return 0;
    if (date_one > date_two) return 1;
    else return -1;
}

int main() {
    Data *data_one;
    Data *data_two;

    data_one = malloc(sizeof(Data));
    data_two = malloc(sizeof(Data));

    printf("Digite duas datas:\n");
    scanf("%d %d %d", &data_one->dia, &data_one->mes, &data_one->ano);
    scanf("%d %d %d", &data_two->dia, &data_two->mes, &data_two->ano);
    
    printf("O dia da primeira data-> %d\n", extrai_dia(data_one));
    printf("O dia da segunda data-> %d\n", extrai_dia(data_two));

    printf("Resultado da comparação^ -> %d\n", compara_datas(data_one, data_two));

    free(data_one);
    free(data_two);
    
    return 0;
}