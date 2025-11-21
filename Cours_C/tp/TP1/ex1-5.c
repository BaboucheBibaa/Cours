#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val = 0;
    int compteur = 0;
    printf("Veuillez saisir une valeur (ctrl+D pour sortir)\n");
    while (scanf("%d",&val) != EOF){
        printf("Veuillez saisir une valeur (ctrl+D pour sortir)\n");
        if ((val%2) == 0){
            compteur+=val;
        }
    }
    printf("La somme des entiers pairs saisis est: %d\n", compteur);  
    return 0;
}