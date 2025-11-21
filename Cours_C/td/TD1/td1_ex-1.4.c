#include <stdio.h>
#include <stdlib.h>
/*int main(int argc, char* argv[]) {
int i;
for (i=0; i<5; ++i) {
int j = i + 1;
printf("i: %d j: %d\n", i, j);
}
printf("Valeurs finales: %d, %d\n", i, j);
return EXIT_SUCCESS;
}*/

//erreur car j n'est pas défini en dehors de la boucle for

/*int main(int argc, char* argv[]) {
    int i;
    for (i=0; i<5; ++i) {
        int j;
        for (j=0; j<5; ++j) {
            int k;
            for (k=0; k<5; ++k) {
                printf("%d ", i+j+k);
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}*/

/*0 1 2 3 4 1 2 3 4 5 2 3 4 5 6 3 4 5 6 7 4 5 6 7 8
1 2 3 4 5 2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9
2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10
3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10 7 8 9 10 11
4 5 6 7 8 5 6 7 8 9 6 7 8 9 10 7 8 9 10 11 8 9 10 11 12
*/

int a = 100, b = 1000;
int fun1(int a) {
    a++;
    return a;

}
int fun2(int a) {
    a += b;
    return a;
}
int fun3(int a) {
    int b;
    a += b;
    return a;
}
int main(int argc, char* argv[]) {
    int a;
    printf("a = %d\n", a);//valeur aléatoire
    fun1(a);//pas un passage par référence donc ne modifie pas a
    printf("a = %d\n", a);
    a = 2; //initialisation de a
    a = fun2(a); //cette fois-ci, a est modifié
    printf("a = %d\n", a); //donc nouvelle valeur de a
    a = fun3(b);
    printf("a = %d\n", a);
    return EXIT_SUCCESS;
}
