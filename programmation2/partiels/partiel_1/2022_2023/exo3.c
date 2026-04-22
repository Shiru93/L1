#include <stdio.h>
#include <stdlib.h>

struct date {
    unsigned jour; // rang (1-31) du jour dans le mois
    unsigned mois; // rang (1-12) du mois dans l'année
    unsigned annee;
};

struct client {
    char nom[40]; // Nom du client
    struct date arr; // Début du séjour du client dans l'hotel
    struct date dep; // Fin du séjour du client dans l'hotel
};

int precede(struct date date1, struct date date2);
void trier_tab_arrivee(struct client *T[], int taille);

int main(){


    return 0;
}

int precede(struct date date1, struct date date2) {
    if (date1.annee < date2.annee) return -1;
    if (date1.annee > date2.annee) return 1;

    if (date1.mois < date2.mois) return -1;
    if (date1.mois > date2.mois) return 1;

    if (date1.jour < date2.jour) return -1;
    if (date1.jour > date2.jour) return 1;

    return 0;
}

void trier_tab_arrivee(struct client *T[], int taille){
    int pos_min, j;
    struct client *tmp;
    for(int i = 0; i < taille - 1; i++){
        pos_min = i;
        for(j = i + 1; j < taille; j++)
            if(precede(T[j]->arr, T[pos_min]->arr) == -1) pos_min = j;

        if(pos_min != i) {
            tmp = T[pos_min];
            T[pos_min] = T[j];
            T[j] = tmp;
        }
    }
}

void afficher_tab(struct client *T[], int taille){
    for(int i = 0; i < taille; i++)
        printf("%s : %d/%d/%d -> %d/%d/%d\n", T[i]->nom, T[i]->dep.jour, T[i]->dep.mois, T[i]->dep.annee, T[i]->arr.jour, T[i]->arr.mois, T[i]->dep.annee);
}