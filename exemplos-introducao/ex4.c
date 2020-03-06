#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int number;
	int next;
	int back;

	printf("Entre com qualquer numero: ");
	scanf("%d", &number);

	next = number + 1;
	back = number - 1;
	
	printf("Antecessor: %d\n", back);
	printf("Sucessor: %d\n", next);

	return 0;
}
