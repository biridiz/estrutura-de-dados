#include <stdio.h>
#include <stdlib.h>

int main(void){

	int x, y, z;

	x = y = 10;
	printf("%d %d %d\n", x, y, z);

	z = ++x;
	printf("%d %d %d\n", x, y, z);

	x = -x;
	printf("%d %d %d\n", x, y, z);

	y++;
	printf("%d %d %d\n", x, y, z);

	x = x + y - (z--);
	printf("%d %d %d\n", x, y, z);


	return 0;
}
