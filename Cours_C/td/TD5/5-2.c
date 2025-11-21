#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char *result = NULL;      
    size_t total_len = 0; //longueur totale de la chaine concaténée
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("Entrez une chaîne (ou FIN pour terminer) : ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {//
            break; 
        }

        // strcspn cherche dans buffer la première fois que \n apparait, pour le remplacer par \0 pour concaténer et pas faire un retour ligne
        buffer[strcspn(buffer, "\n")] = '\0';

        // on peut pas faire if buffer == "FIN", ça fonctionne pas pour les chaînes de caractères hélas
        if (strcmp(buffer, "FIN") == 0) {
            break;
        }

        size_t len = strlen(buffer);//longueur de la chaîne écrite

        // realloc pour concaténer
        char *tmp = realloc(result, total_len + len + 1); // +1 pour '\0'
        if (tmp == NULL) {
            printf("Erreur d'allocation mémoire !\n");
            free(result);
            return 1;
        }
        result = tmp;

        // Concaténation
        strncat(result, buffer, len);  // on ajoute len caractères
        total_len += len;
        result[total_len] = '\0';  // s'assurer que c'est terminé par '\0'
    }

    if (result != NULL) {
        printf("\nChaîne concaténée finale : %s\n", result);
        free(result);
    } else {
        printf("Aucune chaîne entrée.\n");
    }

    return 0;
}
