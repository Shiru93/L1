#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "monstres.h"
#include "Grille.h"

// Fonction qui permet d'allouer les monstres
Monstres * monstres_allouer(char nom[], float pv, float atk, float def){
    Monstres * monster = malloc(sizeof(Monstres));
    if(!monster){
        puts("Erreur allocation mémoire");
        exit(2);
    }

    
    strcpy(monster->nom, nom);
    monster->pv = pv;
    monster->atk = atk;
    monster->def = def;

    return monster;
}

// Fonction qui désalloue les mosntres
void monstres_desallouer(Monstres * m){
    free(m);
}

/* void boss_placer(Grille * g, Monstres ** tab, int pos_x, int pos_y){
    int dante_or_vergil = rand() % 2;
    tab[dante_or_vergil]->x = pos_x;
    tab[dante_or_vergil]->y = pos_y;
    g->tab[tab[dante_or_vergil]->x][tab[dante_or_vergil]->y] = BOSS;
} */

// Fonction qui créé un tableau qui va contenir la liste des monstres
Monstres ** creer_tableau_monstres(int taille){
    Monstres ** tableau = malloc(taille * sizeof(Monstres *));
    if(!tableau){
        puts("Erreur allocation mémoire");
        exit(2);
    }

    for(int i = 0; i < taille; i++)
        tableau[i] = NULL;

    return tableau;
}

// Fonction qui désalloue le tableau de monstres
void supprimer_tableau_monstres(Monstres ** tab, int taille){
    for(int i =0; i < taille; i++)
        if(tab) monstres_desallouer(tab[i]);

    free(tab);
}

// Fonction qui ajoute les monstres dans le tableau qui contient les monstres
void ajouter_monstres(Monstres ** tableau, int index, char nom[], float pv, float atk, float def){
    tableau[index] = monstres_allouer(nom, pv, atk, def);
}

// Fonction contenant la liste de tous les monstres (va les ajouter dans le tableau)
void statistiques_monstres(Monstres ** tableau){
    ajouter_monstres(tableau, 0, "Arkham", 120.0, 11.23, 10.0);
    ajouter_monstres(tableau, 1, "Mundus", 450.0, 256.54, 78.63);
    ajouter_monstres(tableau, 2, "Urizen", 1000.0, 750.0, 50.0);
    ajouter_monstres(tableau, 3, "Eva", 75.0, 5.0, 5.0);
    ajouter_monstres(tableau, 4, "Kyrie", 50.0, 5.0, 5.0);
    ajouter_monstres(tableau, 5, "Nico", 45.0, 5.0, 5.0);
    ajouter_monstres(tableau, 6, "Dante", 1250.0, 950.78, 150000.12);
    ajouter_monstres(tableau, 7, "Vergil", 1250.0, 977.64, 129640.45);
}

// Fonction qui va créé un tableau qui contiendra les boss
Monstres ** creer_tableau_boss(int taille){
    Monstres ** tableau = malloc(taille * sizeof(Monstres *));
    if(!tableau){
        puts("Erreur allocation mémoire");
        exit(2);
    }

    for(int i = 0; i < taille; i++)
        tableau[i] = NULL;

    return tableau;
}

// Fonction qui supprime le tableau de boss
void supprimer_tableau_boss(Monstres ** tab, int taille){
    for(int i =0; i < taille; i++)
        if(tab) monstres_desallouer(tab[i]);

    free(tab);
}

// Même chose que la fonction ajouter_boss
void ajouter_boss(Monstres ** tableau, int index, char nom[], float pv, float atk, float def){
    tableau[index] = monstres_allouer(nom, pv, atk, def);
}

// Même chose que la fonction statistiques_monstres
void statistiques_boss(Monstres ** tableau){
    ajouter_boss(tableau, 0, "Dante", 125000.0, 950.78, 150000.12);
    ajouter_boss(tableau, 1, "Vergil", 125000.0, 977.64, 129640.45);
}

// Fonction qui affiche les informations du monstre
void informations_monstres(Monstres ** tab, int x){
    printw("NOM : %s\nPV : %.3f\nATK : %.3f\nDEF : %.3f\n", tab[x]->nom, tab[x]->pv, tab[x]->atk, tab[x]->def);
}