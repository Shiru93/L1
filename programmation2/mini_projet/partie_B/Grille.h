#ifndef _GRILLE_H_
#define _GRILLE_H_

typedef enum elements_grille {
    RIEN,
    MUR,
    PION,
    PIEGE,
    ARME,
    MONSTRE,
    BOSS
} Elements;

typedef struct Grille {
    int n;
    int m;
    Elements ** tab;
} Grille;

Grille * Grille_initialiser(int n, int m);
void Grille_desallouer(Grille *g);
void Grille_vider(Grille *g);
void Grille_redessiner(Grille *g);

#endif