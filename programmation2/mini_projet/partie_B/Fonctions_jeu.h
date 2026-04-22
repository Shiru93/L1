#ifndef _FONCTIONS_JEU_
#define _FONCTIONS_JEU_

#include "Pion.h"
#include "monstres.h"
#include "armes.h"

void heurter_mur(Pion * p, Grille * g);
void heurter_piege(Grille * g, Pion * p, Monstres ** tab, int * tmp);
void heurter_arme(Grille * g, Pion * p, Armes ** tab);
void combat(Pion * p, Monstres ** tab, int x);
void attaque_monstre(Pion * p, Monstres ** tab, int x);
void game_over(Pion * p, int * tmp);
int victoire(Monstres ** tab, int x, Pion * p);
void affrontement_boss(Grille * g, Monstres ** tab, Pion * p, int x, int * tmp);
void heurter_boss(Grille * g, Pion * p, Monstres ** tab, int * tmp);
void defaite_boss(Monstres ** tab, Pion * p, int x, int * tmp);
void fin_secrete(int * tmp);
void fin_classique(int * tmp);
void histoire_jeu();

#endif