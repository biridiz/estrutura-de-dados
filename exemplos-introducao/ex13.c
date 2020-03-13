#include <stdio.h>
#include <stdlib.h>

int main(void){

	int number;
	int res;
	int i;

	scanf("%d", &number);
	for(i=0; i<number; i++){
		res += i;
	}

	printf("%d", res);

	return 0;
}
