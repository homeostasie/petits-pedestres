#include <stdio.h>
#include <stdlib.h>

    char CH1 = 'X';
    char CH2 = 'O';

    int J1 =  1;
    int J2 = -1;

// Affichage de la lettre choisie en fonction du joueur.
char affiche_lettre(int *plateau, int indice)
{
    if (plateau[indice] == 0 ){return(' ');}
    if (plateau[indice] == 1 ){return(CH1);}
    if (plateau[indice] == -1){return(CH2);}
}


// Affichage du plateau de jeu
/*
 * -------
 * |7|8|9|
 * -------
 * |4|5|6|
 * -------
 * |1|2|3|
 * -------
 */

void affiche_plateau(int *plateau)
{
    int i, j;

    printf("%s\n", "-------");

    for (i = 2 ; i >= 0 ; i--)
    {
        for (j = 0 ; j <3 ; j++)
        {
            printf("%s", "|");
            printf("%c", affiche_lettre( plateau, (3*i+j)));
        }
        printf("%s\n", "|");
        printf("%s\n", "-------");
    }
}

// Produit des cases pour savoir si le jeu est fini.
int partie_nulle(int *plateau)
{
    int i=0;
    int res=1;

    for (i = 0 ; i < 9 ; i++)
    {
        res = res*plateau[i];
    }
    return(res);

}

// Initialisation du tableau pour rejouer une partie.
void init_plateau(int *plateau)
{
    int i=0;
    for (i = 0 ; i < 10 ; i++)
    {
        plateau[i] = 0;
    }
}

/* 
 * Return 1 si la case est libre et que le coup est valide.
 * Return 0 si la case est déjà occupé et que le coup est invalide.
 */

int jeu_plateau(int *plateau, int joueur, int choix)
{
    if (plateau[choix-1] == 0)
    {
        // tableau indexé à partir de 0 et non 1 : d'où choix -1.
        plateau[choix-1] = joueur;
        return(1);
    }
    else{return(0);}
}

/* 
 * Return  0 si on peut encore jouer.
 * Return 10 si la grille est complète.
 * Return  1 si J1 gagne.
 * Return -1 si J1 gagne.
 */

int test_plateau(int *plateau)
{
    int i;

    // Tests horizontaux
    if (plateau[0] + plateau[1] + plateau[2] == 3 ||
        plateau[3] + plateau[4] + plateau[5] == 3 ||
        plateau[6] + plateau[7] + plateau[8] == 3 )
    {   
        plateau[9] = J1;
        return J1;
    }
    
    if (plateau[0] + plateau[1] + plateau[2] == -3 ||
        plateau[3] + plateau[4] + plateau[5] == -3 ||
        plateau[6] + plateau[7] + plateau[8] == -3 )
    {   
        plateau[9] = J2;
        return J2;
    }

    // Tests verticaux
    if (plateau[0] + plateau[3] + plateau[6] == 3 ||
        plateau[1] + plateau[4] + plateau[7] == 3 ||
        plateau[2] + plateau[5] + plateau[8] == 3 )
    {   
        plateau[9] = J1;
        return J1;
    }
    if (plateau[0] + plateau[3] + plateau[6] == -3 ||
        plateau[1] + plateau[4] + plateau[7] == -3 ||
        plateau[2] + plateau[5] + plateau[8] == -3 )
    {   
        plateau[9] = J2;
        return J2;
    }
    // Tests diagonaux
    if (plateau[0] + plateau[4] + plateau[8] == 3 ||
            plateau[2] + plateau[4] + plateau[6] == 3 )
    {   
        plateau[9] = J1;
        return J1;
    }
    if (plateau[0] + plateau[4] + plateau[8] == -3 ||
            plateau[2] + plateau[4] + plateau[6] == -3 )
    {   
        plateau[9] = J2;
        return J2;
    }

    // La grille est complète sans gagnant.
    int nulle=1;
    for (i = 0 ; i < 9 ; i++)
    {
        nulle = nulle*plateau[i];
    }
    if(nulle != 0)
    {
        printf("%s\n", "----------------------------");
        printf("\n");
        printf("%s\n", "------ PAS DE GAGNANT ------");
        printf("\n");
        printf("%s\n", "----------------------------");

        return(10);
    }

    // La partie continue.
    return (0);
}

int tour_plateau(int *plateau)
{
    if (plateau[9] == 0)
    {    
        printf("%s\n", "        ------- Prochain tour : ");
        return (0);
    }
    if (plateau[9] == J1)
    {   
        printf("%s\n", "----------------------------");
        printf("\n");
        printf("%s\n", "------- Gagnant : J1 -------");
        printf("\n");
        printf("%s\n", "----------------------------");
        return (J1);
    }
    if (plateau[9] == J2)
    {    
        printf("%s\n", "----------------------------");
        printf("\n");
        printf("%s\n", "------- Gagnant : J2 -------");
        printf("\n");
        printf("%s\n", "----------------------------");
        return (J2);
    }
}

int main()
{
    int plateau[10];

    int victoire = 0;
    int valide =0;

    printf("%s\n", "------- DEBUT INITIALISATION PLATEAU ------ I");
    init_plateau(plateau);
    affiche_plateau(plateau);
    printf("%s\n", "------- FIN INITIALISATION PLATEAU ------ I");
    printf("\n");

    int choix;
    printf("%s\n", "------- DEBUT PARTIE ------ I");
    printf("\n");

    // tant que personne ne gagne ou que la partie n'est pas finie.
    while(victoire == 0 && victoire != 10)
    {
        // joueur 1
        do
        {
            printf("%s", "J1 prend la case : ");
            scanf("%i", &choix);

            valide = jeu_plateau(plateau, J1, choix);

            affiche_plateau(plateau);
        } while(valide == 0);

        victoire = test_plateau(plateau);
        tour_plateau(plateau);

        // Le joueur 1 gagne ou complète la grille.
        if(victoire == 0 && victoire != 10)
        {    
            // joueur 2    
            do
            {
                printf("%s", "J2 prend la case : ");
                scanf("%i", &choix);

                valide = jeu_plateau(plateau, J2, choix);

                affiche_plateau(plateau);
            } while(valide ==0);        

            victoire = test_plateau(plateau);
            tour_plateau(plateau);
        }
    }

    // fin du main().
    return 0;
}