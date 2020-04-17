#include <stdio.h>
#include <stdlib.h>


int main (void) {
    int x, y;
    int r;
    int op;

    do {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &op);
        if (op == 1) r = (x + y);
        if (op == 2) r = (x - y);
        if (op == 3) r = (x * y);
        if (op == 4) r = (x / y);
        if (op == 5) r = (x % y);
        printf("%d\n", r);
    } while (op != 0);

    return 0;
}