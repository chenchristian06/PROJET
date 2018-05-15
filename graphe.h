#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>

//DEBUT_DEF_STRUCT


// description/valeur d'un voisin
typedef struct{
    long arrivee;
    double cout;
} T_ARC;


// structure d'un voisin
typedef struct lsucc{
    T_ARC val;
    struct lsucc* suiv;
}* L_ARC;


//Structure d'un sommet
typedef struct{
    char* nom;
    long position_tas;
    double x,y;
    L_ARC voisins;
} T_SOMMET;




//Liste fonctions
T_SOMMET* creer_graphe(void);
T_SOMMET* creation_graphe(T_SOMMET* g,char* nom_fichier,long* pnb_sommets,long* pnb_arcs);
L_ARC ajout_teteG(T_ARC k,L_ARC l);
L_ARC creer_L_ARC(void);
void visualiser_graphe(T_SOMMET* g,long* pnb_sommets,long* pnb_arcs);

#endif /* graph_h */
