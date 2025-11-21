#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

//COPIE DU TD4 MAIS SANS LE MAIN POUR EVITER LES CONFLITS

void print_liste(Liste* list){
    Liste* actuelle = list;
    while (actuelle != NULL){
        printf("%d\n", actuelle->valeur);
        actuelle = actuelle->suivant;
    }
}

Liste* push_front(Liste* elt, Liste** list){
    if (elt == NULL) return *list;

    elt->suivant = *list;
    *list = elt;

    return *list;
}
