#include <stdio.h>
#include <stdlib.h>



int main(){
    char texte[100];
    printf("Veuillez écrire une chaîne de caractères : ");
    fgets(texte, sizeof(texte), stdin);
    char *p = texte; 
    while (*p != '\0'){
        if (*p != ' '){
            printf("%c", (*p + 3));
        }
        else{
            printf(" ");
        }
        p++;
    }
    printf("\n");
    return 0;
}