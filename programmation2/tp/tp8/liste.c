#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

maillon * creer_maillon(int num){
    maillon * a = (maillon *)malloc(sizeof(maillon));

    if(!a){
        puts("Erreur allocation mémoire");
        return NULL;
    }

    a->numero = num;
    a->suiv = NULL;

    return a;
}

void ajout_en_tete(Liste * L, int num){
    if(!L){
        printf("Erreur allocation mémoire\n");
        exit(1);
    }

    maillon * nouveau = creer_maillon(num);
    
    if(!nouveau) return;

    nouveau->suiv = L->debut;
    L->debut = nouveau;
    L->taille++;
}

void affichage_liste(Liste L){
    maillon * courant = L.debut;
    printf("Liste (taille = %d) : ", L.taille);
    while(courant) {
        printf("%d -> ", courant->numero);
        courant = courant->suiv;
    }

    printf("NULL\n");
}

void suppression_en_fin(Liste * L){
    maillon * courant = NULL;
    if(!L || !L->debut) return;

    if(!L->debut->suiv){
        free(L->debut);
        L->debut = NULL;
    } else {
        courant = L->debut;
        while(courant->suiv->suiv)
            courant = courant->suiv;

        free(courant->suiv);
        courant->suiv = NULL;
    }

    L->taille--;
}