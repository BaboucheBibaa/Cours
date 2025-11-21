#include <stdio.h>
#include <stdlib.h>

char max_carac(char mot[]){
    char *p = mot;
    char max = mot[0];
    while (*p != '\0'){
        if (max < *p){
            max = *p;
        }
        p++;
    }
    return max;
}

int main(){

    char mot[10] = "bonjour";
    char max = max_carac(mot);
    printf("%c\n", max);
}