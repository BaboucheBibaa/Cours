#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){ return a+b; }
int sub(int a, int b){ return a-b; }
int mul(int a, int b){ return a*b; }
int div_int(int a, int b){
    if (b==0){
        printf("division par 0\n");
        return 0;
    }
    return a/b;
}
int neg(int n){ return -n; }
int sqr(int n){ return n*n; }

typedef int (*op_bin_t)(int,int);
typedef int (*op_un_t)(int);

typedef enum {
    CONSTANTE,
    OP_BINAIRE, 
    OP_UNAIRE
} op_type_t;

typedef struct expression {
    op_type_t type;           
    void *value;              // int* (constante), op_bin_t (binaire), op_un_t (unaire)
    struct expression *gauche;
    struct expression *droit;
} expression_t;

// Fonction récursive d'évaluation
int calcule(expression_t *e) {
    switch (e->type) {
        case CONSTANTE:
            return *(int*)e->value;//ici retourne le résultat
        case OP_BINAIRE:
            return ((op_bin_t)e->value)(calcule(e->gauche), calcule(e->droit)); //value est un pointeur vers la fonction qui lui correspond, et va donc appliquer l'opération qui correspond sur gauche et droit.
        case OP_UNAIRE:
            return ((op_un_t)e->value)(calcule(e->gauche));//même chose qu'en haut mais ici pour une opération unaire (opposé ou carré)
        default:
            printf("Erreur de type dans l'expression\n");
            return 0;
    }
}

int main(){
    int a=5, b=10, c=2;

    expression_t constante_a, constante_b, constante_c;
    expression_t op1, op2, op3;

    // Constantes
    constante_a.type = CONSTANTE;
    constante_a.value = &a;
    constante_a.gauche = constante_a.droit = NULL; //la structure gère une constante donc pas d'opération à faire, donc null

    constante_b.type = CONSTANTE;
    constante_b.value = &b;
    constante_b.gauche = constante_b.droit = NULL;

    constante_c.type = CONSTANTE;
    constante_c.value = &c;
    constante_c.gauche = constante_c.droit = NULL; 

    // gère l'opérateur unaire
    op3.type = OP_UNAIRE;
    op3.value = neg;
    op3.gauche = &constante_c;
    op3.droit = NULL; //null car on gère juste la négation de la valeur dans la structure

    // Opérateur binaire: neg(c) * b
    op2.type = OP_BINAIRE;
    op2.value = mul; //opérateur multiplication
    op2.gauche = &op3;
    op2.droit = &constante_b;

    // Opérateur binaire: a + (neg(c) * b)
    op1.type = OP_BINAIRE;
    op1.value = add; //ici, addition.
    op1.gauche = &constante_a;
    op1.droit = &op2;

    printf("Expression : 5 + (-2 * 10) = %d\n", calcule(&op1));
}
