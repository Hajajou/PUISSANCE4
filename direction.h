
#ifndef _direction_h
#define _direction_h

#define ABS 0
#define ORD 0


typedef enum {NORD=0, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST} t_dir;

int direction_suivante(int dir); // donne la direction suivante, sens horaire
int valeur_suivante_abs(t_dir dir, int val);
int valeur_suivante_ord(t_dir dir, int val);


#endif

void Lancer_Jeu();
