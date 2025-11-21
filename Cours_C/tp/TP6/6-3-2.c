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
        printf( "Cannot open file %s\n", argv[1] );
        exit( -1 );
    }

    FILE *tempFile = fopen("temp.txt", "w+");
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

    float moyenne_c =0;
    float moyenne_sdf = 0;
    float moyenne_progfonc = 0;
    float moyenne_globale = 0;
    while (fgets(buffer,MAX_LONGUEUR, inputFile) != NULL){
        buffer[strcspn(buffer, "\n")] = '\0';
        temp[ligne] = strdup(buffer);
        
        float moyenne_eleve = 0;
        char * strToken = strtok ( buffer,";");
        int colonne = 0;
        while (strToken) {
            float note = atof(strToken);
            switch (colonne) {
                case 2: moyenne_c += note; break;
                case 3: moyenne_sdf += note; break;
                case 4: moyenne_progfonc += note; break;
            }
            moyenne_eleve += note;
            strToken = strtok(NULL, ";");
            colonne++;
        }
        moyenne_eleve /= NB_NOTES;
        moyenne_globale += moyenne_eleve;
        fprintf(tempFile,"%s;%.2f\n", temp[ligne], moyenne_eleve);
        ligne++;
    }

    moyenne_c /= (ligne-1);
    moyenne_sdf /= (ligne-1);
    moyenne_progfonc /= (ligne-1);
    moyenne_globale /= (ligne-1);
    fprintf(tempFile, "Moyenne;Générales;%.2f;%.2f;%.2f;%.2f", moyenne_c,moyenne_sdf,moyenne_progfonc, moyenne_globale);
    fclose( inputFile );
    fclose (tempFile);

    if (remove(argv[1]) != 0) {
        perror("Erreur lors de la suppression de l'ancien fichier");
        return 1;
    }

    if (rename("temp.txt", argv[1]) != 0) {
        perror("Erreur lors du renommage du fichier temporaire");
        return 1;
    }

    for (int i = 0; i < ligne; i++) {
        free(temp[i]);
    }

    return 0;
}