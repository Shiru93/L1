#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Pion.h"
#include "Grille.h"
#include "Fonctions_jeu.h"
#include "Fonctions_UNDO.h"

Pion * Pion_allouer(int x, int y){
    Pion * p = malloc(sizeof(Pion));
    if(!p){
        puts("Erreur allocation mÃ©moire");
        exit(1);
    }

    p->x = x;
    p->y = y;
    p->x_old = x;
    p->y_old = y;

    return p;
}

void Pion_desallouer(Pion * p){
    free(p);
}

void Pion_placer(Grille * g, Pion * p){
    g->tab[p->x][p->y] = PION;
}

Deplacements touche_deplacement() {
    switch(getch()){
        case KEY_UP: return HAUT;
        case KEY_DOWN: return BAS;
        case KEY_RIGHT: return DROITE;
        case KEY_LEFT: return GAUCHE;
        case 27: return ECHAP;
        case 'Z':
        case 'z':
            return ANNULER;
        default: return AUCUN;
    }
}

void Pion_deplacer(Grille * g, Pion * p, Deplacements direction, int * tmp, Positions * m, Listes * l){
    Positions * ancien;
    p->x_old = p->x;
    p->y_old = p->y;

    switch(direction){
        case ECHAP:
            clear();
            nodelay(stdscr, FALSE);
            printw("Vous avez appuyé sur la touche ECHAP\n");
            printw("Vous quittez le jeu\n");
            refresh();
            getch();
            *tmp = 1;
            return;

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

        case ANNULER:
            if(l->taille > 0){
                m = acceder_liste(l, 0);
                g->tab[p->x][p->y] = m->contenu_case;
                p->x = m->x;
                p->y = m->y;
                ancien = extraire_maillon_debut_liste(l);
                afficher_liste(l);
                detruire_maillon(ancien);
                getch();
            }
            break;

        default:
            return;
    }

    heurter_mur(p, g);

    g->tab[p->x_old][p->y_old] = RIEN;
    heurter_piege(g, p, tmp, m);
    heurter_arme(g, p, m);
    Pion_placer(g, p);
}