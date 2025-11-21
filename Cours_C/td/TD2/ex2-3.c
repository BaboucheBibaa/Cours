#include <stdio.h>
#include <stdlib.h>

int maximum(int tableau[], int N, int* maxi){
    int max = tableau[0];
    int indice = 0;
    for (int i = 1; i < N; i++){
        if (max < tableau[i]){
            max = tableau[i];
            indice = i;
            *maxi = tableau[i];
        }
    } 
    return indice;
}

int main(){
    int tab[5] = {1,2,8,4,5};
    int maxi;
    int indice = maximum(tab, 5, &maxi);
    printf("%d\n", indice);
    printf("val max: %d\n", maxi);
    return 0;
}