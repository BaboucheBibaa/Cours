#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <chaine> <debut> <fin>\n", argv[0]);
        return -1;
    }

    int longueurChaine = strlen(argv[1]);
    int debut = atoi(argv[2]);
    int fin = atoi(argv[3]);

    if (debut < 0 || fin >= longueurChaine || debut > fin) {
        printf("Erreur : indices invalides (0 <= debut <= fin < longueur de la chaine)\n");
        return -1;
    }

    // Copie de la chaîne d'origine
    char chaine[100];
    strcpy(chaine, argv[1]);

    // Allocation pour la sous-chaîne
    char* sousListe = malloc((fin - debut + 2) * sizeof(char));
    if (!sousListe) {
        perror("malloc");
        return -1;
    }

    // Copie manuelle des caractères
    for (int i = debut; i <= fin; i++) {
        sousListe[i - debut] = chaine[i];
    }
    sousListe[fin - debut + 1] = '\0'; // fin de chaîne

    printf("Sous-chaîne extraite : %s\n", sousListe);

    free(sousListe);
    return 0;
}
