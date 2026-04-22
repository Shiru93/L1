#ifndef _LISTE_H_
#define _LISTE_H_

typedef struct maillon_s {
    int numero; // Numéro de l'usager
    struct maillon_s * suiv; // Pointeur sur l'élèment suivant
} maillon;

typedef struct {
    maillon * debut; // Pointeur sur premier élèment de la liste
    int taille; // Nombre de maillon dans la liste
} Liste;

maillon * creer_maillon();
void ajout_en_tete(Liste * L, int num);
void affichage_liste(Liste L);
void suppression_en_fin(Liste * L);

#endif