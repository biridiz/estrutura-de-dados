#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int machine_one = 1;
	int machine_two = 3;
	float machine_tree = 2.5;
	int days;
	float res;

	printf("Informe a quantidade de dias: ");
	scanf("%d", &days);

	res = (machine_one + machine_two + machine_tree) * days;

	printf("Numero de postes = %0.2f\n", res);

	return 0;
}
