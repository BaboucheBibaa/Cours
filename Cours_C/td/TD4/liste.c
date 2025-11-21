#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
    int valeur;
    struct liste* suivant;
} Liste;

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

int main(){
    Liste* list = NULL;

    Liste* e1 = malloc(sizeof(Liste));
    e1->valeur = 10;

    Liste* e2 = malloc(sizeof(Liste));
    e2->valeur = 20;

    Liste* e3 = malloc(sizeof(Liste));
    e3->valeur = 30;

    push_front(e1,&list);
    push_front(e2,&list);
    push_front(e3,&list);

    print_liste(list);
}