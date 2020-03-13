#include <stdio.h>
#include <stdlib.h>

int main(void){

	int calorias_horas;
	int calorias;
	float horas;

	printf("Informe quantas calorias serão gastas por hora: ");
	scanf("%d", &calorias_horas);

	printf("Informe quantas calorias pretende queimar: ");
	scanf("%d", &calorias);

	horas = calorias / calorias_horas;

	printf("Você vai precisar de %.1fh para alcançar seu objetivo\n", horas);

	return 0;
}
