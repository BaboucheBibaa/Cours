#include <stdio.h>
#include <stdlib.h>


int main(){
    int nb_faces;
    printf("Veuillez saisir un nombre de faces pour votre dé: ");
    scanf("%d", &nb_faces);
    int val_rand = rand() % (nb_faces+1);
    printf("Vous êtes tombés sur le chiffre: %d\n", val_rand);
}