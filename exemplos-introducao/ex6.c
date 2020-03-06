#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int number;
	float result;

	printf("Informe um numero -> ");
	scanf("%d", &number);
	
	result = number / 3;

	printf("A terça parte deste numero é: %f\n", result);		

	return 0;
}
