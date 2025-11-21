#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define NB_COLONNES 5

int main(int argc, char *argv[]) {
    argc--; argv++;

    if (argc == 0) {
        printf("Usage: %s filename\n", argv[-1]);
        return 1;
    }

    FILE *inputFile = fopen(argv[0], "r");
    if (!inputFile) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile){
        perror("Erreur sur la création du fichier temporaire");
        return 1;
    }


    int nb = 0;
    char *buffer = malloc(MAX_LENGTH);
    char **temp = malloc(MAX_LENGTH);
    if (!buffer || !temp) {
        perror("Erreur malloc");
        return 1;
    }

    // Ignorer l'entête
    fgets(buffer, MAX_LENGTH, inputFile);  

    //évite le double \n en fin de ligne
    buffer[strcspn(buffer, "\n")] = '\0';

    //écriture de l'entête dans le fichier temporaire
    temp[nb] = strdup(buffer);
    fprintf(tempFile,"%s;Moyenne\n", temp[nb]);
    nb++;


    while (fgets(buffer, MAX_LENGTH, inputFile)) {

        
        //Ecriture de la ligne dans un fichier temporaire
        //buffer[strcspn(buffer, "\n")] = '\0';  // \n final
        temp[nb] = strdup(buffer);            // copie de la ligne
        fprintf(tempFile,"%s", temp[nb]);
        nb++;
    }

    for (int i = 0; i < nb; i++) {
        //printf("%s\n", temp[i]);
        free(temp[i]); 
    }

    free(temp);
    free(buffer);
    fclose(inputFile);
    return 0;
}
