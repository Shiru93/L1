#ifndef _FONCTIONS_JEU_
#define _FONCTIONS_JEU_

#include "Pion.h"

void heurter_mur(Pion * p, Grille * g);
int heurter_piege(Grille * g, Pion * p, int * tmp, Positions * m);
void heurter_arme(Grille * g, Pion * p, Positions * m);

#endif