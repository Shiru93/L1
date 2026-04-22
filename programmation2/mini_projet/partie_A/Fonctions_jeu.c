#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "Fonctions_jeu.h"
#include "Fonctions_UNDO.h"

void heurter_mur(Pion * p, Grille * g){
    if(g->tab[p->x][p->y] == MUR){
        p->x = p->x_old;
        p->y = p->y_old;
    }
}

int heurter_piege(Grille * g, Pion * p, int * tmp, Positions * m){
    if(g->tab[p->x][p->y] == PIEGE){
        (*tmp)++;
        clear();
        attron(COLOR_PAIR(1));
        printw("Vous êtes tombés dans un piège !");
        attroff(COLOR_PAIR(1));
        fflush(stdout);
        refresh();
        getch();
    }

    m->contenu_case = g->tab[p->x][p->y];

    return * tmp;
}

void heurter_arme(Grille * g, Pion * p, Positions * m){
    
    if(g->tab[p->x][p->y] == ARME){
        clear();
        attron(COLOR_PAIR(1));
        printw("Vous avez récupérer une arme");
        attroff(COLOR_PAIR(1));
        fflush(stdout);
        refresh();

        getch();
    }   

    m->contenu_case = g->tab[p->x][p->y];
}