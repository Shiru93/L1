#ifndef _PION_H_
#define _PION_H_

#include "Grille.h"
#include "Fonctions_UNDO.h"

typedef enum deplacements_pion {
    HAUT,
    BAS,
    DROITE,
    GAUCHE,
    AUCUN,
    ANNULER,
    ECHAP
} Deplacements;

typedef struct Pion {
    int x;
    int y;
    int x_old;
    int y_old;
} Pion;

Pion * Pion_allouer(int x, int y);
void Pion_desallouer(Pion * p);
void Pion_placer(Grille * g, Pion * p);
Deplacements touche_deplacement();
void Pion_deplacer(Grille * g, Pion * p, Deplacements direction, int * tmp, Positions * m, Listes * l);

#endif