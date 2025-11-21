#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 26

void init_vigenere(char table[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            table[i][j] = 'A' + (i + j) % TAILLE;
        }
    }
}

void afficher_vigenere(char table[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}


//Le cryptage de vigenere se fait ainsi: Crypté[i] == (Mot[i] + Clé[j]) mod 26 (== veut dire congru ici)
//Pour le décryptage, on veut isoler Mot[i], donc on a Mot[i] = Crypte[i] - Clé[i] mod 26
//Sauf que Crypte[i] - Clé[i] peut donner un résultat négatif (si la lettre de la clé est une lettre au dessus de la lettre cryptée) donc on fait + 26 (ce qui rendra tjrs positif
//et donnera le bon résultat)
//Donc Mot[i] = (Crypte[i] - Clé[i] + 26) mod 26, utilisé dans le décryptage

char* crypt_vigenere(char* mot, char* cle){
    char* crypte = (char*)malloc(strlen(mot) * sizeof(char));
    int len_cle = strlen(cle);
    int incr_cle = 0;
    int len_mot = strlen(mot);
    for (int i = 0; i < len_mot; i++){
        crypte[i] = (mot[i]+cle[incr_cle])%26+'A'; //+'A' Pour rester dans le bon intervalle de caractères ascii
        incr_cle++;
        if (incr_cle == len_cle){
            incr_cle = 0;
        }
    }
    return crypte;
}

char* decrypt_vigenere(char* crypte, char* cle){
    char* decrypte = (char*)malloc(strlen(crypte) * sizeof(char));
    int len_cle = strlen(cle);
    int incr_cle = 0;
    int len_crypt = strlen(crypte);
    for (int i = 0; i < len_crypt;i++){
        decrypte[i] = (crypte[i]-cle[incr_cle]+26)%26 + 'A';
        incr_cle++;
        if (incr_cle == len_cle){
            incr_cle = 0;
        } 
    }
    return decrypte;
}

int main() {
    char vigenere[TAILLE][TAILLE];
    init_vigenere(vigenere);
    char mot[] = "VIVELEPRINTEMPSETLEBEAUTEMPS";
    char cle[] = "FLEUR";
    char* crypte = crypt_vigenere(mot,cle);
    char *p = crypte;
    while (*p != '\0'){
        printf("%c",*p);
        p++;
    }
    printf("\n");
    char* decrypte = decrypt_vigenere(crypte, cle);
    char *e = decrypte;
    while (*e != '\0'){
        printf("%c",*e);
        e++;
    }
    free(crypte);
    return 0;
}