#include <stdio.h>
int main()
{
    printf("%lu\n", sizeof(int));
    if (sizeof(int) < -1)
        printf("Bizarre, bizarre ...\n");
    else printf ("Tout semble normal\n");
}
/*Note: Si on fait x-- dans la fonction sizeof, cela n'est pas pris en compte. Si on fait sizeof(x--) et x=11 avant l'appel de sizeof, x sera tjrs égal à 11.

Réponse à la question: sizeof renvoie une valeur de type size_t, donc un entier non signé (positif uniquement), or, ici on le compare avec un entier signé (-1)
Donc ici, il est sûrement question de conversion d'un type signé en type non signé afin de pouvoir comparer les deux entre eux
Sauf que -1 en unsigned se transforme en une valeur positive immense (souvent la valeur maximale du type.)

-> si le type non signé peut représenter toutes les valeurs du type signé, alors le int est converti en unsigned.

Sinon (cas courant : size_t est souvent un unsigned long), l’entier signé est converti en unsigned. (Source: ChatGPT, à voir la véracité de l'info)
*/