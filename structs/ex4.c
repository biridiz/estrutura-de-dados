#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[41];
    double salario;
    Data *nascimento;
} Funcionario;

void imprime_data(Data *data) {
    printf("Dia: %d\n", data->dia);
    printf("Mes: %d\n", data->mes);
    printf("Ano: %d\n", data->ano);
}

int main() {
    Funcionario funcionario;
    Data *data;

    data = malloc(sizeof(Data));

    funcionario.nascimento = data;

    scanf(
        "%d %d %d",
        &funcionario.nascimento->dia,
        &funcionario.nascimento->mes,
        &funcionario.nascimento->ano
    );

    imprime_data(funcionario.nascimento);

    free(data);

    return 0;
}