#ifndef _PION_H_
#define _PION_H_

#include "Grille.h"
#include "monstres.h"
#include "armes.h"

typedef enum deplacements_pion {
    HAUT,
    BAS,
    DROITE,
    GAUCHE,
    AUCUN
} Deplacements;

typedef struct Pion {
    int x;
    int y;
    int x_old;
    int y_old;
    float pv;
    float atk;
    float def;
    int compteur_arme;
} Pion;

Pion * Pion_allouer(int x, int y);
void Pion_desallouer(Pion * p);
void Pion_placer(Grille * g, Pion * p);
Deplacements touche_deplacement();
void Pion_deplacer(Grille * g, Pion * p, Deplacements direction, Monstres ** tab_monstres, int * tmp, Armes ** tab_armes, Monstres ** tab_boss);
void Pion_informations(Pion * p);

#endif