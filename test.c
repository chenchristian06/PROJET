//
//  test.c
//  tritas
//
//  Created by Chen Christian on 14/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include <stdio.h>
#include "graphe.h"
#include "dijkstra.h"
#include "hachage.h"
#include "tas.h"
int main(){
    /*---DEBUT CREATION GRAPHE---*/
    T_SOMMET* g;
    //char nom_fichier[512];
    //printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    char* nom_fichier="/Users/chenchristian/Documents/grapheNewYork.csv";
    g = creer_graphe();
    long nb_sommets;
    long nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    printf("ce graphe contient %ld sommets \n",nb_sommets);
    //visualiser_graphe(g,&nb_sommets,&nb_arcs);
    //printf("le graphe crée\n");
    /*---FIN---*/
    /*---DEBUT DIJKSTRA---*/
    long depart;
    long arrivee;
    long* pere;
    TAS* pcc;
    printf("Donner depart\n");
    scanf("%ld",&depart);
    printf("Donner arrivee\n");
    scanf("%ld",&arrivee);
    long j;
    long taille_tas = nb_sommets;
    double poids;
    pere = creer_pere(nb_sommets);
    pcc = creer_poids(nb_sommets,depart,g);
    do{
        j = pcc[0].sommet;
        poids = pcc[0].poids;
        supprime_tete_tas(pcc, taille_tas , g);
        //printf("tête supprimé: %ld \n",j);
        /*long i;
        for(i=0;i<nb_sommets;i++){
            printf("%ld , sommet : %ld de poids %lf \n",i,pcc[i].sommet,pcc[i].poids);
        }*/
        taille_tas -= 1;
        L_ARC l = g[j].voisins;
        while(l!=NULL){
            long k = (l->val).arrivee;
            //printf("voisin : %ld \n",k);
            double cjk = (l->val).cout;
            if(pcc[g[k].position_tas].poids > poids + cjk ){
                pcc[g[k].position_tas].poids = poids + cjk;
                pere[k] = j;
                //long i;
                pcc = augmentetas(pcc,g[k].position_tas, g);
                /*for(i=0;i<nb_sommets;i++){
                    printf("%ld , sommet : %ld de poids %lf \n",i,pcc[i].sommet,pcc[i].poids);
                }*/
            }
            
            l = l->suiv;
        }
    }while((j!=arrivee)&&(pcc[g[j].position_tas].poids!=0xffffffff));
if(j!=arrivee){
    puts("Pas de chemin possible \n");
}
else{
    printf("fin <-%ld <- ",arrivee);
    long x=arrivee;
    do{
        printf("%ld <- ",pere[x]);
        x=pere[x];
    }while(x!=depart);
    puts("début\n");
}
    
}
