#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flotte_voiture.h"

#define IMMA_MIN 10000000
#define IMMA_MAX 99999999

#define KM_MIN 5000
#define KM_MAX 200000

#define ELECTRIQUE 1
#define ESSENCE 0

#define TRUE 1
#define FALSE 0

Flotte* creer_flotte(int n) {
    Flotte * voitures = malloc(sizeof(Flotte));
    if(!voitures){
        printf("Erreur allocation mémoire\n");
        exit(2);
    }
    
    voitures->nb_voitures = n;

    voitures->TabV = malloc(n * sizeof(Voiture*));
    if(!voitures->TabV){
        free(voitures);
        printf("Erreur allocation mémoire\n");
        exit(2);
    }

    for(int i = 0; i < n; i++)
        voitures->TabV[i] = NULL;

    return voitures;
}

void initialisee_random(Flotte *F) {
    for(int i = 0; i < F->nb_voitures; i++){
        F->TabV[i] = malloc(sizeof(Voiture));
        if(!F->TabV[i]){
            printf("Erreur allocation mémoire\n");
            exit(2);
        }

        F->TabV[i]->immatriculation = IMMA_MIN + rand() % (IMMA_MAX - IMMA_MIN + 1);
        F->TabV[i]->nb_kilometres = KM_MIN + rand() % (KM_MAX - KM_MIN + 1);
        F->TabV[i]->type = (rand() % 101 <= 60) ? ELECTRIQUE : ESSENCE;
    }
}

void affiche(Flotte* F) {
    printf("Voiture numéro\t\tImmatriculation\t\tNb_kilomètre\t\tType\n");
    for(int i = 0; i < F->nb_voitures; i++){
        printf("#%-12d\t\t%14d\t\t%12d\t\t%4s\n", i+1, F->TabV[i]->immatriculation, F->TabV[i]->nb_kilometres, F->TabV[i]->type == ELECTRIQUE ? "Electrique" : "Essence");
    }
}

void desalloue_flotte(Flotte **F){
    for(int i = 0; i < (*F)->nb_voitures; i++)
        if((*F)->TabV[i]){
            free((*F)->TabV[i]);
            (*F)->TabV[i] = NULL;
        }

    free((*F)->TabV);
    (*F)->TabV = NULL;

    free(*F);
    *F = NULL;
}

void affiche_plus_ancienne(Flotte* F){
    int voiture_plus_ancienne = - 1, max_km = 0;

    for(int i = 0; i < F->nb_voitures; i++){
        if(F->TabV[i]->type == ESSENCE)
            if(F->TabV[i]->nb_kilometres > max_km){
                max_km = F->TabV[i]->nb_kilometres;
                voiture_plus_ancienne = i;
            }
    }

    if(voiture_plus_ancienne == -1)
        printf("Il n'y a pas de voiture à essence\n");
    else 
        printf("La voiture à essence ayant le plus de kilomètre au compteur est la voiture avec l'immatriculation %d avec %d kilomètres au compteur\n", F->TabV[voiture_plus_ancienne]->immatriculation, F->TabV[voiture_plus_ancienne]->nb_kilometres);
}

void tri_par_kilometrage(Flotte *F){
    Voiture * tmp;
    int i, j, min;

    for(i = 0; i < F->nb_voitures - 1; i++){
        min = i;
        for(j = i + 1; j < F->nb_voitures; j++)
            if(F->TabV[j]->nb_kilometres < F->TabV[min]->nb_kilometres)
                min = j;

        if(min != i){
            tmp = F->TabV[i];
            F->TabV[i] = F->TabV[min];
            F->TabV[min] = tmp;
        }
    }
    
}

Voiture** extrait_essence(Flotte* F){
    Voiture ** voitures_essence;
    int nb_essence = 0, j = 0;

    for(int i = 0; i < F->nb_voitures; i++)
        if(F->TabV[i]->type == ESSENCE)
            nb_essence++;

    voitures_essence = malloc(nb_essence * sizeof(Voiture *));
    if(!voitures_essence) {
        printf("Erreur allocation mémoire\n");
        return NULL;
    }

    for(int i = 0; i < F->nb_voitures; i++){
        if(F->TabV[i]->type == ESSENCE){
            voitures_essence[j] = F->TabV[i];
            j++;
        }
    }

    return voitures_essence;
}

void afficher_voiture_essence(Voiture ** V, int nb_essence){
    printf("Voiture numéro\t\tImmatriculation\t\tNb_kilomètre\t\tType\n");
    for(int i = 0; i < nb_essence; i++){
        printf("#%-12d\t\t%14d\t\t%12d\t\t%4s\n", i+1, V[i]->immatriculation, V[i]->nb_kilometres, V[i]->type == ELECTRIQUE ? "Electrique" : "Essence");
    }
}

void transforme_electrique(Voiture** T, int taille) {
    for(int i = 0; i < taille; i++)
        T[i]->type = ELECTRIQUE;
}

void affiche_deuxieme_ancienne(Flotte* F){
    int max_km = 0, voiture_plus_ancienne2 = -1, max_km2 = 0;

    for(int i = 0; i < F->nb_voitures; i++){
        if(F->TabV[i]->nb_kilometres > max_km){
            max_km = F->TabV[i]->nb_kilometres;
        }
    }

    for(int i = 0; i < F->nb_voitures; i++){
        if(F->TabV[i]->nb_kilometres > max_km2 && F->TabV[i]->nb_kilometres < max_km){
            max_km2 = F->TabV[i]->nb_kilometres;
            voiture_plus_ancienne2 = i;
        }
    }

    printf("La 2e voiture ayant le plus de kilométrage à son actif est la voiture avec l'immatriculation %d avec %dkm à son actif\n", F->TabV[voiture_plus_ancienne2]->immatriculation, F->TabV[voiture_plus_ancienne2]->nb_kilometres);
}

void desalloue_flotte_essence(Voiture **F, int nb_essence){
    if(!F) return;

    for(int i = 0; i < nb_essence; i++)
        if(!F[i]) {
            free(F[i]);
            F[i] = NULL;
        }

    free(F);
    F = NULL;
}