#include <stdio.h>
#include <stdlib.h>


int main(){
    char texte[100];
    printf("Veuillez écrire une chaîne de caractères : ");
    fgets(texte, sizeof(texte), stdin); //fgets au lieu de scanf pour permettre les espaces et donc la saisie de phrases
    char *p = texte;

    while (*p != '\0'){
        if (*p != 'e'){
            printf("%c", *p);
        }
        p++;
    }

    return 0;
}