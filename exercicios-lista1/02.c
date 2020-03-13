#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float pedaco_tecido = 11;
	float desperdicio = (pedaco_tecido / 100) * 15;
	int entrada;
	int qntd_calcas;
	float desperdicio_total;

	printf("Informe a quantidade de pedaços: ");
	scanf("%d", &entrada);
	
	qntd_calcas = entrada * 5;
	desperdicio_total = entrada * desperdicio;

	printf("Foram produzidas %d calças\n", qntd_calcas);
	printf("Com um desperdicio de %0.2f m²\n", desperdicio_total);
	
	return 0;
}
