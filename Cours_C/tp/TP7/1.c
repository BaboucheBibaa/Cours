#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    float val;

    printf("Saisissez un nombre: ");
    scanf("%f",&val);
    double intPart;
    double dec = modf(val, &intPart);
    printf("Partie entière: %g\n", intPart);

    int intPartInt = val;
    printf("Partie entière v2: %d\n", intPartInt);

    val = floor(val);
    printf("Partie entière v3: %g\n", val);
}