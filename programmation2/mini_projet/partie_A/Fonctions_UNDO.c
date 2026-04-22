#include <stdio.h>
#include <stdlib.h>
#include "Fonctions_UNDO.h"
#include "Pion.h"

Positions * creer_maillon(Pion * p, Grille * g){
    Positions * res = malloc(sizeof(Positions));
    res->x = p->x;
    res->y = p->y;
    res->suivant = NULL;

    return res;
}

void detruire_maillon(Positions * m){
    free(m);
}

Listes * initialiser_liste_vide(){
    Listes * res = malloc(sizeof(Listes));
    res->debut = NULL;
    res->taille = 0;

    return res;
}

int test_liste_vide(Listes l){
    if(l.taille == 0) return 1;

    return 0;
}

unsigned int cardinal_liste(Listes l){
    return l.taille;
}

void afficher_liste(Listes * l){
    Positions * cour;
    for(cour = l->debut; cour != NULL; cour = cour->suivant)
        printf("Positions (x, y) et contenu de la case : %d, %d, %d\n\r", cour->x, cour->y, cour->contenu_case);
}

/* int test_appartenir_liste(Listes l, int x, int y){
    Positions * cour = l.debut;
    while(cour != NULL){
        if(cour->x == x && cour->y == y) return 1;
        cour = cour->suivant;
    }

    return 0;
} */

Positions * acceder_liste(Listes * l, unsigned int pos){
    Positions * m;
    for(m = l->debut; m != NULL && pos != 0; pos--) m = m->suivant;

    return m;
}

void ajouter_maillon_debut_liste(Listes * l, Positions * m){
    m->suivant = l->debut;
    l->debut = m;
    l->taille++;
}

Positions * extraire_maillon_debut_liste(Listes * l){
    Positions * res = l->debut;
    if(res != NULL){
        l->debut = res->suivant;
        l->taille--;
        res->suivant = NULL;
    }

    return res;
}

void liste_detruire(Listes * l){
    while(!test_liste_vide(*l))
        detruire_maillon(extraire_maillon_debut_liste(l));

    free(l);
}

void suppression_en_fin(Listes * l){
    Positions * cour = NULL;
    if(!l || !l->debut) return;

    if(!l->debut->suivant){
        free(l->debut);
        l->debut = NULL;
    } else {
        cour = l->debut;
        while(cour->suivant->suivant)
            cour = cour->suivant;

        free(cour->suivant);
        cour->suivant = NULL;
    }

    l->taille--;
}