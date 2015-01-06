#include <stdio.h>
#include <stdlib.h>

#include "fonction.h"



char* coul_joueur[MAX_JOUEUR] = { MAGENTA, CYAN, VERT, ROUGE };




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

void afficher_bordure() {//affiche une bordure de ligne
    int i;
    printf("    +");
    for (i = 0 ; i < M ; i++) {
        printf("---------+");
    }
    printf("\n");
}

void afficher_grille(Pion grille[N][M]) {//affiche la grille
    int i, j;
    
    system("clear");
    
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
           
            
            printf(" |");
        }
        printf("\n");
       afficher_bordure();
    }
   
}

//renvoie VRAI si grille[lig][col] est vide
// une case vide est une case qui ne contient ni piece bloquante, ni piece pleine ni piece creuse
int case_vide(Pion grille[N][M],int lig, int col){

	return (grille[lig][col].creuse == VIDE && grille[lig][col].pleine == VIDE && grille[lig][col].bloquante == VIDE);

}



/*
	jouer : joue dans la colonne 'colonne' le pion 'pion'
	il faut avoir vÃ©rifiÃ© que la colonne n'est pas pleine
    renvoie VRAI si on a posÃ© le pion, FAUX sinon
*/

int jouer(Pion grille[N][M],int colonne,char pion,int joueur){
	int ligne=5; // on commence en bas du tableau
	int index=0;
	switch(pion)
	{
		
		case BLOC:
			// tant que la case n'est pas vide -> on remonte !
            		while(ligne>=0 && !case_vide(grille, ligne, colonne-1))
               		{
                	  	ligne --;
              		 }
			// 2 possibilitÃ©s : soit ligne >= 0, on place le pion dans la case, ligne, colonne
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
               	//while(ligne>=0 && (grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].pleine != VIDE )){
                   ligne ++;
              	 }
           //il faut mettre le pion juste au dessus de la ligne
               if(ligne > 0)
                {
                   //if(grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].pleine != VIDE ){
                	//if(grille[ligne][colonne-1].creuse != VIDE || case_vide(grille, ligne, colonne-1))
                  		 grille[ligne-1][colonne-1].pleine= joueur;
                   		 
                   	/*}else{
                   		while(grille[ligne][colonne-1].creuse != VIDE){
                   			ligne--;
                   		}
                   		ligne++;
                   		grille[ligne][colonne-1].pleine= joueur;
                   	}*/
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
                 	//if(grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].creuse != VIDE  ){
                     //if(grille[ligne][colonne-1].pleine != VIDE || case_vide(grille, ligne, colonne-1))
                  		 grille[ligne-1][colonne-1].creuse= joueur;
                     		 
                     	/*}else{
                     		while(grille[ligne][colonne-1].pleine != VIDE){
                   			ligne--;
                   		}
                   		ligne++;
                   		grille[ligne][colonne-1].creuse= joueur;
                   	*/
                   	return 1;
                 }
                 else {
                       //colonne pleine !!
                      printf("colonne pleine !! \n\n");
                 }
	   	
		;break; 			
				
        }
   	 return 0; // on n'a pas placÃ© la piece
    	
}

/*

	fonction qui permet de faire jouer le joueur
*/

void faire_jouer(int joueur,Pion grille[N][M]){
	int colonne;
	char pion;
    
    //on choisit une colonne et un pion, tant qu'on ne peut pas jouer dans cette colonne
    do {
        
        do{
        	printf("choisir une colonne (entre 1 et 7)  : ");
        	scanf("%i",&colonne);
        }while(colonne<1 || colonne>7);
        

           printf("choisir le pion (bloquante: b, pleine: p, creux: c) : ");
      	   scanf(" %c",&pion);
       	   printf("\n");
     	   
     	   if(pion!= CREUX && pion!=BLOC && pion!=PLEIN)
        	printf("veuillez choisir soit un pion plein ou bloquant ou creux");
        	

      } while(jouer(grille,colonne,pion,joueur) == 0);  

}	
	
	
	
	
	

