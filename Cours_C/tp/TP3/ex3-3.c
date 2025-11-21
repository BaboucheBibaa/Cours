#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texte[1000];
    printf("Veuillez écrire une chaîne de caractères : ");
    fgets(texte, sizeof(texte), stdin);
    int longueur = strlen(texte);
    printf("Version 1: Longueur de texte avec strlen: %d\n", longueur-1);
    
    int compteur = 0;
    for (int i = 0; texte[i] != '\0';i++){
        compteur++;
    }
    printf("Version 2: Longueur de texte avec boucle for: %d\n", compteur-1);

    char *p = texte;
    compteur = 0;
    while (*p != '\0'){
        compteur++;
        p++;
    }
    printf("Version 3: Longueur de texte avec boucle while et pointeur: %d\n", compteur-1);
}