#ifndef _POSTE_H
#define _POSTE_H_

#include "liste.h"

#define MAX_GUICHETS 10

typedef struct {
    Liste guichets[MAX_GUICHETS];
    int nb;
} BureauPoste;

BureauPoste * creerBureauPoste(int n);
void afficherPoste(const BureauPoste * bureau);
int ajouterAuGuichet(BureauPoste *bureau, int num_guichet, int num_usager);

#endif