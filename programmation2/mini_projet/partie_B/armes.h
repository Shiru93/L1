#ifndef _ARMES_H_
#define _ARMES_H_

#include "Grille.h"

#define TAILLE_NOM_ARMES 10

typedef struct armes {
    char nom[TAILLE_NOM_ARMES];
    float pv;
    float atk;
    float def;
} Armes;

Armes * armes_allouer(char nom[], float pv, float atk, float def);
void armes_desallouer(Armes * a);
Armes ** creer_tableau_Armes(int taille);
void ajouter_armes(Armes ** tableau, int index, char nom[], float pv, float atk, float def);
void supprimer_tableau_armes(Armes ** tab, int taille);
void statistiques_armes(Armes ** tableau);

#endif