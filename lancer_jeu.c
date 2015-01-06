#include <stdio.h>
#include <stdlib.h>
#include "direction.h"
#include "fonctions.h"
#include "lancer_jeu.h"



/**
* \file lancer_jeu.c
* \author Yassine M'chaar And Ilyess Hajajou
* \date 05 Décembre 2014
* \brief ce fichier source contient la définition d'une fonction qui  permet de lancer le jeu et jouer la puissance 4++ .De plus,la partie sera enregistrée.
*/


/**
* \fn void Lancer_Jeu()
* \brief fonction qui permet de lancer et enregistrer la partie dans un fichier .
*/
void Lancer_Jeu()
{
	
	Pion grille[N][M]; 
	FILE * fichier; /*fichier de sauvegarde nom des joueurs et resultats partie !*/
	fichier=fopen("resultats.txt","a+");
	int joueur,j=0, colonne, compteur=0,rep=0,score, total,choix;
	char pion;
	printf("\n");
	initialiser_grille(grille);
	afficher_grille(grille);
	printf(" \n Bienvenue dans le  mode jeu puissance 4++ \n ");
	
	do
	{
		printf("\n Combien de joueurs  vont jouer ? (maximum 4) : ");
		scanf("%i",&joueur);
	}while(joueur<2 || joueur>MAX_JOUEUR);
	printf(" \33[31m /! Pour rappel, un systeme d'aide a était mit en place, si vous demandez de l'aide \n");
	printf(" alors que tous vos pions sont encerclés, ou aucun de vos pion n'est placé,  \n");
	printf(" vous serez  alors pénalisé, votre tour sautera ! Bonne Partie ! / \33[30m \n");

	while (compteur !=42) //tant que la grille n est pas remplie
    	 {
     								
			j=joueursuivant(j,joueur);
			printf("\n\n\t\t==============## Joueur \33[31m %i\33[30m   ##================\n\n",j);
			do{
				printf("Tapez 1 si vous avez besoin d'aide sinon Tapez 2 : ");
				scanf("%i",&choix);
			}while(choix!=1 && choix!=2);
			switch(choix){
				case 1: 
					Help_Me(j,grille);
					afficher_grille(grille);
					rep=victoire(j,grille);
					if (rep==1)
					{	
						printf("\n Le joueur %i a gagné ! \n", j);
						fprintf(fichier,"%i %i %i \n",j,1,1);
					};
					break;
				case 2:
					printf("Dans quelle colonne voulez-vous jouez et quel type de pièce? \n Pleine (p), Creuse (c), Bloquante (b) ");
					scanf("%i%c",&colonne,&pion);
					
					while (colonne>M || colonne<1 ||( pion !='b' && pion !='c'&& pion!='p')) /*cas erreur*/
					{ 
						printf("veuillez ressaisir le numero de la colonne (entre 1 et 7) et le type de la pièce ");
						scanf("%i%c",&colonne,&pion);
					}
					if (colonne_pleine(pion,colonne,grille))//on regarde si la colonne est pleine
					{
						printf("La colonne est pleine, ressaisissez la colonne et le type de piece ");
						scanf("%i%c",&colonne,&pion);
					}
					jouer(grille,colonne,pion,j) ;
					rep=victoire(j,grille);
					afficher_grille(grille);
					compteur++;

					
					if (rep==1){
						printf("\n Le joueur %i a gagné ! \n", j);
						fprintf(fichier,"%i %i %i \n",j,1,1);
					};
					break;
				
			}
	}
	
	if (compteur ==42){ // si la grille est remplie
		printf(" Match nul, la grille est remplie sans detection de victoire \n ");
		for(j=1;j<5;j++){
			fprintf(fichier,"%i %i %i \n",j,0,0);	
		
		}
	}else{	
		switch(j){
			case 1:fprintf(fichier,"%i %i %i \n",2,0,0);fprintf(fichier,"%i %i %i \n",3,0,0);fprintf(fichier,"%i %i %i \n",4,0,0);break;
			case 2:fprintf(fichier,"%i %i %i \n",1,0,0);fprintf(fichier,"%i %i %i \n",3,0,0);fprintf(fichier,"%i %i %i \n",4,0,0);break;
			case 3:fprintf(fichier,"%i %i %i \n",1,0,0);fprintf(fichier,"%i %i %i \n",2,0,0);fprintf(fichier,"%i %i %i \n",4,0,0);break;
			case 4:fprintf(fichier,"%i %i %i \n",1,0,0);fprintf(fichier,"%i %i %i \n",2,0,0);fprintf(fichier,"%i %i %i \n",2,0,0);break;
		
		}

	}
	
	rewind(fichier);/*met le pointeur du fichier au debut*/
	while(!feof(fichier))
	{
			fscanf(fichier,"%i",&j);// afficher les joueurs et leur score mis a jour a voir 
			fscanf(fichier,"%i",&score);
			fscanf(fichier,"%i",&total);
			printf ("joueur %i : score %i total %i \n",j,score,total);
			break;
	}
		
	fclose(fichier);
}


