#include <stdio.h>
/*Fonctionne pas dans la version du TD car on attend un type int **, et on lui envoie un int*[3], donc erreur*/

//version corrigée: 
void affichage(int size, int mat[size][size])
{
    int i,j;
    for (i=0; i < size; i++){
        for(j=0; j < size; j++){
            printf("%d|", mat[i][j]);
        }
    printf("\n");
    }
}
int main(){
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    affichage(3,mat);
}
