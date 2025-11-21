#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *prog) {
    fprintf(stderr, "Usage: %s [-c|-w|-l] fichier\n", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    char *option = argv[1];
    char *filename = argv[2];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int nbCarac = 0, nbMots = 0, nbLignes = 0;
    int inWord = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) { //fgetc lit un caractère d'un fichier passé en paramètre
        nbCarac++;

        if (c == '\n') {
            nbLignes++;
        }

        if (c == ' ') {
            inWord = 0;  // fin d’un mot
        } else if (!inWord) {
            inWord = 1;  // début d’un mot
            nbMots++;
        }
    }

    fclose(fp);

    if (strcmp(option, "-c") == 0) {
        printf("%d\n", nbCarac);
    } else if (strcmp(option, "-w") == 0) {
        printf("%d\n", nbMots);
    } else if (strcmp(option, "-l") == 0) {
        printf("%d\n", nbLignes);
    } else {
        usage(argv[0]);
    }

    return 0;
}
