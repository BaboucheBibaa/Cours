#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, compteur=0;
    for (i; i <= 10; i++){
        compteur += i;
        printf("%d\n",i);
    }
    printf("la somme des dix premiers entiers naturels est %d\n",compteur);
    return 0;
}