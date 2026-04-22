#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "polynome.h"

#define PUISSANCE 2.0

int main(int argc, char *argv[]) {
    struct polynome * res_dp, * res_dq;
    int dp, dq;
    clock_t temps_initial, temps_final;
    double temps_cpu;

    srand(time(NULL));
    
    if (argc != 3){
        printf("Erreur ! Nombre d'arguments invalide.\n");
        printf("Usage : %s int \n", argv[0]);
        return EXIT_FAILURE;
    }

    dp = atoi(argv[1]);
    dq = atoi(argv[2]);
    
    printf("dp : %d, dq : %d\n",dp,dq);

    if (dp < -1 || dq < -1){
        perror("Erreur ! Les deux arguments doivent être supérieur ou égale à -1.\n");
        return EXIT_FAILURE;
    }


    res_dp = initialiser_polynome_alea(dp);
    

    if(res_dp){
        printf("Polynome dp : ");
        afficher_polynome(res_dp);

        putchar('\n');

        temps_initial = clock();
        printf("Le polynôme élevé à la puissance %f (avec fonction pow): %f\n", PUISSANCE, evaluer_polynome_pow(res_dp, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode pow met %f secondes en temps_cpu\n", temps_cpu);

        putchar('\n');

        temps_initial = clock();
        printf("Le polynôme élevé à la puissance %f (sans fonction pow): %f\n", PUISSANCE, evaluer_polynome_classique(res_dp, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode classique met %f secondes en temps_cpu\n", temps_cpu);

        putchar('\n');

        temps_final = clock();
        printf("Le polynôme élevé à la puissance %f (Méthode de Horner): %f\n", PUISSANCE, evaluer_polynome_Horner(res_dp, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode Horner met %f secondes en temps_cpu\n", temps_cpu);
    } else
        printf("Erreur: Impossible de créer le polynôme.\n");


    putchar('\n');
    
    res_dq = initialiser_polynome_alea(dq);


    if(res_dq){
        printf("Polynome dq : ");
        afficher_polynome(res_dq);

        putchar('\n');

        temps_initial = clock();
        printf("Le polynôme élevé à la puissance %f (avec fonction pow): %f\n", PUISSANCE, evaluer_polynome_pow(res_dq, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode pow met %f secondes en temps_cpu\n", temps_cpu);

        putchar('\n');

        temps_initial = clock();
        printf("Le polynôme élevé à la puissance %f (sans fonction pow): %f\n", PUISSANCE, evaluer_polynome_classique(res_dq, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode classique met %f secondes en temps_cpu\n", temps_cpu);

        putchar('\n');

        temps_final = clock();
        printf("Le polynôme élevé à la puissance %f (Méthode de Horner): %f\n", PUISSANCE, evaluer_polynome_Horner(res_dq, PUISSANCE));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("La méthode Horner met %f secondes en temps_cpu\n", temps_cpu);
    } else
        printf("Erreur: Impossible de créer le polynôme.\n");

    putchar('\n');

    printf("Le résultat de l'addition entre les 2 polynômes est : ");
    afficher_polynome(additionner_polynome(res_dp, res_dq));

    printf("Le résultat de la multiplication entre les 2 polynômes est : ");
    afficher_polynome(multiplier_polynome(res_dp, res_dq));

    printf("La dérivée du polynôme dp est : ");
    afficher_polynome(deriver_polynome(res_dp));

    detruire_polynome(&res_dp);
    detruire_polynome(&res_dq);


    return 0;
}