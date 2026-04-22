#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "Poste.h"

#define NB_GUICHETS 3

int main(){
    Liste L;
    BureauPoste bureau;

    L.debut = NULL;
    L.taille = 0;

    puts("Liste initiale :");
    affichage_liste(L);

    printf("\nAjout de 10, 20 et 30 en tête\n");
    ajout_en_tete(&L, 10);
    ajout_en_tete(&L, 20);
    ajout_en_tete(&L, 30);

    puts("Liste après ajout :");
    affichage_liste(L);

    printf("\nSuppression du dernier élèment de la liste\n");
    suppression_en_fin(&L);
    affichage_liste(L);

    printf("\nSuppression de toute la liste\n");
    while(L.debut) suppression_en_fin(&L);
    affichage_liste(L);

    creerBureauPoste(NB_GUICHETS);

    

    return 0;
}