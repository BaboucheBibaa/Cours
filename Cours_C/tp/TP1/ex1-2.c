#include <stdio.h>
#include <stdlib.h>

int main() {
    int val1, val2, val3;
    int tmp;
    printf("Entrez trois entiers : ");
    scanf("%d %d %d", &val1, &val2, &val3);
    if (val1 > val2 && val1 > val3){
        printf("La plus grande valeur est %d\n", val1);
        return 0;
    } else if (val2 > val1 && val2 > val3){
        printf("La plus grande valeur est %d\n", val2);
        return 0;
    }
    printf("La plus grande valeur est %d\n", val3);
    return 0;
}
