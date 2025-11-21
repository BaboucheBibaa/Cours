typedef struct liste {
    int valeur;
    struct liste* suivant;
} Liste;

void print_liste(Liste* list);
Liste* push_front(Liste* elt, Liste** list);
