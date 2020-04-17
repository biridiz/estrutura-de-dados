#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int x;
    int y;
    int r;
    
    scanf("%d %d", &x, &y);
    for (int i=0; i<y; i++) {
        r += x;
    }
    printf("%d\n", r);

    return 0;
}