#ifndef _GRILLE_H_
#define _GRILLE_H_

typedef enum elements_grille {
    RIEN,
    MUR,
    PION,
    PIEGE,
    ARME
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
void Grille_charger_fichier(const Grille * g, const char * fichier);

#endif