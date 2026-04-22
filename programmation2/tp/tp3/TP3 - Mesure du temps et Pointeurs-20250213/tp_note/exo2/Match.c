#include "Match.h"

void affiche_match(Match m){
    printf("%s %d - %d %s\n", m.eq_hote->nom, m.score_hote, m.score_invite, m.eq_invite->nom);
}

void analyse_matchs(Match Tmatch[], int n){
    for (int i = 0; i < n; i++){
        Equipe * hote =  Tmatch[i].eq_hote;
        Equipe * invite = Tmatch[i].eq_invite;

        if(Tmatch[i].score_hote > Tmatch[i].score_invite){
            hote->nb_victoires++;
            invite->nb_defaites++;

            if(Tmatch[i].score_hote - Tmatch[i].score_invite <= 5){
                invite->nb_bonus++;
            }
        } else if(Tmatch[i].score_hote < Tmatch[i].score_invite){
            invite->nb_victoires++;
            hote->nb_defaites++;

            if(Tmatch[i].score_invite - Tmatch[i].score_hote <= 5){
                hote->nb_bonus++;
            }
        } else {
            hote->nb_nuls++;
            invite->nb_nuls++;
        }
    }
}