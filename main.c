#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "lancer_jeu.h"

/**
* \file main.c
* \author Yassine M'chaar And Ilyess Hajajou
* \date 03 Décembre 2014
* \brief ce fichier contient le programme principal qui affiche le menu du jeu
* */


/**
* \fn int main(void)
* \brief Programme principal.
*/

int main(void)
{	
	
	int choix;
	

/* on affiche le menu du jeu */
	do
	{	
		    //Afficher le début du jeu
       		printf("\t\t\33[32m ___________________________________\n");
       		printf("\t\t\33[32m|                                   |\n");
      		printf("\t\t\33[32m|\33[30m       \33[34mJEU DE PUISSANCE 4++  \33[30m   \33[32m   |\n");
	        printf("\t\t\33[32m|___________________________________|\n");
	        printf("\t\t\33[32m|   \33[34m Bienvenue dans Puissance 4++ \33[30m \33[32m | \n");
 	        printf("\t\t\33[32m| 	\33[34m~ Faites votre Choix ~   \33[30m  \33[32m |\n");
  	        printf("\t\t\33[32m|___________________________________|\n");
	        printf("\t\t\33[32m|\33[34m 1 - Jouer au Puissance 4 ++    \33[30m\33[32m   |\n");
	        printf("\t\t\33[32m|\33[34m 2- Regarder regles puissance 4++ \33[30m\33[32m | \n");
	        printf("\t\t\33[32m|\33[34m 3 - Quitter                      \33[30m \33[32m|\n");
                printf("\t\t\33[32m|___________________________________\33[30m\33[32m|\33[30m  \n\n");
	        printf("Votre choix : ");
		scanf("%i",&choix);

/* on Traite  le choix de l'user */
		switch(choix)
		{	
			case 1: Lancer_Jeu();break;
			case 2: regles();break;
			case 3:break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf("\n A la prochaine  ! \n\n");
	return 0;
}





