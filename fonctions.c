#include <stdio.h>
#include <stdlib.h>
#include "direction.h"
#include "fonctions.h"

/**
* \file fonctions.c
* \author Yassine M'chaar And Ilyess Hajajou
* \date 03 Décembre 2014
* \brief ce fichier source contient les définitions des fonctions d'affichage  de la grille du jeu et des fonctions qui permettent de jouer dans la grille detecter une victoire d'un joueur.
* \details ce fichier contient aussi la définition de la fonction d'initialisation de la grille du jeu.
* il contient également la définition de la fonction  qui permet de savoir si la grille du jeu est entièrement remplie.et aussi des fonctions servent à jouer dans la grille et detecter le joueur gagnant.
* */


/**
* \var Pion grille[N][M]
* \brief structure de données utilisé pour le jeu puissance4++
* \details matrice de type pion et de taille N*M .
* chaque case de la matrice peut contenir deux pièces(pions) au maximum.
* une case peut contenir une pièce "bloquante" ou "pleine" ou "creuse" ou deus pièces "creuse/pleine" ou peut etre vide(espace).
* on distingue donc 5 cas possibles pour une case de la matrice.
*/
Pion grille[N][M];

/**
* \var char* coul_joueur[MAX_JOUEUR]
* \brief structure de données utilisé pour le jeu puissance4++ qui precise la couleur de chaque joueur
* \details tableau de type char et de taille MAX_JOUEUR.
* \* chaque case du tableau contient la couleur du joueur
*/
char* coul_joueur[MAX_JOUEUR] = { MAGENTA, CYAN, VERT, ROUGE };




/**
* \fn void initialiser_grille(Pion grille[N][M]
* \brief procédure qui initialise les cases de la grille à vide (des espaces).
* \param grille matrcie de taille N(lignes)*M(colonnes) qui représente la grille du jeu.
*/
void initialiser_grille(Pion grille[N][M]) {
    int i,j;
    
    
    for (i = 0 ; i < N ; i++) {
        for (j = 0 ; j < M ; j++) {
            grille[i][j].creuse = VIDE;
	    grille[i][j].pleine = VIDE;
	    grille[i][j].bloquante = VIDE;
        }
    }
}

/**
* \fn void afficher_bordure()
* \brief procédure qui affiche les bordures de  ligne de la grille du jeu.
*/

void afficher_bordure() { 
    int i;
    printf("\33[32m    +");
    for (i = 0 ; i < M ; i++) {
        printf("\33[32m---------+");
    }
    printf("\n");
}


/**
* \fn void afficher_grille(Pion grille[N][M])
* \brief procédure qui affiche la grille du jeu.
* \param grille matrice de type pion de taille N*M à afficher.
*/

void afficher_grille(Pion grille[N][M]) {//affiche la grille
    int i, j,num;
    
   // system("clear");
      for (num = 1 ; num < M+1 ; num++) 
			printf("\33[32m      %i   \33[30m ",num);
			printf(" \n");
    afficher_bordure();
    for (i = 0 ; i < N ; i++) {
        printf("    |");
        for (j = 0 ; j < M ; j++) {
           
            printf("   ");
            if(grille[i][j].creuse == VIDE) printf(" ");
            else { printf("%sc%s", coul_joueur[grille[i][j].creuse - 1], BLANC); }//afficher les pions en couleur
            
            printf(" ");
            
            if(grille[i][j].pleine == VIDE) printf(" ");
             else { printf("%sp%s", coul_joueur[grille[i][j].pleine - 1], BLANC); }
            
            printf(" ");
            
            if(grille[i][j].bloquante == VIDE) printf(" ");
            else { printf("%sb%s", coul_joueur[grille[i][j].bloquante - 1], BLANC); }
           
            
            printf("\33[32m |");
        }
        printf("\n");
       afficher_bordure();
    }
   
}

/**
* \fn int case_vide(Pion grille[N][M],int lig, int col)
* \brief renvoie VRAI si grille[lig][col] est vide
* \brief une case vide est une case qui ne contient ni piece bloquante, ni piece pleine ni piece creuse
* \param grille matrice de type pion de taille lig*col à afficher 
*/

int case_vide(Pion grille[N][M],int lig, int col){

	return (grille[lig][col].creuse == VIDE && grille[lig][col].pleine == VIDE && grille[lig][col].bloquante == VIDE);

}

/**
* \fn int jouer(Pion grille[N][M],int colonne,char pion,int joueur)
* \brief joue dans la colonne 'colonne' le pion 'pion' et il faut avoir vÃ©rifiÃ© que la colonne n'est pas pleine.
* \brief renvoie VRAI si on a posé le pion, FAUX sinon.
* \param joueur qui permet de choisir une colonne de la grille pour mettre le pion choisie 
*/

