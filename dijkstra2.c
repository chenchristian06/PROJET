//
//  dijkstra.c
//  Projet1A
//
//  Created by Chen Christian on 13/04/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#include "dijkstra2.h"
#include <stdio.h>
#include <stdlib.h>

//Dijkstra
long* creer_pere(long nb_sommets){
/*on créer un tableau de pere ou l'indice est le pere et le contenu est l'antécédent*/
    long* tab_pere;
    tab_pere = calloc(nb_sommets,sizeof(long));
    long i = 0;
    for(;i<nb_sommets;i++){
        *(tab_pere+i) = -1;
    }
    return tab_pere;
}

TAS* creer_poids2(long nb_sommets){
    /*on crée le tas des poids ou à l'indice 0 on a le départ */
    long* tab_poids;
    tab_poids = calloc(nb_sommets,sizeof(long));
    long i = 0;
    for(;i<nb_sommets;i++){
        *(tab_poids+i) = 0xfffff;
    }
    return tab_poids;
}





    




