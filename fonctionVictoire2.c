#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 7
#define VIDE 0
#define CREUX 'c'
#define BLOC 'b'
#define PLEIN 'p'
#define nb_case N*M




#define MAGENTA "\33[35m"
#define VERT "\33[32m"
#define ROUGE "\33[31m"
#define JAUNE "\33[33m"
#define BLEU "\33[34m"
#define CYAN "\33[36m"
#define BLANC "\33[37m"




typedef struct {
    int creuse,
    pleine ,
    bloquante;
    
  } Pion;

void initialiser_grille(Pion grille[N][M]) {
    int i, j;
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
            printf("   %i %i %i |", grille[i][j].creuse,grille[i][j].pleine,grille[i][j].bloquante);
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
		
			// tant que la case ne contient ni une bloquante ni une pleine -> on remonte !			
               while(ligne>=0 && (grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].pleine != VIDE )){
                   ligne --;
               }
               
               if(ligne>=0)
                {
                   grille[ligne][colonne-1].pleine= joueur;
                   return 1;
                }
               else {
                   //colonne pleine !!
                   printf("colonne pleine !! \n\n");
               }
			 
			 
		
               ;break;
            case CREUX:		// Si case non vide ou bloquante, on remonte sinnon traverse
						while(ligne>=0 && (grille[ligne][colonne-1].bloquante != VIDE || grille[ligne][colonne-1].creuse != VIDE)){
							ligne --;
                        }if(ligne>=0)
                         {
                            grille[ligne][colonne-1].creuse = joueur;
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


void victoire (Pion grille[N][M],int joueur)
{

	 int ligne,colonne,x,z=0;
	int nbp_v = 0;  // nombre de pion alignés verticalement
	int nbp_h = 0; // nombre de pion alignés horizontalement
	int nbp_d = 0; // nombre de pion alignés diagonalement
	

        		
        			/* Verification victoire d'alignement vertical */
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
											
    			/* Verification victoire d'alignement  horizontale*/
   
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
    		
    		/* Verification victoire d'alignement  diagonale 	
    		
    		for(ligne=5;ligne>=3;ligne++)
    		{
    					printf(" valeur 4 \n");
    			for(colonne=0;colonne<4;colonne++)
				{
					
							printf(" valeur colonne %i \n",z);
					x=0;
					do
					{
								fprintf(stderr, "XXxx  Valeur de  x = %i\n", x); 
							printf(" valeur 2 \n");
						if(((grille[ligne+x][colonne+x].bloquante == joueur) ||(grille[ligne+x][colonne+x].pleine== joueur) || grille[ligne+x][colonne+x].creuse ==joueur || ((grille[ligne+x][colonne+x].pleine== joueur) && (grille[ligne+x][colonne+x].creuse ==joueur ))) && (nbp_d != 3))
    					{
    						nbp_d++;
    						fprintf(stderr, "######### nbp_d= %i\n", nbp_d);  
    					}
    					else if((grille[ligne+x][colonne+x].pleine != joueur) && (grille[ligne+x][colonne+x].bloquante != joueur) && grille[ligne+x][colonne+x].creuse != joueur)
    						nbp_d=0;
    					else 
    						printf(" DIAGONALE ok du joueur%i\n",joueur);
						x++;
						printf(" valeur 3 \n");
						
						 
					}while(colonne<M || ligne >=0 || x <= 5);
    		
    		}
    	}
    
    		*/
    		
}
    			



/*

	fonction qui permet de faire jouer le joueur
*/

void faire_jouer(int joueur,Pion grille[N][M]){
	int colonne;
	char pion;
    
    //on choisit une colonne et un pion, tant qu'on ne peut pas jouer dans cette colonne
    do {
        printf("choisir la colonne: ");
        scanf("%i",&colonne);
        printf("choisir le pion: ");
        scanf(" %c",&pion);
        printf("\n");
    
    } while(jouer(grille,colonne,pion,joueur) == 0);
			
    

}

int main(){
	int i=0,colonne,joueur=1,nbr_joueur,j=1;
	char pion;
	
	Pion grille[N][M];
	initialiser_grille(grille);
	afficher_grille(grille);
	do
	{
		printf("\nveuillez choisir le nombre des joueurs (maximum : ");
		scanf("%i",&nbr_joueur);
	}while(nbr_joueur<2 || nbr_joueur>4);
   
	printf(" ici \n");
	while(i<nb_case){						//tant que la partie n'est pas finie
		
		if(nbr_joueur){
		
        
				printf("\n\n\t\t==============## Joueur %i ##================\n\n",joueur);
		
				faire_jouer(joueur,grille);
				afficher_grille(grille);
				victoire(grille,joueur);
				if(joueur==nbr_joueur)
				joueur=0;
				
				i++;	
				joueur++;
				
			
			
		}
		
	}
	
}
