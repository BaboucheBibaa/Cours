#include <stdio.h>

/* post incrémentation: la valeur est incrémentée après être utilisée (ancienne valeur utilisée)*/

int post_increment(int *i) {
    int old_value = *i;
    (*i)++;          
    return old_value; 
}

//la valeur est incrémentée avant d'être utilisée
int pre_increment(int *i) {
    (*i)++;             
    return *i;         
}

/*En post incrémentation, une copie de i est utilisée, donc cela coûte du stockage en plus*/
