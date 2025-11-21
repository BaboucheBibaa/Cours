#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long int factorielle(int n){
    unsigned long int total = 1;
    for (int i = 1; i<=n; i++){
        total*=i;
    }
    return total;
}

unsigned long int factorielle_recursive(int n){
    if (n<=1){
        return 1;
    }
    return n*factorielle_recursive(n-1);
}

int main(){
    unsigned long int res;
    int valeur;
    printf("Veuillez saisir une valeur pour la factorielle\n");
    scanf("%d",&valeur);
    res = factorielle(valeur);
    if (res >= ULONG_MAX || res == 0){
        printf("Dépassement de capacité !\n");
        return 0;
    }
    printf("Résultat: %lu\n", res);
    return 0;
}