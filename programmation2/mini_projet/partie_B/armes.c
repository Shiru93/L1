#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "armes.h"

// Fonction qui alloue les armes
Armes * armes_allouer(char nom[], float pv, float atk, float def){
    Armes * arme = malloc(sizeof(Armes));

    strcpy(arme->nom, nom);
    arme->pv = pv;
    arme->atk = atk;
    arme->def = def;

    return arme;
}

// Fonctions qui désalloue les armes
void armes_desallouer(Armes * a){
    free(a);
}

// Fonction qui créé un tableau qui va contenir la liste des armes
Armes ** creer_tableau_Armes(int taille){
    Armes ** tab = malloc(taille * sizeof(Armes *));

    for(int i = 0; i < taille; i++)
        tab[i] = NULL;

    return tab;
}

// Fonction qui va permettre d'ajouter des armes dans le tableau d'armes
void ajouter_armes(Armes ** tableau, int index, char nom[], float pv, float atk, float def){
    tableau[index] = armes_allouer(nom, pv, atk, def);
}

// Fonction qui va supprimer le tableau d'armes
void supprimer_tableau_armes(Armes ** tab, int taille){
    for(int i = 0; i < taille; i++)
        if(tab) armes_desallouer(tab[i]);

    free(tab);
}

// Fonction qui va rajouter les armes dans le tableau
void statistiques_armes(Armes ** tableau){
    ajouter_armes(tableau, 0, "DragonSlayer", 0, 100, 100);
    ajouter_armes(tableau, 1, "X-Gun", 0, 75, 0);
    ajouter_armes(tableau, 2, "LostVayne", 75, 25, 0);
    ajouter_armes(tableau, 3, "Kikoku", 0, 25, 0);
    ajouter_armes(tableau, 4, "Excalibur", 100, 100, 100);
    ajouter_armes(tableau, 5, "Harkonnen", 0, 125, 25);
    ajouter_armes(tableau, 6, "Punisher", 0, 125, -75);
    ajouter_armes(tableau, 7, "Riyujin Jakka", 0, 150, -50);
    ajouter_armes(tableau, 8, "Dominator", 0, 50, -50);
}