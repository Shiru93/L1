#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "Grille.h"
#include "Pion.h"
#include "Fonctions_jeu.h"
#include "monstres.h"
#include "armes.h"

#define TRUE 1
#define FALSE 0

#define P_X 1 // Position x du pion
#define P_Y 1 // Position y du pion

/* #define B_X 28
#define B_Y 28 */

#define N 30 // Nombre de colonnes
#define M 30 // Nombre de lignes

#define TAILLE_TAB_MONSTRES 8 // Taille du tableau contenant les monstres
#define TAILLE_TAB_BOSS 2 // Taille du tableau contenant les boss

#define TAILLE_TAB_ARMES 9 // Taille du tableau contenant les armes

int main(){
    Grille * g;
    Pion * p;
    Deplacements d;
    Monstres ** monstres;
    Monstres ** boss;
    Armes ** armes;
    int tmp = 0;

    srand(time(NULL));
    
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    
    g = Grille_initialiser(N, M);
    p = Pion_allouer(P_X, P_Y);
    monstres = creer_tableau_monstres(TAILLE_TAB_MONSTRES);
    boss = creer_tableau_boss(TAILLE_TAB_BOSS);
    armes = creer_tableau_Armes(TAILLE_TAB_ARMES);

    statistiques_monstres(monstres);
    statistiques_boss(boss);
    statistiques_armes(armes);

    Pion_placer(g, p);
    // boss_placer(g, boss, 28, 28);
    refresh();
    
    // Permet d'effacer tout ce qu'il y avait dans le terminal juste avant
    // system pour accéder aux commandes linux et clear qui est une commande Linux
    // system("clear");

    histoire_jeu();
    
    while(tmp == 0) {
        Grille_redessiner(g);
        d = touche_deplacement();
        
        Pion_deplacer(g, p, d, monstres, &tmp, armes, boss);
        clear();
        refresh();
    }
    
    Grille_desallouer(g);
    Pion_desallouer(p);
    supprimer_tableau_monstres(monstres, TAILLE_TAB_MONSTRES);
    supprimer_tableau_boss(boss, TAILLE_TAB_BOSS);
    supprimer_tableau_armes(armes, TAILLE_TAB_ARMES);

    endwin();

    return EXIT_SUCCESS;
}