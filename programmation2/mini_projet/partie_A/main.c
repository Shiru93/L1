#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Grille.h"
#include "Pion.h"
#include "Fonctions_jeu.h"
#include "Fonctions_UNDO.h"

#define TRUE 1
#define FALSE 0

#define P_X 1
#define P_Y 1

int main(){
    Grille * g;
    Pion * p;
    Positions * maillon;
    Listes * l;
    Deplacements d;
    int n, m; 
    int tmp = 0;
    
    printf("Veuillez préciser les dimensions de votre grille :\n");
    printf("Nombre de lignes : ");
    scanf("%d", &n);
    printf("Nombre de colonnes : ");
    scanf("%d", &m);
    
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    
    g = Grille_initialiser(n, m);
    p = Pion_allouer(P_X, P_Y);
    maillon = creer_maillon(p, g);
    l = initialiser_liste_vide();

    Pion_placer(g, p);
    refresh();

    Grille_charger_fichier(g, "ma_grille.txt");

    
    // Permet d'effacer tout ce qu'il y avait dans le terminal juste avant
    // system pour accéder aux commandes linux et clear qui est une commande Linux
    // system("clear");

    
    while(tmp == 0) {
        Grille_redessiner(g);
        d = touche_deplacement();
        if(d != ANNULER && d != AUCUN){
            maillon = creer_maillon(p, g);
            ajouter_maillon_debut_liste(l, maillon);
        }
        Pion_deplacer(g, p, d, &tmp, maillon, l);
        clear();
        refresh();
    }
    
    Grille_desallouer(g);
    Pion_desallouer(p);

    endwin();

    return EXIT_SUCCESS;
}