#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int one_shirt = 100;
	int shirts;
	int input;
	int total_shirts;

	printf("Informe a quantidade de algodão: ");
	scanf("%d", &input);	

	shirts = input / one_shirt;
	total_shirts = shirts + ((shirts * 5) / 100);

	printf("Total de camisetas sem desperdicio: %d\n", shirts);
	printf("Total de camisetas incluindo o desperdicio: %d\n", total_shirts);

	return 0;
}
