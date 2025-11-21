#include <stdio.h>

int main(){
    unsigned int a = 1;
    unsigned int b = 0xFFFFFFFE;
    unsigned int c = a + b;
    printf("%u\n", c);
    return 0;
}

/* 2-2-1 Output: -1

Car 0xFFFFFFFE = 11111111 11111111 11111111 11111110 en notation signée en C (ici en int), cela vaut -2, donc 1 - 2 = -1.

2-2-2: Output: 4294967295

Car cette fois-ci, on prend la valeur en notation non signée, donc 2^32 - 1*/