int jouer(Pion grille[N][M],int colonne,char pion,int joueur){
	int ligne=5; // on commence en bas du tableau
	switch(pion)
	{
		
		case BLOC:
			// tant que la case n'est pas vide -> on remonte !
            		while(ligne>=0 && !case_vide(grille, ligne, colonne-1))
               		{
                	  	ligne --;
              		 }
			// 2 possibilitées : soit ligne >= 0, on place le pion dans la case, ligne, colonne
			// soit i < 0 -> la colonne est pleine
			
               		if(ligne>=0)
              		 {
                 		 grille[ligne][colonne-1].bloquante = joueur;
                 		
                  		return 1;
               		}
               		else {
                  	 //colonne pleine !!
                  	 printf("colonne pleine !! \n\n");
                   
               		}
				
              	 ;break;
            case PLEIN:
            	ligne=0; // on commence en haut du tableau, on descend si !plein ou si !block
		while(ligne < N && grille[ligne][colonne-1].pleine == VIDE && grille[ligne][colonne-1].bloquante == VIDE ){
			// tant que la case ne contient ni une bloquante ni une pleine -> on remonte !			
                   	ligne ++;
              	 }
           //il faut mettre le pion juste au dessus de la ligne
               if(ligne > 0)
                {
                   
                  	grille[ligne-1][colonne-1].pleine= joueur;
                   	return 1;
                }
               else {
                   //colonne pleine !!
                   printf("colonne pleine !! \n\n");
               }
			 
			 
		
               ;break;
            case CREUX:		// Si case non vide ou bloquante, on remonte sinnon traverse
            ligne=0;    // on commence en haut du tableau, on descend si !creuse ou si !block
            	while(ligne < N && grille[ligne][colonne-1].creuse == VIDE && grille[ligne][colonne-1].bloquante == VIDE){
		//while(ligne>=0 && (grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].creuse != VIDE)){
                        ligne ++;
                 }
                if(ligne>=0)
                 {
                 	
                  	grille[ligne-1][colonne-1].creuse= joueur;
                   	return 1;
                 }
                 else {
                       //colonne pleine !!
                      printf("colonne pleine !! \n\n");
                 }
	   	
		;break; 			
				
        }
   	 return 0; // on n'a pas placé la piece
    	
}

/**
* \fn int coord_valides(int ligne, int colonne, Pion grille[N][M])
* \brief verifie que les coordonnées (i;j) sont valides (dans la matrice)
* \param grille matrice de type pion de taille ligne*colonne à afficher 
*/

int coord_valides(int ligne, int colonne, Pion grille[N][M])
{
    if ((ligne>=0 && ligne<N) && (colonne>=0 && colonne<M))
        return 1;
    return 0;
    
}

/**
* \fn int present(int joueur, int ligne,int colonne, Pion grille[N][M])
* \brief test la présence du joueur x sur a un endroit donné, retourne le numero du joueur ou zéro sinon
* \param  grille de taille lignne*colonne detecte joueur   
* \return joueur pour qu on sache si il est present sinon il retourne 0
*/

int present(int joueur, int ligne,int colonne, Pion grille[N][M]) /**/
{
	if (grille[ligne][colonne].creuse==joueur || grille[ligne][colonne].pleine==joueur || grille[ligne][colonne].bloquante==joueur)
		return joueur;
	return 0;
}

/**
* \fn int victoire (int joueur, Pion grille[N][M])
* \brief fonction qui renvoie vrai si la case i,j est le début d'une suite de 4 pions de couleur joueur
* \param  grille de taille N*M precise le joueur qui gagne 
* \return VRAI si il y a 4 pions alignés soit verticalement ou diagonalement ou horizontalement
*/

int victoire (int joueur, Pion grille[N][M]){

    int nbp,i,is,j,js ;
    //pour chaque direction
    t_dir dir=NORD;
        			nbp=0;
    	for(i=0;i<N;i++){
    		for(j=0;j<M;j++){
    				do{
    							is=i;	
    							js=j;
        //compte le nombre de pions de la bonne couleur dans cette direction
       		 			while(nbp<4 && coord_valides(is, js, grille) && present(joueur,is,js,grille)==joueur){
            				nbp++;
            //positionner is et js sur la case suivante
            	is = valeur_suivante_abs(dir, is);
           	 	js = valeur_suivante_ord(dir, js);
        				}
        //si c'est 4 -> gagné
        				if(nbp >=4)
            			return 1;
        // sinon rien
        
        //on passe à la direction suivante
        				dir=direction_suivante(dir); nbp=0;
        
    } while(dir!= NORD); //on n'a pas fait le tour !
    }}
    //on n'a pas gagne -> renvoie faux
    return 0;
    
    
}

