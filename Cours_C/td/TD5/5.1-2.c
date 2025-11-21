#include <stdio.h>
#include <stdlib.h>

int main(){
    int taille;
    int i = 0;
    int valeur;
    int *tab;
    printf("Veuillez saisir une taille pour votre tableau:");
    scanf("%d",&taille);
    tab = (int*)malloc(taille * sizeof(int)); //taille du tableau multiplié par la taille d'un entier pour connaître la taille du tableau

    while (i != taille){
        printf("Veuillez saisir une valeur: ");
        scanf("%d",&valeur);
        tab[i] = valeur;
        i++;
    }


    for (int i = 0; i < taille; i++){
        printf("valeur: %d\n", tab[i]);
    }

    free(tab);
    return 0;
}