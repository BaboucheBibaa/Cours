#include <stdio.h>
int main(int argc, char* argv[]) {
short s;
int i;
long l;
unsigned short us;
unsigned int ui;
unsigned long ul;
float f;
double d;
s = 32768;
printf("valeur: %d\n", s);//limite des shorts: -32768 à 32767 donc revient à -32768
s = 65536;
printf("valeur: %d\n", s);//toujours un short, donc 65536-65536=0
us = 32768;
printf("valeur: %d\n", us);//limite des unsigned short: 0 à 65535 donc affiche 32768
us = 65536;
printf("valeur: %d\n", us);//ici ça affiche 0
us = 70000;
printf("valeur: %d\n", us);//ici ça affiche 70000-65536=4464
i = 2147483647;
printf("valeur: %d\n", i);//limite des int: -2147483648 à 2147483647 donc affiche 2147483647
s = i;
printf("valeur: %d\n", s);//ici ça affiche -1 car 2147483647-65536*32768=-1
us = i;
printf("valeur: %d\n", us);//ici ça affiche 65535 car 2147483647-65536*32768=65535
f = 10.1;
f *= 100;
printf("valeur: %f\n", (f));//10.1 * 100 = 1010.000000 mais avec soucis de précision
f = 10.1;
i = 100;
i *= f;
printf("valeur: %d\n", i);//10.1 * 100 = 1010.000000 mais i est un int donc affiche 1010
i = 100;
i *= (int) f;
printf("valeur: %d\n", i);//cast en int donc 10*100 = 1000

ui = 0;
for (i=0; i<100; ++i)
ui += f;//cast sur un int donc 10+10... 100 fois = 1000
printf("valeur: %d\n", ui);
i = 10;
if (i<f) printf("%d < %f\n", i, f); else printf("%d >= %f\n", i, f);//comparaison vraie donc affiche 10 < 10.100000.
return 0;
}
