#include <stdio.h>
#include <stdlib.h>

void maximum(int N, int M, int tableau[N][M], int* maxi, int* imax, int* jmax){
    int max = tableau[0][0];
    for (int i = 1; i < N; i++){
        for (int j = 1; j < M; j++){
            if (max < tableau[i][j]){
                max = tableau[i][j];
                *imax = i;
                *jmax = j;
                *maxi = tableau[i][j];
            }
        }
    }
}

int main(){
    int N = 3;
    int M = 4;
    int imax, jmax, max;
    int tableau[3][4] = {
        {1, 5, 2, 7},
        {3,92, 0, 4},
        {8, 6, 2, 10}
    };    
    maximum(N,M,tableau,&max, &imax, &jmax);
    printf("max = %d\n", max);
    printf("imax = %d\n", imax);
    printf("jmax = %d\n", jmax);
}

/* on peut pas renvoyer plusieurs valeurs dans une fonction, donc on peut soit renvoyer un tableau
soit passer des valeurs en paramètre et les modifier via un passage par adresse*/