#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texte[10];

    printf("Veuillez écrire une chaîne de caractères (max 9 caractères) : ");
    scanf("%9s", texte); // max à 9 caractères
    printf("Texte avant inversion : %s\n", texte);
    char texte_cpy[10];
    strcpy(texte_cpy, texte);
    int longueur = strlen(texte);
    for (int i = 0; i < longueur / 2; i++){
        char temp = texte[i];
        texte[i] = texte[longueur - i - 1]; // -1 pour éviter le '\0'
        texte[longueur - i - 1] = temp;
    }
    printf("Texte après inversion : %s\n", texte);
    
    //comparaison
    if (strcmp(texte_cpy,texte) == 0){
        printf("Le texte est un palindrome.\n");
    }
    else{
        printf("Le texte n'est pas un palindrome.\n");
    }
    return 0;
}