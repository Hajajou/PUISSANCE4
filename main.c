#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


/*	Programme principal */
int main(void)
{	
	
	int choix;
	int nbr_joueur;

/* on affiche le menu du jeu */
	do
	{	
		    //Afficher le début du jeu
       printf("\33[32m ___________________________________\n");
       printf("\33[32m|                                   |\n");
       printf("\33[32m|\33[30m      \33[34mJEU DE PUISSANCE 4++ \33[30m  \33[32m    |\n");
		  printf("\33[32m|___________________________________|\n");
		  printf("\33[32m|   \33[34m Bienvenue dans Puissance 4++ \33[30m \33[32m | \n");
  printf("\33[32m| 	\33[34m~ Faites votre Choix ~   \33[30m  \33[32m |\n");
  		printf("\33[32m|___________________________________|\n");
		  printf("\33[32m|\33[34m 1 - Jouer au Puissance 4 classique\33[30m\33[32m|\n");
		  printf("\33[32m|\33[34m 2 - Jouer en mode 2 joueurs       \33[30m\33[32m|\n");
		  printf("\33[32m|\33[34m 3 - Jouer en mode 3 joueurs       \33[30m\33[32m|\n");
		  printf("\33[32m|\33[34m 4 - Jouer en mode 4 joueurs       \33[30m\33[32m|\n");
		  printf("\33[32m|\33[34m 5 - Regarder regles puissance 4++ \33[30m\33[32m| \n");
		  printf("\33[32m|\33[34m 6 - Quitter                      \33[30m \33[32m|\n");
       printf("\33[32m|___________________________________\33[30m\33[32m|\33[30m  \n\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* on Traite  le choix de l'user */
		switch(choix)
		{	
			case 1: Lancer_Jeu();
			case 2: Lancer_Jeu();nbr_joueur=2;
			case 3: Lancer_Jeu();nbr_joueur=3;
			case 4:Lancer_Jeu();nbr_joueur=4;
			case 5: 
			case 6: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=5);
	printf("A la prochaine inshaa Allah  ! \n");
	return 0;
}





