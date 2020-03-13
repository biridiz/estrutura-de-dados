#include <stdio.h>
#include <stdlib.h>

int main(void){

	int caractere;
	float velocidade;
	float res;
	
	printf("Informe quantos caracteres tem o texto: ");
	scanf("%d", &caractere);
	
	printf("Informe a velocidade em caracteres por segundo: ");
	scanf("%f", &velocidade);

	res = (caractere / velocidade) / 60;
	printf("Tempo estimado em minutos: %0.1f\n", res);

	return 0;
}
