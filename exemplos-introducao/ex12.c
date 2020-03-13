#include <stdio.h>
#include <stdlib.h>

int main(void){

	int number;
	int i;
	int soma;

	scanf("%d", &number);

	for(i=0; i<number; i++){
		if (i % 2 != 0){
			soma += i;
		}
	}
	printf("%d", soma);

	return 0;
}