void victoire (Pion grille[N][M],int joueur)
{
    
    int ligne,colonne;
	int nbp_v = 0;  // nombre de pion alignes verticalement
	int nbp_h = 0; // nombre de pion alignes horizontalement
	
	
         			/* Verification victoire d'alignement Vertical */
    	for(colonne=0;colonne<M;colonne++)
    	{
    		for(ligne=5;ligne>=0;ligne--)
    		{
    			if(((grille[ligne][colonne].bloquante == joueur) ||(grille[ligne][colonne].pleine== joueur) || grille[ligne][colonne].creuse ==joueur || ((grille[ligne][colonne].pleine== joueur) && (grille[ligne][colonne].creuse ==joueur ))) && (nbp_v != 3))
    			{
    				nbp_v ++;
    				fprintf(stderr, "######### nbp_v= %i\n", nbp_v);  
    			}
    			else if((grille[ligne][colonne].pleine != joueur) && (grille[ligne][colonne].bloquante != joueur) && grille[ligne][colonne].creuse != joueur)
    				nbp_v=0;
    			else 
    				printf(" VERTICALE ok du joueur %i\n",joueur);
    		} 			
    	}
											
    			/* Verification victoire d'alignement  Horizontale*/
   
    		for(ligne=5;ligne>=0;ligne--)
    		{
    			for(colonne=0;colonne<M;colonne++)
    			{		
    				if(((grille[ligne][colonne].bloquante == joueur) ||(grille[ligne][colonne].pleine== joueur) || grille[ligne][colonne].creuse ==joueur || ((grille[ligne][colonne].pleine== joueur) && (grille[ligne][colonne].creuse ==joueur ))) && (nbp_h != 3))
    					{
    						nbp_h++;
    						fprintf(stderr, "######### nbp_h= %i\n", nbp_h);  
    					}
    					else if((grille[ligne][colonne].pleine != joueur) && (grille[ligne][colonne].bloquante != joueur) && grille[ligne][colonne].creuse != joueur)
    						nbp_h=0;
    					else 
    						printf(" HORIZONTALE ok du joueur%i\n",joueur);
					
  				} 	
    		}       

}

/* fonction d'aide au joueur */

void Help_Me(int joueur,Pion grille[N][M])
{
	 int ligne, colonne;

		/*	
			for(colonne=0;colonne<M;colonne++)
			{	
    			 while((grille[ligne][colonne].pleine == 1) || (grille[ligne][colonne].pleine == 2 ) || (grille[ligne][colonne].pleine == 3) || (grille[ligne][colonne].pleine == 4 ) 
    			 ||(grille[ligne][colonne].bloquante == 1) || ( grille[ligne][colonne].bloquante == 2) ||(grille[ligne][colonne].bloquante == 3) || ( grille[ligne][colonne].bloquante == 4) 
    			 || (grille[ligne][colonne]. creuse == 1 ) || (grille[ligne][colonne].creuse == 2 ) || (grille[ligne][colonne]. creuse == 3 ) || (grille[ligne][colonne].creuse == 4 ))

    				ligne--;

    				grille[ligne][colonne].pleine=joueur;	
    				break;
    		
    		} 			
    */
	
		int nbp_v = 0;  // nombre de pion alignes verticalement
	
	
         			/* Verification d'aide Vertical */
    	for(colonne=0;colonne<M;colonne++)
    	{
    		for(ligne=5;ligne>=0;ligne--)
    		{
    			if(((grille[ligne][colonne].bloquante == joueur) ||(grille[ligne][colonne].pleine== joueur) || grille[ligne][colonne].creuse ==joueur || ((grille[ligne][colonne].pleine== joueur) && (grille[ligne][colonne].creuse ==joueur ))) && (nbp_v != 3))
    			{
    				nbp_v ++;
    			}
    			else if((grille[ligne][colonne].pleine != joueur) && (grille[ligne][colonne].bloquante != joueur) && (grille[ligne][colonne].creuse != joueur))
    			{
    					grille[ligne][colonne].pleine=joueur;	
						break;

				}
    		} 	
    		break;		
    	}
}	

void Lancer_Jeu()
{
	int i=0,colonne,joueur=1,nbr_joueur,j=1;
	char pion;
	int choix;
	
	Pion grille[N][M];
	initialiser_grille(grille);
	afficher_grille(grille);
	do
	{
		printf("\n veuillez choisir le nombre des joueurs (maximum 4) : ");
		scanf("%i",&nbr_joueur);
	}while(nbr_joueur<2 || nbr_joueur>MAX_JOUEUR);
   
	
	while(i<nb_case){	//tant que la partie n'est pas finie
		if(nbr_joueur){
		
        
				printf("\n\n\t\t==============## Joueur %i ##================\n\n",joueur);
				
				choix=0;
				do
				{
					printf(" Si Vous voulez jouer normalement, tapez > 1 < \n");
					printf(" Si vous avez besoin d'aide, tapez > 2 < \n");
					scanf("%i",&choix);
			        }while(choix<1 || choix>2);
				
				printf(" ici \n");
			while ( choix ==1 )
			{
				printf(" classique \n");
				faire_jouer(joueur,grille);
				if(joueur==nbr_joueur)
                    joueur=0;
				afficher_grille(grille);
                victoire (grille, joueur);
				i++;
				joueur++;
				choix--;
			}
			
			while ( choix == 2 )
			{
				printf(" Fonction Help \n");
				Help_Me(joueur,grille);
				if(joueur==nbr_joueur)
                    joueur=0;
				afficher_grille(grille);
                victoire (grille, joueur);
				i++;
				joueur++;
				choix--;
			}
				
		}
		
	}
	printf("la grille est pleine");
}




