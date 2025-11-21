#include <stdio.h>

void afficherGrille(int taille, char tableau[taille][taille]) {
    // num de colonnes
    printf("   ");
    for (int col = 0; col < taille; col++) {
        printf(" %d  ", col);
    }
    printf("\n");

    // num de lignes
    for (int ligne = 0; ligne < taille; ligne++) {
        printf("%d   ", ligne);

        for (int col = 0; col < taille; col++) {
            printf("%c", tableau[ligne][col]);
            
            if (col < taille - 1) printf(" | ");
        }
        printf("\n");

        if (ligne < taille - 1) {
            printf("   ");
            for (int col = 0; col < taille; col++) {
                printf("---");
                if (col < taille - 1) printf("+");
            }
            printf("\n");
        }
    }
}

int compteur_tour(int nb_tours){
    return nb_tours % 2;
}

void saisie(int *saisie){
    do {
        scanf("%d", saisie);
        if (*saisie < 0 || *saisie > 2){
            printf("Saisie invalide, recommence (entre 0 et 2)\n");
        }
    } while (*saisie < 0 || *saisie > 2);
}

int verifie_position(int taille, char tableau[taille][taille],int coord_x, int coord_y){
    if (tableau[coord_x][coord_y] != '_'){
        return 0; //erreur.
    }
    return 1;//pas d'erreur
}

void place_caractere(int taille, char tableau[taille][taille], int coord_x, int coord_y, char caractere){
    if (verifie_position(taille, tableau, coord_x, coord_y)){
        tableau[coord_x][coord_y] = caractere;
    }
}

int verif_colonne(int taille, char tableau[taille][taille], int num_colonne){
    char val0 = tableau[0][num_colonne];
    char val1 = tableau[1][num_colonne];
    char val2 = tableau[2][num_colonne];

    return (val0 != '_' && val1 != '_' && val2 != '_' && val0 == val1 && val1 == val2);
}

int verif_ligne(int taille, char tableau[taille][taille], int num_ligne){
    char val0 = tableau[num_ligne][0];
    char val1 = tableau[num_ligne][1];
    char val2 = tableau[num_ligne][2];

    return (val0 != '_' && val1 != '_' && val2 != '_' && val0 == val1 && val1 == val2);
}

int verif_diag_1(int taille, char tableau[taille][taille]){
    char val0 = tableau[0][0];
    char val1 = tableau[1][1];
    char val2 = tableau[2][2];
    return (val0 != '_' && val1 != '_' && val2 != '_' && val0 == val1 && val1 == val2);
}

int verif_diag_2(int taille, char tableau[taille][taille]){
    char val0 = tableau[0][2];
    char val1 = tableau[1][1];
    char val2 = tableau[2][0];
    return (val0 != '_' && val1 != '_' && val2 != '_' && val0 == val1 && val1 == val2);
}

void init(int taille, char tableau[taille][taille]){
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            tableau[i][j] = '_';
        }
    }
}

int main() {
    int nb_tours = 0;
    int qui_joue = compteur_tour(nb_tours); //si qui_joue = 1, à X de jouer, sinon à O.
    int choix;
    int partie_finie = 0; //1 si vrai
    int ligne;
    int colonne;
    char relancer;
    printf("Choisissez la taille de la grille (3 ou 5) : ");
    scanf("%d", &choix);

    
    //type du tableau (3x3 ou 5x5)
    while (choix != 3 && choix != 5) {
        printf("Taille invalide, choisissez 3 ou 5.\n");
        scanf("%d", &choix);
    }

    //initialisation du tableau
    char tableau[choix][choix];
    init(choix, tableau);


    //boucle de jeu
    while (!partie_finie){
        afficherGrille(choix, tableau);
        //gestion du tour de O
        if (qui_joue == 0){


            printf("Au tour de O de jouer ! Choisis la ligne tu veux mettre ton O (entre 0 et 2):\n");
            saisie(&ligne);
            printf("Saisis désormais la colonne où tu veux mettre ton O:\n");
            saisie(&colonne);

            //gestion en cas de case cochée
            while (!(verifie_position(choix, tableau, ligne, colonne))){
                printf("Tu ne peux choisir une case déjà cochée ! Saisis une ligne (entre 0 et 2) !\n");
                saisie(&ligne);
                printf("Et une colonne\n");
                saisie(&colonne);
            }
            place_caractere(choix,tableau,ligne,colonne,'O');
            

        } else {

            //gestion du tour de X
            printf("Au tour de X de jouer ! Choisis la ligne tu veux mettre ton X:\n");
            saisie(&ligne);

            printf("Saisis désormais la colonne où tu veux mettre ton X:\n");
            saisie(&colonne);
            
            
            while (!(verifie_position(choix, tableau, ligne, colonne))){
                printf("Tu ne peux choisir une case déjà cochée ! Saisis une ligne (entre 0 et 2) !\n");
                saisie(&ligne);
                printf("Et une colonne\n");
                saisie(&colonne);
            }
            place_caractere(choix,tableau,ligne,colonne,'X');
        }

        nb_tours++;
        qui_joue = compteur_tour(nb_tours);


        if (verif_diag_1(choix, tableau) || verif_diag_2(choix, tableau)){ //cas de victoire
            if (tableau[1][1] == 'X'){ // vu qu'on sait que les 3 de la diagonale sont les mêmes, il suffit d'en prendre un pour savoir lequel a gagné
                printf("Victoire de X !\n");
                afficherGrille(choix, tableau);
                partie_finie = 1;
            } else if (tableau[1][1] == 'O'){
                afficherGrille(choix, tableau);
                printf("Victoire de O !\n");
                partie_finie = 1;
            }
        }

        for (int i = 0; i < choix; i++){
            if (verif_colonne(choix, tableau, i)){
                if (tableau[0][i] == 'X'){
                    printf("Victoire de X !\n");
                    afficherGrille(choix, tableau);
                    partie_finie = 1;
                } else if (tableau[0][i] == 'O'){
                    printf("Victoire de O !\n");
                    afficherGrille(choix, tableau);
                    partie_finie = 1;
                }
            }

            if (verif_ligne(choix, tableau,i)){
                if (tableau[i][0] == 'X'){
                    printf("Victoire de X !\n");
                    afficherGrille(choix, tableau);
                    partie_finie = 1;
                } else if (tableau[i][0] == 'O'){
                    printf("Victoire de O !\n");
                    afficherGrille(choix, tableau);
                    partie_finie = 1;
                }
            }
        }
        if (!partie_finie){
            printf("Au tour des %c\n", (qui_joue == 0) ? 'O' : 'X');
        }
        if (partie_finie){
            printf("Voulez-vous relancer une partie ? (O ou N)\n");
            scanf(" %c",&relancer);
            if (relancer == 'O' || relancer == 'o'){
                partie_finie = 0;
                init(choix, tableau);
                nb_tours = 0;
                qui_joue = 0;
            }
        }

    }

    

    return 0;
}
