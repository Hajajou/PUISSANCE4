#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 7
#define VIDE 0
#define CREUX 'c'
#define BLOC 'b'
#define PLEIN 'p'
#define nb_case N*M

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


void victoire (Pion grille[N][M]){
 int nbp,ligne,colonne,num_joueur;
 	
					num_joueur=1;  // pour verifier chaque joueur
        			nbp=0; //  nombre de pion même couleur
        			
    	for(colonne=1;colonne<M;colonne++)
    	{

    		nbp=0; //  nombre de pion même couleur
    		
    		for(ligne=5;ligne>=0;ligne--)
    		{
    
				
					if(grille[ligne][colonne-1].pleine== 1) 
    				{
    					nbp++;
    					printf(" %i  ok du joueur 1 \n",nbp);
    				}
    				else
    				nbp=0; //  nombre de pion même couleur
    					
    			
    		}
    			
	}
    	if( nbp >=4)
    		printf(" ok ok ok ok ok \n");
    	
    
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
				if(joueur==nbr_joueur)
				joueur=0;
				afficher_grille(grille);
				i++;
				joueur++;
				
				victoire(grille);
			
		}
		
	}
	
}
