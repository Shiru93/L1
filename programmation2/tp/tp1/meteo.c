#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256     /* taille maximale d'une chaîne de caractère */
#define MAX_VILLES 50      /* nombre maximale de villes */

typedef struct {
    char nom[MAX_STRING];   /* nom de la ville */
    float altitude;         /* altitude de la ville */
    float temp[12];         /* tableau des températures */
} Ville;

typedef struct {
    char nom[MAX_STRING];
    float temp_moy;
} Order;

void moyenne_temp(Ville TabV[]);
void record_temp(Ville TabV[]);
void ville_froide(Ville TabV[]);
void ordre_ville(Ville TabV[]);

int main() {
    int nbV = 10;
    Ville TabV[MAX_VILLES] = {
        {"Paris", 35, {7.5, 8.2, 9.1, 10.5, 13.2, 15.8, 18.0, 17.2, 14.3, 10.9, 8.1, 7.2}},
        {"Saint-Etienne", 633, {5.5, 6.1, 7.3, 9.0, 12.0, 15.2, 18.3, 17.4, 14.1, 10.4, 7.2, 5.7}},
        {"Clermont-Ferrand", 370, {6.0, 6.7, 7.9, 9.2, 12.5, 14.9, 17.1, 16.3, 13.4, 9.8, 7.0, 6.3}},
        {"Lyon", 237, {8.3, 9.1, 10.2, 12.4, 15.0, 18.0, 20.0, 19.2, 16.8, 13.0, 9.5, 8.0}},
        {"Marseille", 20, {12.5, 13.1, 14.2, 16.0, 18.3, 21.0, 24.0, 23.1, 19.7, 15.2, 13.0, 12.0}},
        {"Bordeaux", 9, {10.0, 11.2, 12.3, 14.2, 17.0, 19.5, 22.0, 21.2, 18.0, 14.3, 11.1, 9.8}},
        {"Lille", 27, {6.8, 7.5, 8.6, 10.0, 12.5, 15.0, 17.0, 16.3, 13.5, 10.1, 7.5, 6.0}},
        {"Grenoble", 212, {6.5, 7.0, 8.2, 10.5, 13.4, 16.0, 19.0, 18.2, 15.0, 11.3, 8.2, 6.4}},
        {"Dijon", 265, {7.3, 8.1, 9.3, 11.0, 14.0, 16.5, 19.2, 18.5, 15.6, 12.3, 9.2, 7.0}},
        {"Nantes", 18, {9.5, 10.2, 11.1, 13.2, 15.6, 18.0, 20.5, 19.7, 16.5, 13.0, 10.2, 9.0}}
    };


    moyenne_temp(TabV);
    record_temp(TabV);
    ville_froide(TabV);
    ordre_ville(TabV);

    
    return EXIT_SUCCESS;
}

void moyenne_temp(Ville TabV[]){
    float moyenne = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 12; j++){
            moyenne += TabV[i].temp[j];
        }
        printf("La moyenne de température de la ville %s est de : %.2f\n", TabV[i].nom, moyenne / 12);
        moyenne = 0;
    }
}

void record_temp(Ville TabV[]){
    int mois;
    int name;

    printf("Veuillez taper un mois (en chiffre) : ");
    scanf("%d", &mois);
    mois--;
    float haute_temp = TabV[0].temp[mois];

    for(int i = 1; i < 10; i++){
        if(TabV[i].temp[mois] > haute_temp){
            haute_temp = TabV[i].temp[mois];
            name = i;
        } 
    }

    printf("La ville avec la température la plus chaude ce mois-là est : %s pour une température de : %.2f\n", TabV[name].nom, TabV[name].temp[mois]);
}

void ville_froide(Ville TabV[]){
    int alt;
    float temperature = TabV[0].temp[0];
    int name;

    printf("Veuillez taper une altitude comprise en 1 et 600 : ");
    scanf("%d", &alt);

    for(int i = 0; i < 10; i++){
        if(TabV[i].altitude >= alt){
            for(int j = 0; j < 12; j++){
                if(TabV[i].temp[j] < temperature){
                    temperature = TabV[i].temp[j];
                    name = i;
                }
            }
        }
    }

    printf("La ville se situant à une altitude supérieure ou égale à %d est la ville %s avec une température la plus basse de %.2f\n", alt, TabV[name].nom, temperature);
}

void ordre_ville(Ville TabV[]){
    Order var[MAX_STRING];
    float temporaire;
    char temp_blaze[MAX_STRING];
    
    for(int i = 0; i < 10; i++){
        strcpy(var[i].nom, TabV[i].nom);
        var[i].temp_moy = TabV[i].temp[0];
            for(int j = 1; j < 12; j++){
                var[i].temp_moy += TabV[i].temp[j];
            }
    }
    
    for(int i = 0; i < 10; i++){
        var[i].temp_moy /= 12;
        printf("%s : %.2f\n", var[i].nom, var[i].temp_moy);
    }

    putchar('\n');

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(var[i].temp_moy > var[j].temp_moy){
                temporaire = var[j].temp_moy;
                var[j].temp_moy = var[i].temp_moy;
                var[i].temp_moy = temporaire;

                strcpy(temp_blaze, var[j].nom);
                strcpy(var[j].nom, var[i].nom);
                strcpy(var[i].nom, temp_blaze);
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%s : %.2f\n", var[i].nom, var[i].temp_moy);
    }
}