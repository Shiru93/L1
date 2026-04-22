#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flotte_voiture.h"

#define NB_VOITURES 10

#define ESSENCE 0

int main(){
    Flotte * voitures = creer_flotte(NB_VOITURES);
    Voiture ** voitures_essence;
    int nb_essence = 0;
    
    srand(time(NULL));
    
    initialisee_random(voitures);
    affiche(voitures);

    for(int i = 0; i < voitures->nb_voitures; i++)
        if(voitures->TabV[i]->type == ESSENCE)
            nb_essence++;

    putchar('\n');

    affiche_plus_ancienne(voitures);

    putchar('\n');

    tri_par_kilometrage(voitures);
    printf("Affichage après tri :\n");
    affiche(voitures);

    putchar('\n');
    voitures_essence = extrait_essence(voitures);
    printf("Voici la liste de toutes les voitures à essence :\n");
    afficher_voiture_essence(voitures_essence, nb_essence);

    putchar('\n');
    transforme_electrique(voitures_essence, nb_essence);
    printf("Voici la liste des voitures initialement essence devenues électrique :\n");
    afficher_voiture_essence(voitures_essence, nb_essence);

    putchar('\n');

    affiche_deuxieme_ancienne(voitures);

    desalloue_flotte(&voitures);
    desalloue_flotte_essence(voitures_essence, nb_essence);

    return EXIT_SUCCESS;
}