#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGUEUR 256
#define NB_COLONNES 5
#define NB_NOTES 3
#define MAX_LIGNES 100

int main( int argc, char * argv[] ) {
    if ( argc != 2 ) {
        printf( "Usage: sample filename\n" );
        exit( 0 );
    }
    FILE * inputFile = fopen( argv[1], "r" );
    if ( inputFile == NULL ) {
        printf( "Cannot open file %s\n", argv[0] );
        exit( -1 );
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile){
        perror("Erreur sur la création du fichier temporaire");
        fclose(inputFile);
        return 1;
    }
    
    int ligne = 0;
    char buffer[MAX_LONGUEUR];
    char *temp[MAX_LIGNES];

    if (fgets(buffer,MAX_LONGUEUR, inputFile)){
        buffer[strcspn(buffer, "\n")] = '\0';
        temp[ligne] = strdup(buffer);
        fprintf(tempFile,"%s;Moyenne\n", temp[ligne]);
        ligne++;
    }

    while (fgets(buffer,MAX_LONGUEUR, inputFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        temp[ligne] = strdup(buffer);
        
        float moyenne_eleve = 0;
        char * strToken = strtok ( buffer,";");
        int colonne = 0;

        while (strToken) {
            if (colonne > 1){ // 0 et 1 sont le nom et le prénom donc on les prend pas en compte pour faire la moyenne
                moyenne_eleve += atof(strToken);
            }
            strToken = strtok(NULL, ";");
            colonne++;
        }
        moyenne_eleve /= NB_NOTES;
        fprintf(tempFile,"%s;%.2f\n", temp[ligne], moyenne_eleve);
        ligne++;
    }

    fclose( inputFile );
    fclose (tempFile);

    if (remove(argv[1]) != 0 || rename("temp.txt", argv[1]) != 0) {
        perror("Erreur lors de la mise à jour du fichier original");
        return 1;
    }

    for (int i = 0; i < ligne; i++) {
        free(temp[i]);
    }
        
    return 0;
}