#include "polynome.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

struct polynome * creer_polynome (int taille) {
   struct polynome * res = malloc(sizeof(struct polynome));
   if (res == NULL) {
      perror("Échec de l'allocation mémoire pour la structure ");
      exit(2);
   }
   res->coefficients = malloc(taille * sizeof(int));
   if (taille > 0 && res->coefficients == NULL) {
      perror("Échec de l'allocation mémoire pour les coefficients ");
      exit(2);
   }
   res->degre = -1;
   res->taille = taille;
   return res;
}


void detruire_polynome (struct polynome **p){
  if (*p != NULL) {
	if ((*p)->coefficients != NULL) 
	  free((*p)->coefficients);	
  	free(*p);
	*p = NULL;
  }
}


/* Génération aléatoire d'un polynome d'au plus dehre_max
   et avec des coefficients  entre -9 et +9 */
struct polynome * initialiser_polynome_alea (int degre_max) {
   struct polynome * res = creer_polynome(degre_max + 1);

   res->degre = rand() % (degre_max +1);
   for(int i = 0; i <= res->degre; i++){
      res->coefficients[i] = rand() % 19 - 9;
   }

   return res;
}



void afficher_polynome (const struct polynome *p) {
   int j = 0;

   // for(int i = 0; i <= p->degre; i++){
   //    if(p->degre -i == 1)
   //       printf("%dx", p->coefficients[i]);
   //    else if(p->degre - i == 0)
   //       printf("%d", p->coefficients[i]);
   //    else
   //       printf("%dx^%d", p->coefficients[i], p->degre - i);
      
   //    if(i < p->degre/* && p->coefficients[i] > 0*/)
   //    {
   //       printf(" + ");
   //    } 
   //    // else if (i < p->degre && p->coefficients[i +1] < 0){
   //    //    printf(" ");
   //    // }
   // }

   for(int i = p->degre; i >= 0; i--){
      if(p->degre - j == 1)
         printf("%dx", p->coefficients[i]);
      else if (p->degre - j == 0)
         printf("%d", p->coefficients[i]);
      else
         printf("%dx^%d", p->coefficients[i], p->degre - j);

      if(j < p->degre){
         printf(" + ");
      }
      j++;
   }
   
   putchar('\n');
}



void scalaire_polynome (struct polynome* p, int a) {

}

struct polynome * additionner_polynome (const struct polynome *p, const struct polynome *q) {
   int degre_max = (p->degre >= q->degre) ? p->degre : q->degre;
	struct polynome * res = creer_polynome(degre_max + 1);

   res->degre = degre_max;

   for(int i = 0; i <= degre_max; i++){
      int coeff_p = (i <= p->degre) ? p->coefficients[i] : 0;
      int coeff_q = (i <= q->degre) ? q->coefficients[i] : 0;
      res->coefficients[i] = coeff_p + coeff_q;
   }
	
	return res;
}

struct polynome * multiplier_polynome (const struct polynome *p, const struct polynome *q) {
   int degre_max = (p->degre >= q->degre) ? p->degre : q->degre;
	struct polynome *res = creer_polynome(degre_max + 1);

   res->degre = degre_max;

   for(int i = 0; i <= degre_max; i++){
      int coeff_p = (i <= p->degre) ? p->coefficients[i] : 1;
      int coeff_q = (i <= q->degre) ? q->coefficients[i] : 1;
      res->coefficients[i] = coeff_p * coeff_q;
   }

	return res;
}

struct polynome * deriver_polynome (const struct polynome *p) {
	struct polynome * res = creer_polynome(p->degre);

   res->degre = p->degre - 1;

   for(int i = 0; i <= res->degre; i++){
      if(p->degre > 0)
         res->coefficients[i] = p->coefficients[i] * (p->degre - i);
      else
         res->coefficients[i] = 0;
   }
	
	return res;
}





/********************************************/
/**  Évaluation d'un polynôme en un point  **/
/********************************************/


/** Évalue le polynôme p en a (méthode standard) avec la fonction pow*/
double evaluer_polynome_pow(const struct polynome * p, double a) {
	double res = 0.0;

   if(!p->coefficients)
      return 0.0;

   for (int i = 0; i <= p->degre; i++)
      res += p->coefficients[i] * pow(a, p->degre -i);

	return res;
}

/** Évalue le polynôme p en a (méthode standard) */
double evaluer_polynome_classique(const struct polynome * p, double a) {
   double res = 0.0, puissance = 1.0;

  if(p->coefficients == NULL)
     return 0.0;

  for (int i = 0; i < p->degre; i++)
     puissance *= a;

  for (int i = 0; i <= p->degre; i++){
     res += p->coefficients[i] * puissance;
     puissance /= a;
  }

   return res;
}

/* Évalue le polynôme p en a (méthode de Horner) */
double evaluer_polynome_Horner(const struct polynome * p, double a) {
	double res;

   if(!p->coefficients)
      return 0.0;

   res = p->coefficients[0];

   for(int i = 1; i <= p->degre; i++)
      res = res * a + p->coefficients[i];

	return res;
}