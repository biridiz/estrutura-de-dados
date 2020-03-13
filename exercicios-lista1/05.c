#include <stdio.h>
#include <stdlib.h>

int main(void){

	int horas;
	float valor_hora;
	float salario_bruto;
	float salario_liq;
	float inss;
	float imposto;
	float adiantamento;
	
	printf("Informe a quantidade de horas trabalhadas: ");
	scanf("%d", &horas);

	printf("Informe o valor por hora: ");
	scanf("%f", &valor_hora);

	printf("Informe o valor em adiantamentos: ");
	scanf("%f", &adiantamento);

	salario_bruto = horas * valor_hora;
	inss = (salario_bruto / 100) * 8;
	imposto = (salario_bruto / 100) * 12;
	salario_liq = salario_bruto - (inss + imposto + adiantamento);
	
	printf("Salário liquido = %.2f\n", salario_liq);

	return 0;
}
