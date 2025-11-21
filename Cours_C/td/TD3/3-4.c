#include <stdio.h>
#include <stdlib.h>

int b[3][5];
int *a=*b, c; //a vaut la première valeur du tableau b, c initalisé à une valeur random
for (c=0; c<15; *a++=c++); //c = 15, a vaut le dernier élément du tableau b
**b=15; 
**(b+1)=16; 
*(b[0]+1)=17; 
*(*b+8)=18; 
*(b[1]+2)=19;
*(*(b+1)+5)=20; 
*(b[2]+3)=21; 
*(*(b+2)+2)=22;