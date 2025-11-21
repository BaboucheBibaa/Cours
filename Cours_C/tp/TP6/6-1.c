#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int estTriee = 1;
    int ancien, actuel;
    for (int i = 2; i < argc; i++){
        ancien = atoi(argv[i-1]);
        actuel = atoi(argv[i]);
        if (ancien > actuel){
            estTriee = 0;
        }
    }
    estTriee % 2 == 0 ? printf("Non triée\n") : printf("Triée\n");
    return 0;
}