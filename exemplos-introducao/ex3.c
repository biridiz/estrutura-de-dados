#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int x;
	int y;
	int z;
	float media;

	printf("Entre com 3 valores:\n-> ");
	scanf("%d %d %d", &x, &y, &z);
	
	media = (x + y + z) /3;

	printf("A media eh: %f\n", media);	

	return 0;
}
