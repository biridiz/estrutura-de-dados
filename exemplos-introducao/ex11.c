#include <stdio.h>
#include <stdlib.h>

int main(void){

	int number;
	int i;
	int res;

	scanf("%d", &number);

	for(i=0; i<11; i++){
		res = number * i;
		printf("%d x %d = %d\n", number, i, res);
	}

	return 0;
}
