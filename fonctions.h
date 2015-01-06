#include <stdio.h>
#include <stdlib.h>


/**
* \file fonctions.h
* \author Yassine M'chaar And Ilyess Hajajou
* \date 04 Décembre 2014
* \brief ce fichier contient les en-tete des fonctions définies dans le fichier source fonctions.h
* \details ce fichier contient aussi la déclaration, des variables globales et des structures de données utilisées (matrcie,typedef,tableau...)
* */

/**
* \def N nombre de lignes de la matrice qui modélise le jeu puissance 4++.
* \brief représente le nombre de lignes de la grille du jeu puissance 4++.
*/
#define N 6
/**
* \def M nombre de colonnes de la matrice qui modélise le jeu puissance 4++.
* \brief représente le nombre de colonnes de la grille du jeu puissance 4++.
*/
#define M 7

/**
* \def CREUX
* \brief une pièce creuse du jeu est représentée par le caractère 'c'.
*/

#define CREUX 'c'

/**
* \def BLOC
* \brief une pièce blocante du jeu est représentée par le caractère 'b'.
*/

#define BLOC 'b'

/**
* \def VIDE
* \brief constante pour désigner qu'un champ d'une case de la matrice ne contient aucun pion.
*/

#define VIDE ' '

/**
* \def PLEIN
* \brief une pièce pleine du jeu est représentée par le caractère 'p'.
*/

#define PLEIN 'p'

/**
* \def nb_case
* \brief constante qui precise le nombe de case dans la grille.
*/

#define nb_case N*M

/**
* \def MAGENTA
* \brief couleur magenta.
*/

#define MAGENTA "\33[35m"

/**
* \def CYAN
* \brief couleur cyan .
*/

#define CYAN "\33[36m"

/**
* \def VERT
* \brief couleur verte.
*/

#define VERT "\33[32m"

/**
* \def ROUGE
* \brief couleur rouge.
*/

#define ROUGE "\33[31m"

/**
* \def JAUNE
* \brief couleur jaune.
*/

#define JAUNE "\33[33m"

/**
* \def BLANC
* \brief couleur blanche.
*/

#define BLANC "\33[37m"

/**
* \def MAX_JOUEUR
* \brief constante qui precise le nombe maximum des joueurs pour jouer puissance 4++.
*/

#define MAX_JOUEUR 4

/**
* \struct Pion fonctions.h
* \brief Définition de la structure pion contenant les différents types de pièces nécessaire pour jouer au puissance4++.
*/

typedef struct {
    char creuse, // champ de la structure qui représente une pièce creuse
    pleine , // champ de la structure qui représente une pièce pleine
    bloquante; // champ de la structure qui représente une pièce bloquante
    
  } Pion;

void initialiser_grille(Pion grille[N][M]);
void afficher_bordure();
void afficher_grille(Pion grille[N][M]);
int case_vide(Pion grille[N][M],int lig, int col);
int jouer(Pion grille[N][M],int colonne,char pion,int joueur);
void faire_jouer(int joueur,Pion grille[N][M]);
int coord_valides(int i, int j, Pion mat[N][M]);
int joueursuivant(int num_joueur,int nb_joueur) ;
int colonne_pleine(char pion,int colonne,Pion mat[N][M]);
int present(int joueur, int ligne,int colonne, Pion grille[N][M]) ;
int victoire (int joueur, Pion grille[N][M]);
void Help_Me(int joueur,Pion grille[N][M]);
void regles();
