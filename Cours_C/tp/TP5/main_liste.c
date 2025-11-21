#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

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