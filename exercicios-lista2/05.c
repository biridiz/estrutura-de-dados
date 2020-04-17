#include <stdio.h>
#include <stdlib.h>

int main (void) {
    double antonio = 1.5;
    double carlos = 1.1;
    int i = 0;

    while (antonio >= carlos) {
        antonio += 0.2;
        carlos += 0.3;
        i++;
    }

    printf("%d\n", i);

    return 0;
}