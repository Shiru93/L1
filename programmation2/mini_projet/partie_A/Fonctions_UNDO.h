#ifndef _FONCTIONS_UNDO_
#define _FONCTIONS_UNDO_

#include "Grille.h"

typedef struct Pion Pion; 

typedef struct maillons {
    int x;
    int y;
    Elements contenu_case;
    struct maillons * suivant;
} Positions;

typedef struct listes {
    Positions * debut;
    unsigned int taille;
} Listes;

Positions * creer_maillon(Pion * p, Grille * g);
void detruire_maillon(Positions * m);

Listes * initialiser_liste_vide();
int test_liste_vide(Listes l);
unsigned int cardinal_liste(Listes l);
void afficher_liste(Listes * l);
/* int test_appartenir_liste(Listes l, int x, int y); */
Positions * acceder_liste(Listes * l, unsigned int pos);
void ajouter_maillon_debut_liste(Listes * l, Positions * m);
Positions * extraire_maillon_debut_liste(Listes * l);
void liste_detruire(Listes * l);
void suppression_en_fin(Listes * l);

#endif