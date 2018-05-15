//
//  main.c
//  tritas
//
//  Created by Chen Christian on 14/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

int main(){
    double* tab;
    tab = calloc(10,sizeof(double));
    int i ;
    double x;
    for(i=0;i<10;i++){
        tab[i] = rand_a_b(1,20);
    }
    affichage(tab,10);
    printf("Construction du tas \n");
    tab = constructiontas(tab,10);
    affichage(tab,10);
    printf("kndqsgklnkldfsngl");
    /*
     puts("\n \n");
     tri(tab,10);
     affichage(tab,10);
     */
}
