#include <stdio.h>
#include <stdlib.h>

int soma(int n) {
    if (n == 0)
        return 0;
    return (n+soma(n-1));
}

int main() {

    printf("%d\n", soma(5));

    return 0;
}