#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//ex 2.4-1
int rotationgauche3(int nb) {
    int nbits = sizeof(int) * CHAR_BIT; // nombre de bits d’un int
    int decale_gauche = (nb << 3);
    int decale_droite = (unsigned int)nb >> (nbits - 3);
    return decale_gauche | decale_droite;
}

//ex 2.4-2
int rotationgauche(int nb, int n) {
    int nbits = sizeof(int) * CHAR_BIT;
    int decale_gauche = (nb << n); //on généralise à n
    int decale_droite = (unsigned int)nb >> (nbits - n);
    return decale_gauche | decale_droite;
}

//ex2.4-1
int rotationgauche_char(unsigned char c, int n) {
    int nbits = sizeof(unsigned char) * CHAR_BIT; // = 8
    return (unsigned char)((c << n) | (c >> (nbits - n)));
}



int main() {
    unsigned char x = '7'; // exemple en hexadécimal
    int r = rotationgauche_char(x, 2);
    printf("Avant : %d\n", x);
    printf("Après : %d\n", r);
    return 0;
}
