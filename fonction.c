//////////////////////////////
// ELIASS HAJAJOU 		 //
//											//
//////////////////////////

#include <stdio.h>
#include "fonction.h"


// structure de nos type  de pion

typedef struct {
    char creuse,
    pleine ,
    bloquante;
    
  } Pion;

														/*initialise la matrice de jeu*/
void init_matrice(Pion grille[N][M]) 
{
	int i,j;	
	for (i=0;i<N;i++)
	{
			for (j=0;j<M;j++)
			{
			      grille[i][j].creuse = VIDE;
			      grille[i][j].pleine = VIDE;
	    	      grille[i][j].bloquante = VIDE;
			}
		}
}

														/*affichage de la matrice */
void afficher_jeu(Pion grille[N][M])
{
	int i,j;
		


    printf("| ");
    for(i = 0; i < M; i++)
        printf("%i  | ", i+1); // on affiche le numero de la colonne
  
    printf("\n");

    printf("|");
    for(i = 0; i < M-1; i++)
        printf("____"); // une ligne 'souligné' pour dessiner le cadre
    printf("__________|\n");
	
  for(j = M-1 ; j >= 0; j--) // on affiche la ligne du haut en haut et on descend pour avoir l'affichage dans le bon sens
    {
        printf("|");
        
        for(i = 0; i< N; i++)
        {
           
                printf("%c%c%c ", grille[i][j].creuse,grille[i][j].pleine,grille[i][j].bloquante);
                           printf("|");
        }
        printf("    |\n");
    }
  
    for(i = 0; i < M-1; i++)
        printf("___"); // une ligne 'souligné' pour dessiner le cadre
    printf("_________________|\n");
    
}
	
int case_vide(Pion grille[N][M],int lig, int col){

	return (grille[lig][col].creuse == VIDE && grille[lig][col].pleine == VIDE && grille[lig][col].bloquante == VIDE);

}
	
											
											
											
																		/*verification si coordonnées valides*/   /
int coord_valide(Pion grille[N][M],int i, int j)
{
	    if ((i>=0 && i<N) && (j>=0 && j<M))	//valeur entrée par user doit etre comprise entre 0 et 7
       		 return 1;
    	else
    		return 0;
} 
 
 
 
 
																			 /*test si la colonne est pleine*/      
		
int colonne_pleine(int colonne,Pion grille[N][M];)
{
	int ligne =0;
	
	 if( grille[ligne][colonne-1] ==0 )  	// si ligne  du haut de la colonne  entrée est pleine renvois 1  sinon 0
			return 1;							
	else
		return 0;
} 
    															/*test si grille jeu pleine*/   
 int grille_pleine(int grille[N][M])
{
	int colonne=0;
	int ligne=0;
	
	
	while(colonne<=6 && grille[ligne][colonne] !=0  )  //on parcours les colonnes pour vérifier si elles sont pleines
		colonne++;
	
	if(colonne>=7)
		return 1 ;
	else
		return 0;
}   



//int victoire()

//void num_joueur()	



// fonction qui permet à l'user de jouer
void jouer(Pion grille[N][M],int colonne,char pion, char joueur){
	int ligne=5; // on commence en bas du tableau
	switch(pion)
	{
		
		case BLOC:
			// tant que la case n'est pas vide -> on remonte !
			while(ligne>=0 && !case_vide(grille, ligne, colonne)){
				ligne --;
			}
			// 2 possibilités : soit ligne >= 0, on place le pion dans la case, ligne, colonne
			// soit i < 0 -> la colonne est pleine
			grille[ligne][colonne].bloquante = BLOC;

		;break;
		case PLEIN:
		
			// tant que la case ne contient ni une bloquante ni une pleine -> on remonte !			
			while(ligne>=0 && (grille[ligne][colonne].bloquante != VIDE || grille[ligne][colonne].pleine != VIDE )){
				ligne --;
			}
			 grille[ligne][colonne].pleine= PLEIN;
			 
		
			;break;
		case CREUX:		// Si case non vide ou bloquante, on remonte sinnon traverse
						while(ligne>=0 && (grille[ligne][colonne].bloquante != VIDE || grille[ligne][colonne].creuse != VIDE)){
							ligne --;
							}
							grille[ligne][colonne].creuse = CREUX;  	
			;break; 			
				
	}	
}	





					//		jouer partie 
void lancer_jeu()
{
	int i=0,colonne;
	char pion;
	char joueur;
	Pion grille[N][M];
	init_matrice(grille);
	afficher_jeu(grille);
	while(i<Z){
		
		printf("choisir la colonne: ");
		scanf("%i",&colonne);
		colonne--;
		printf("choisir un type de pion ");
		scanf(" %c",&pion);
		printf("\n");
		
       		jouer(grille,colonne,pion,'A');
		afficher_jeu(grille);
		i++;
	}

					
}
	int i=0;  // incrementation pour les 42 pions en jeu
 	char pion;
	int colonne;
	char joueur_1[20];
	Pion grille[N][M];
	printf(" Quel joueur commence ? \n");
	scanf("%s",joueur_1);
		
	while( i !=42 && grille_pleine(grille))
	{
		
		printf(" \n Bonjour %i choisissez une colonne : ", num_joueur ); // avoir avec yassin
		scanf("%i",&colonne);
		while(!coord_valide())
					scanf("%i",&colonne);
		
		while(colonne_pleine())
		{
			printf(" cette colonne est pleine, choisissez en une autre \n");
			scanf("%i",&colonne);
		}
					
			printf(" \n Et choisissez un type de pion :");
			printf(" \n 'p' Pion type plein :");
			printf(" \n 'b' Pion type bloquant :");
			printf(" \n 'c' Pion type creux :");
			scanf("%c", &pion);
			jouer(grille,colonne,pion);
			afficher_jeu(grille);
			i++
			
		}
	







/*	Programme principal */
int main(void)
{	int choix;

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
		{	case 1: lancer_jeu();
			case 2: 
			case 3: 
			case 4:
			case 5: 
			case 6: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=5);
	printf("A la prochaine inshaa Allah  ! \n");
	return 0;
}
