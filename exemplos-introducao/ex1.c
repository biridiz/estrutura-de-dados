#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float altura;
	char sexo;
	float peso_ideal;

	printf("Informe sua altura: ");
	scanf("%f", &altura);
	
	printf("Informe seu sexo: ");
	scanf("%c", &sexo);
	
	peso_ideal = (72.7 * altura) - 58;
	printf("\nSexo: %c\nPeso ideal: %f \n", sexo, peso_ideal);
	
	return 0;
}
