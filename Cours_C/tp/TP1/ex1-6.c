#include <stdio.h>
#include <stdlib.h>

int log2_int(unsigned int n) {
    int result = -1;
    while (n > 0) {
        n >>= 1;
        result++;
    }
    return result;
}

int main() {
    unsigned int x;

    printf("Entrez un entier positif non nul : ");
    if (scanf("%u", &x) != 1 || x == 0) {
        printf("Erreur : vous devez entrer un entier strictement positif.\n");
        return 1;
    }
    printf("log2(%u) (partie entière) = %d\n", x, log2_int(x));

    return 0;
}
