#include <stdio.h>
#include <stdlib.h>


int a_p(float media){
	if (media < 6) { return 0; }
	else { return 1; }
}

void print(float media){
	printf("\n%.1f\n", media);
	if (a_p(media) == 1) { printf("Aproved"); }
	else { printf("Reproved"); }
	printf("\n****************\n");
}

float media(float notas, int qntd_notas){
	float media;

	media = notas / qntd_notas;

	return media;
}

void read(int qntd_alunos, int qntd_notas){
	float notas;
	float aux;

	for(int i=0; i<qntd_alunos; i++) {
		notas = 0;
		aux = 0;
		for(int j=0; j<qntd_notas; j++) {
                	scanf("%f", &aux);
                	notas += aux;
		}
		print(media(notas, qntd_notas));
        }

	return;
}

int main(void){

	int qntd_alunos;
	int qntd_notas;

	scanf("%d", &qntd_alunos);
	scanf("%d", &qntd_notas);
	printf("\n");

	read(qntd_alunos, qntd_notas);

	return 0;
}
