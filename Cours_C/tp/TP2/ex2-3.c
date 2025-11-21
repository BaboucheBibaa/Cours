#include <stdio.h>

void div_2_bit_a_bit(int n){
    int quotient = n >> 1;    // Division entière par 2
    int reste = n & 1;        // xxxx xxx1 & 0000 0001 renverra 1 donc impair par exemple

    printf("Quotient : %d\n", quotient);
    printf("Reste    : %d\n", reste);
}

void div_4_bit_a_bit(int n){
    int quotient = n >> 2; 
    int reste = n & 3; //xxxx xx11 & 0000 0011 vaudra 3

    printf("Quotient : %d\n", quotient);
    printf("Reste    : %d\n", reste);
}

int main() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    printf("Division par 2 :\n");
    div_2_bit_a_bit(n);
    printf("\nDivision par 4 :\n");
    div_4_bit_a_bit(n);

    return 0;
}
