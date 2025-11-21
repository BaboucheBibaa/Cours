
#include <stdio.h>
#include <stdlib.h>

void recursif(unsigned int n) {
    if (n > 1) {
        recursif(n / 2); 
    }
    putchar((n % 2) ? '1' : '0');
}
int main(void) {
    long input;
    unsigned int n;
    int choice;

    printf("Entrez un entier non-négatif: ");
    if (scanf("%ld", &input) != 1) {
        fprintf(stderr, "Lecture invalide.\n");
        return EXIT_FAILURE;
    }

    if (input < 0) {
        fprintf(stderr, "Veuillez saisir un entier non-négatif.\n");
        return EXIT_FAILURE;
    }

    recursif(input);
    putchar('\n');

return EXIT_SUCCESS;
}