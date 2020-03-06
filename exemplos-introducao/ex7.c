#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float celsius;
	float f;

	printf("Informe uma temperatura em graus Celsius: ");
	scanf("%f", &celsius);

	f = (9/5) * (celsius) + 32;
	
	printf("Temperatura em Fahrenheit: %f\n", f); 

	return 0;
}
