#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x;
	int y;
	int soma;

	printf("Entre com dois numeros: \n-> ");
	scanf("%d %d", &x, &y);
	
	soma = x + y;
	printf("SOMA: %d\n", soma);

	return 0;
}
