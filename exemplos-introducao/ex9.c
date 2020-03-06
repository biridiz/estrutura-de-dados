#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int x1;
	int y1;

	int x2;
	int y2;

	float distancia;
	
	printf("***** DISTÂNCIA ENTRE PONTOS *****\n");
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);

	distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));	
	
	printf("%.2f\n", distancia);

	return 0;
}
