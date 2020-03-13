#include <stdio.h>
#include <stdlib.h>

int main(void){

	float base;
	float aresta_direita;
	float aresta_esquerda;
	float perimetro;

	printf("***** Perimetro de um trinagulo *****\n");

	printf("Informe o valor da base: ");
	scanf("%f", &base);

	printf("Informe a aresta direita: ");
	scanf("%f", &aresta_direita);

	printf("Informe a aresta esquerda: ");
	scanf("%f", &aresta_esquerda);
	
	perimetro = (base + aresta_direita + aresta_esquerda);

	printf("Perimetro = %.2f\n", perimetro);		

	return 0;
}
