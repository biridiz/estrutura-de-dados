#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float salario_base = 1200.00;
	float comissao;
	float vendas;
	float total;

	printf("Informe em reais o valor das vendas: ");
	scanf("%f", &vendas);
	
	comissao = (vendas / 100) * 10;
	total = salario_base + comissao;
	
	printf("Seu salário base é: %.2f\n", salario_base);
	printf("O valor da comissão baseado nas vendas é: %.2f\n", comissao);
	printf("Valor total do salário bruto: %.2f\n", total);	

	return 0;
}
