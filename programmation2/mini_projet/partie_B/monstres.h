#ifndef _MONSTRES_H_
#define _MONSTRES_H_

#include "Grille.h"

#define TAILLE_NOM 10

typedef struct monsters {
    char nom[TAILLE_NOM];
    int x;
    int y;
    float pv;
    float atk;
    float def;
} Monstres;

Monstres * monstres_allouer(char nom[], float pv, float atk, float def);
void monstres_desallouer(Monstres * m);
// void boss_placer(Grille * g, Monstres ** tab, int x, int y);
Monstres ** creer_tableau_monstres(int taille);
void ajouter_monstres(Monstres ** tableau, int index, char nom[], float pv, float atk, float def);
void supprimer_tableau_monstres(Monstres ** tab, int taille);
void statistiques_monstres(Monstres ** tableau);
Monstres ** creer_tableau_boss(int taille);
void supprimer_tableau_boss(Monstres ** tab, int taille);
void ajouter_boss(Monstres ** tableau, int index, char nom[], float pv, float atk, float def);
void statistiques_boss(Monstres ** tableau);
void informations_monstres(Monstres ** tab, int x);

#endif