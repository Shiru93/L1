#include <stdio.h>
#include <stdlib.h>
#include "Poste.h"

BureauPoste * creerBureauPoste(int n){
    BureauPoste * nouveau = malloc(sizeof(BureauPoste));

    if (n <= 0 || n > MAX_GUICHETS) {
        printf("Erreur: Nombre de guichets invalide (doit être entre 1 et %d)\n", MAX_GUICHETS);
        return NULL;
    }

    if(!nouveau){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    nouveau->nb = n;
    for(int i = 0; i < n; i++){
        nouveau->guichets[i].debut = NULL;
        nouveau->guichets[i].taille = 0;
    }

    return nouveau;
}

void afficherPoste(const BureauPoste * bureau){
    maillon * courant = NULL;
    int position;
    if(!bureau){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    printf("\nAffichage Bureau de Poste\n");
    printf("Nombre total de guichets : %d\n\n", bureau->nb);

    for(int i = 0; i < bureau->nb; i++){
        printf("Guichet %d - %d usagers : \n", i, bureau->guichets[i].taille);

        if(bureau->guichets[i].taille == 0) printf("\t(file vide)\n");
        else {
            courant = bureau->guichets[i].debut;
            position = 1;
            while(courant){
                printf("\t%d. Usager numéro %d\n", position++, courant->numero);
                courant = courant->suiv;
            }
        }
    }
}

int ajouterAuGuichet(BureauPoste *bureau, int num_guichet, int num_usager){
    if(!bureau){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    if(num_guichet < 0 || num_guichet >= bureau->nb){
        printf("Le guicher %d n'existe pas\n", num_guichet);
        exit(1);
    }

    ajout_en_tete(&(bureau->guichets[num_guichet]), num_guichet);
}