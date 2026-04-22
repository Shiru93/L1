#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Pion.h"
#include "Grille.h"
#include "Fonctions_jeu.h"
#include "monstres.h"

// Fonction qui alloue le pion et qui initialise ses positions et stats
Pion * Pion_allouer(int x, int y){
    Pion * p = malloc(sizeof(Pion));
    if(!p){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    p->x = x;
    p->y = y;

    p->x_old = x;
    p->y_old = y;

    p->pv = 100.0;
    p->atk = 15.0;
    p->def = 10.0;

    p->compteur_arme = 0;

    return p;
}

// Fonction qui désalloue le pion
void Pion_desallouer(Pion * p){
    free(p);
}

// Fonction qui place le pion dans la grille (utilisé notamment pour le déplacement du pion dans la grille)
void Pion_placer(Grille * g, Pion * p){
    g->tab[p->x][p->y] = PION;
}

// Fonction utilisé dans la fonction Pion_deplacer qui va capter les touches du clavier et renvoyer un enum ce qui fera changer les coordonnées du pion
Deplacements touche_deplacement() {
    switch(getch()){
        case KEY_UP: return HAUT;
        case KEY_DOWN: return BAS;
        case KEY_RIGHT: return DROITE;
        case KEY_LEFT: return GAUCHE;
        default: return AUCUN;
    }
}

// Fonction qui permet de dépacer le pion
void Pion_deplacer(Grille * g, Pion * p, Deplacements direction, Monstres ** tab_monstres, int * tmp, Armes ** tab_armes, Monstres ** tab_boss){
    p->x_old = p->x;
    p->y_old = p->y;

    switch(direction){
        case HAUT:
            p->x--;
            break;

        case BAS:
            p->x++;
            break;

        case DROITE:
            p->y++;
            break;

        case GAUCHE:
            p->y--;
            break;

        default:
            return;
    }

    heurter_mur(p, g);

    g->tab[p->x_old][p->y_old] = RIEN;
    heurter_piege(g, p, tab_monstres, tmp);
    heurter_boss(g, p,tab_boss, tmp);
    heurter_arme(g, p, tab_armes);
    Pion_placer(g, p);
}

// Fonction qui affiche les informations du pion (utilisé notamment lors d'un combat)
void Pion_informations(Pion * p){
    printw("Informations du joueur : \n");
    printw("PV : %.3f\nATK : %.3f\nDEF : %.3f\n", p->pv, p->atk, p->def);
}