void Help_Me(int joueur,Pion grille[N][M])
{
    int nbp,i,is,j,js,compt=0;
    //pour chaque direction
    t_dir dir=NORD;
        			nbp=0;
    	for(i=0;i<N;i++){
    		for(j=0;j<M;j++){
    			compt++;
    				while(nbp!=1)
    				{	
    							is=i;	
    							js=j;
        //compte le nombre de pions de la bonne couleur dans cette direction
       		 			while(nbp<3 && coord_valides(is, js, grille) && present(joueur,is,js,grille)==joueur)
       		 			{
         	   				nbp++;
         	   				
           					 //positionner is et js sur la case suivante
            				is = valeur_suivante_abs(dir, is);
           	 				js = valeur_suivante_ord(dir, js);
        				}
       					 //si c'est 3 -> gagné
        				if(nbp >=1 && case_vide(grille,is, js)==1)
							grille[is][js].bloquante=joueur;

						break;
        				dir=direction_suivante(dir); 
        				nbp=0;
        
   				 }  
   				 			

    }
   }
    if(compt==42){
   			printf("\33[31m \n\n /! ATTENTION mauvaise tentative votre tour saute \n réfléchissais avant de demander l'aide !/ \33[30m  \n");
    		return 0;
    }else
    	return 1;
}








/**
* \fn void Help_Me(int joueur,Pion grille[N][M])
* \brief fonction qui permet de mettre un pion dans la grille pour aider le joueur
* \param  joueur qui demande l'aide dans la grille du jeu
*/

/*
void Help_Me(int joueur,Pion grille[N][M])
{
	 int ligne=5,colonne=0;
	int nbp_v = 0;  // nombre de pion alignes verticalement
	
	
    			if(((grille[ligne][colonne].bloquante == joueur) ||(grille[ligne][colonne].pleine== joueur) || grille[ligne][colonne].creuse ==joueur || ((grille[ligne][colonne].pleine== joueur) && (grille[ligne][colonne].creuse ==joueur ))) && (nbp_v != 3))
    			{
				
    				nbp_v ++;
				ligne--;
    			}
    			else if((grille[ligne][colonne].pleine != joueur) && (grille[ligne][colonne].bloquante != joueur) && (grille[ligne][colonne].creuse != joueur))
    			{		
					while(!case_vide(grille,ligne, colonne)){
						ligne--;
					}
					if(!case_vide(grille,0, colonne)){
						
    						grille[ligne][colonne+1].bloquante=joueur;	
					}else{
						grille[ligne][colonne].bloquante=joueur;
					}
					

			}
    			
    	
	
}	

*/

/**
* \fn int joueursuivant(int num_joueur,int nb_joueur) 
* \brief fonction qui permet de donner le numero du joueur qui va jouer apres le joueur precedent
* \param  num_joueur qui va jouer parmis les nb_joueur
* \return renvois le joueur suivant ( joueur précédent + 1)
*/

int joueursuivant(int num_joueur,int nb_joueur) 
{
	
	if (num_joueur==nb_joueur)
		num_joueur=0;
	return num_joueur+1; // renvois le joueur suivant ( joueur précédent + 1)


}

/**
* \fn int colonne_pleine(char pion,int colonne,Pion grille[N][M])
* \brief test si la colonne est pleine
* \param grille qui contient des pions dans une colonne précisée 
* \return renvois 1 si la colonne est pleine 0 sinon
*/

int colonne_pleine(char pion,int colonne,Pion grille[N][M])
{
		int ligne =0;
		
		switch(pion){
				case 'p' : {if(grille[ligne][colonne-1].pleine!=VIDE)
									return 1;break;}
				case 'c' : {if(grille[ligne][colonne-1].creuse!=VIDE)
									return 1;break;}
				case 'b' : {if(grille[ligne][colonne-1].bloquante!=VIDE || grille[ligne][colonne-1].creuse!=VIDE || grille[ligne][colonne-1].pleine!=VIDE)
									return 1;break;}
		}
		return 0;
}

/**
* \fn void regles()
* \brief fonction qui donne les regles du jeu au joueur
*/

void regles()
{
	system("clear");
	printf(" \t\t\n\n \33[32m\33[34m Vous avez choisi de consulter les regles \33[30m\33[32m\n\n");
	FILE * fichier; /*fichier de sauvegarde nom des joueurs et resultats partie !*/
  	int caractereActuel = 0;
	fichier=fopen("regles.txt","r");
	   
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
       do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
    }
 
 	printf(" \n\n");

}
	
	


