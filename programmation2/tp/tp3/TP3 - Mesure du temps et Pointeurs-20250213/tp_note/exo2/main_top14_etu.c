#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "Equipe.h"
#include "Match.h"

#define INDICE_D 5


int main(){
  Equipe Teq[NB_EQUIPES];      /* Tableau des équipes */
  Match Tmatch[NB_MATCHS];     /* Tableau des matchs */

  FILE *fic = fopen("Top14.txt", "r");

  if(fic == NULL){
    printf("Le fichier n'existe pas.\n");

    return EXIT_SUCCESS;
  }

  /* Lecture du début du fichier pour remplir le tableau Teq des NB_EQUIPES équipes */
  /* et mise à zéros des compteurs des statistiques */
  for(int i = 0; i < NB_EQUIPES; i++){
    if(fscanf(fic, "%s", Teq[i].nom) != 1){
      printf("Erreur lors de la lecture des équipes.\n");
      fclose(fic);
      return EXIT_FAILURE;
    }

    Teq[i].nb_bonus = 0;
    Teq[i].nb_defaites = 0;
    Teq[i].nb_nuls = 0;
    Teq[i].nb_points = 0;
    Teq[i].nb_victoires = 0;
  }
  
  /* Affichage pour test de la liste des équipes */
  affiche_equipe(Teq);
  
  /* Lecture de la 2eme partie du fichier pour remplir le tableau Tmatch des NB_MATCHS matchs */
  /* Pour cela, il faut rechercher un pointeur sur équipe dans Teq à partir de son nom */
  for(int i = 0; i < NB_MATCHS; i++){
    char nom_hote[MAX_STRING], nom_invite[MAX_STRING];
    if(fscanf(fic, "%s %d - %d %s", nom_hote, &Tmatch[i].score_hote, &Tmatch[i].score_invite, nom_invite) != 4){
      puts("Erreur lors de la lecture des matchs");
      fclose(fic);
      return EXIT_FAILURE;
    }

    Tmatch[i].eq_hote = rech_ptr_equipe(Teq, NB_EQUIPES, nom_hote);
    Tmatch[i].eq_invite = rech_ptr_equipe(Teq, NB_EQUIPES, nom_invite);

    for(int j = 0; j < NB_EQUIPES; j++){
      if(strcmp(nom_hote, Teq[j].nom) == 0)
        Tmatch[i].eq_hote = &Teq[j];

      if(strcmp(nom_invite, Teq[j].nom) == 0)
        Tmatch[i].eq_invite = &Teq[j];
    }

    if (Tmatch[i].eq_hote == NULL || Tmatch[i].eq_invite == NULL){
      printf("Erreur : équipe non trouvée dans la liste.\n");
      fclose(fic);
      return EXIT_FAILURE;
    }
    
    if(Tmatch[i].eq_hote == NULL || Tmatch[i].eq_invite == NULL){
      printf("Erreur : équipe non trouvé dans la liste.\n");
      fclose(fic);
      return EXIT_FAILURE;
    }
  }

  

  /* Affichage pour test de la liste des matchs */
  printf("\nListe des matchs :\n");
  for(int i = 0; i < NB_MATCHS; i++)
    affiche_match(Tmatch[i]);


  fclose(fic);

  

  /* Affichage des résultats des équipes */
  analyse_matchs(Tmatch, NB_MATCHS);
  calcul_points(Teq, NB_EQUIPES);
  putchar('\n');
  affiche_equipe(Teq);

  /* Affichage de l'équipe première au classement */
  putchar('\n');
  premier_classement(Teq, NB_EQUIPES);
  printf("L'équipe #1 au classement est %s avec un total de %d points\n", Teq[0].nom, Teq[0].nb_points);
  
  printf("L'équipe ayant le plus de points à partir de l'indice %d est %s\n", INDICE_D, Teq[max_indice(Teq, NB_EQUIPES, INDICE_D)].nom);


  /* Affichage du classement trié des équipes */
  trier_equipes(Teq, NB_EQUIPES);
  putchar('\n');
  affiche_equipe(Teq);


  return EXIT_SUCCESS;
}