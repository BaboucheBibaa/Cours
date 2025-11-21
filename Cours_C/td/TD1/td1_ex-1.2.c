#include <stdio.h>

int mul2(int a) { return a*2; }
int div2(int a) { return a/2; }
int main(int argc, char* argv[]) {
int a = 8;
printf("%d %d %d %d %d\n", a, mul2(a), div2(a), a=mul2(a), a=div2(a));
}

//affiche : 8 16 4 8 8 