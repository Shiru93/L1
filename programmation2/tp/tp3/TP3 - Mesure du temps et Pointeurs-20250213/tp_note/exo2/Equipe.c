#include <string.h>

#include "Equipe.h"

void affiche_equipe(const Equipe *eq){
    puts("Listes des Equipes :");
    for(int i = 0; i < NB_EQUIPES; i++)
        printf("Equipe #%d : %s %d points (G: %d N: %d P: %d B: %d)\n", i+1, eq[i].nom, eq[i].nb_points, eq[i].nb_victoires, eq[i].nb_nuls, eq[i].nb_defaites, eq[i].nb_bonus);
}

Equipe* rech_ptr_equipe(Equipe Teq[], int n, char nom[]){
    for(int i = 0; i < n; i++)
        if(strcmp(Teq[i].nom, nom) == 0) return &Teq[i];

    return NULL;
}

void calcul_points(Equipe Teq[], int n){
    for(int i = 0; i < n; i++){
        Teq[i].nb_points = (Teq[i].nb_victoires * 4) + (Teq[i].nb_nuls * 2) + Teq[i].nb_bonus;
    }
}

Equipe* premier_classement(Equipe Teq[], int n){
    int i, j;
    for(i = 1; i < n; i++){
        j = i;

        while(j > 0 && Teq[j].nb_points > Teq[j - 1].nb_points){
            Equipe tmp = Teq[j - 1];
            Teq[j - 1] = Teq[j];
            Teq[j] = tmp;
            j--;
        }
    }

    return Teq;
}

int max_indice(Equipe Teq[], int n, int d){
    int indice = d;
    for(int i = d + 1; i < n; i++)
        if(Teq[i].nb_points > Teq[indice].nb_points)
            indice = i;

    return indice;
}

void trier_equipes(Equipe Teq[], int n){
    int i, pos_min;
    for(i = 0; i < n - 1; i++){
        pos_min = max_indice(Teq, n, i);

        if(pos_min != i){
            Equipe tmp = Teq[i];
            Teq[i] = Teq[pos_min];
            Teq[pos_min] = tmp;
        }
    }
}