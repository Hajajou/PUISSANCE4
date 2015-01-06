
#include <stdio.h>
#include "direction.h"

/**
* \file direction.h
* \author Yassine M'chaar And Ilyess Hajajou
* \date 04 Décembre 2014
* \brief ce fichier contient une fonction qui sert à preciser la direction suivante pour definir la fonction diagonale. 
* */


/**
* \fn int direction_suivante(int dir)
* \donne la direction suivante, sens horaire.
*/
int direction_suivante(int dir) 
{
    return (dir+1)%8;
}

int valeur_suivante_abs(t_dir dir, int val)
{
    int res=val;
    if(dir==SUDOUEST || dir==SUD || dir==SUDEST ) res++;
    else if(dir==NORD|| dir==NORDOUEST || dir==NORDEST ) res--;
    
    return res;
}

int valeur_suivante_ord(t_dir dir, int val)
{
    int res=val;
    if(dir==EST || dir==NORDEST || dir==SUDEST ) res++;
    else if(dir==OUEST || dir==NORDOUEST || dir==SUDOUEST ) res--;
    
    return res;
}








