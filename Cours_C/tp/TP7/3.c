#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float* trig_vals(float degres){
    float* tab = (float*)malloc(3*sizeof(float));
        if (!tab) {
        perror("malloc");
        exit(1);
    }

    float rad = degres * (M_PI / 180.0);
    tab[0] = sin(rad);
    tab[1] = cos(rad);
    tab[2] = tan(rad);
    return tab;
}

float hypothenuse(float longueur1, float longueur2){
    float hyp = sqrt(pow(longueur1,2) + pow(longueur2,2));
    return hyp;

}

//arc de cercle calcul = theta*(2piR/360) theta en radians
float arc_cercle(float angle, float rayon){
    float rad = angle * (M_PI / 180);
    float valeur_arc_cercle = rad*rayon;
    return valeur_arc_cercle;
}

int main(){
    float* valeurs = trig_vals(60);
    float longueur1 = 20; 
    float longueur2 = 20;
    float hyp = hypothenuse(longueur1, longueur2);
    printf("L'hypothenuse est: %.2f\n", hyp);
    printf("sin = %f, cos = %f, tan = %f\n", valeurs[0], valeurs[1], valeurs[2]);
    free(valeurs);
    float angle=60;
    float rayon = 3.0;
    float arc=arc_cercle(angle,rayon);
    printf("La valeur de l'arc de cercle est de: %.2f\n", arc);
    return 0;
}