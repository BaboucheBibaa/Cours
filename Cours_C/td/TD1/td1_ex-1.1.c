#include <stdio.h>
int main(int argc, char* argv[]) {
int a, b, c;
if (a = b = c = 0) printf("true\n"); else printf("false\n");// renvoie false a=b=c=0
if (++a) printf("true\n"); else printf("false\n");//a=1 renvoie true
if (!a) printf("true\n"); else printf("false\n");//a=1 renvoie false (!a)
if (~a) printf("true\n"); else printf("false\n");//a=1 différent de 0 donc vrai
if (a--) printf("true\n"); else printf("false\n");//vrai car post-décrémentation (a=0)
if ((b=a)) printf("true\n"); else printf("false\n");//a=b=0, false, pas un test d'égalité
if ((c=b)==a) printf("true\n"); else printf("false\n");//a=b=c=0 renvoie true
if (a++ & ++b | c++) printf("true\n"); else printf("false\n");//a=b=c=1 mais a et c post-incrémentés, a & b vaut 0, 0 | 0 vaut false
if (a-- & --b | c--) printf("true\n"); else printf("false\n");//a=b=c=0 mais c = 1 donc 0 | 1 renvoie vrai
if (a-- && --b || c--) printf("true\n"); else printf("false\n"); //a=c=-1  et b=0, 0 && -1 = faux et faux ou faux = faux (b est ignoré car a-- est post décrémenté donc faux)
if ((a=b) & (c=b)) printf("true\n"); else printf("false\n"); //a=c=b=0, renvoie faux
if ((a==b) && (c==b)) printf("true\n"); else printf("false\n");//a=c=-1 b=0 test d'égalité, renvoie true
if (a ^ b || c ^ b) printf("true\n"); else printf("false\n");//a=c=-1 b=0 xor donc faux ou faux = faux
if (a = a==b) printf("true\n"); else printf("false\n"); //a = 1, c=-1 b=0 et donc renvoie vrai
if (c = a||b) printf("true\n"); else printf("false\n");//a=1, b=0, c=1 donc renvoie vrai
if (a << 4) printf("true\n"); else printf("false\n");//a=1,b=0 c=1 donc renvoie vrai
if (a >> 2) printf("true\n"); else printf("false\n");//a=1, b=0, c=1, on met des 0 à gauche donc le 1 tout à droite part
if (a <<= 4) printf("true\n"); else printf("false\n");//a=16, b=0, c=1, renvoie vrai
if (a >>= 2) printf("true\n"); else printf("false\n");//a=4,b=0,c=1, renvoie vrai
}


