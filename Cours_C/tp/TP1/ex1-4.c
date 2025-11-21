#include <stdio.h>
#include <stdlib.h>

int main(){
    float val;
    float moyenne = 0.0;
    int i = 1;
    printf("Veuillez saisir une valeur\n");
    scanf("%f",&val);
    float sum = val;
    while (val != -1){
        printf("Veuillez saisir une valeur (-1 pour sortir)\n");
        scanf("%f",&val);
        if (val != -1){
            sum+=val;
            i++;
        }
    }
    moyenne = sum/i;
    printf("%f\n", moyenne);
    return 0;
}
