#include <stdio.h>
#include <stdlib.h>


#define N 6
#define M 7
#define VIDE ' '
#define CREUX 'c'
#define BLOC 'b'
#define PLEIN 'p'
#define nb_case N*M

#define MAGENTA "\33[35m"
#define CYAN "\33[36m"
#define VERT "\33[32m"
#define ROUGE "\33[31m"
#define JAUNE "\33[33m"
#define BLANC "\33[37m"

#define MAX_JOUEUR 4


typedef struct {
    char creuse,
    pleine ,
    bloquante;
    
  } Pion;

void initialiser_grille(Pion grille[N][M]);
void afficher_bordure();
void afficher_grille(Pion grille[N][M]);
int case_vide(Pion grille[N][M],int lig, int col);
int jouer(Pion grille[N][M],int colonne,char pion,int joueur);
void faire_jouer(int joueur,Pion grille[N][M]);
void victoire (Pion grille[N][M],int joueur);
void Lancer_jeu();