#include <stdio.h>
#include <stdlib.h>

/*le programme est censé afficher l'adresse de r en premier
le résultat de r en second
0 ?*/

int main(){
    int *p, *r;
    int x=3;
    r=&x;
    printf("%p\n",r);
    x++;
    printf("%d\n", *r);
    *p=0;
    printf("%d\n", *p);
    return 0;
}

//cela affiche bien ce que j'ai supposé en haut