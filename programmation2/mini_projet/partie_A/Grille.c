#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "Grille.h"

#define BLACK "\33[40m  "
#define GREEN "\33[42m  "
#define RED "\33[41m  "
#define BLUE "\33[44m  "
#define BLANC "\33[47m  "

Grille * Grille_initialiser(int n, int m){
    Grille * g = malloc(sizeof(Grille));
    if(!g){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    srand(time(NULL));

    g->n = n; // n = nombre de lignes
    g->m = m; // m = nombre de colonnes
    
    g->tab = malloc(n * sizeof(enum elements *)); 
    if(!g->tab){
        puts("Erreur allocation mémoire");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        g->tab[i] = malloc(m * sizeof(enum elements *)); 
        if(!g->tab[i]){
            puts("Erreur allocation mémoire");
            exit(1);
        }

        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                g->tab[i][j] = MUR;

            else 
                if(rand() % 50 == 0){
                    g->tab[i][j] = PIEGE;
                }

                else if (rand() % 50 == 1)
                    g->tab[i][j] = ARME;

                else
                    g->tab[i][j] = RIEN;
            
        }
    }


    return g;
}

void Grille_desallouer(Grille *g){
    if(!g){
        printf("Erreur allocation mémoire\n");
        exit(1);
    }

    for(int i = 0; i < g->n; i++)
        free(g->tab[i]);

    free(g->tab);
    free(g);
}

void Grille_vider(Grille *g){
    if(!g || !g->tab){
        printf("Erreur allocation mémoire\n");
        exit(1);
    }

    for(int i = 0; i < g->n; i++)
        if(g->tab[i])
            for(int j = 0; j < g->m; j++)
                g->tab[i][j] = RIEN;
}

void Grille_redessiner(Grille *g){
    if(!g || !g->tab){
        printf("Erreur allocation mémoire\n");
        exit(1);
    }

    printf("\33[2J"); // Efface tout l'ecran
    printf("\33[H");  // Deplace le curseur en position (0,0) 
    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->m; j++){
            switch(g->tab[i][j]){
                case RIEN:
                    printf("%s", BLACK); // Affiche un carré noir
                    break;
        
                case MUR:
                    printf("%s", GREEN);  // Affiche un carré vert
                    break;
        
                case PION:
                    printf("%s", RED);  // Affiche un carré rouge
                    break;
        
                case PIEGE:
                    printf("%s", BLUE);  // Affiche un carré bleu
                    break;  

                case ARME:
                    printf("%s", BLANC); // Affiche un carré blanc
                    break;
        
                default:
                    printf("%s", BLACK);  // Affiche un carré noir
                    break;
            }
        }
        printf("\33[1E");
        /* printf("\n\r"); */
        fflush(stdout);
        printf("\033[40m"); // Declare le fond noir pour la suite
    }
}

void Grille_charger_fichier(const Grille * g, const char * fichier){
    FILE * file = fopen(fichier, "w");
    if(!file) {
        perror("Erreur d'ouverture du fichier en écriture");
        exit(2);
    }

    fprintf(file, "%d %d\n", g->n, g->m);

    for(int i = 0; i < g->n; i++){
        for(int j = 0; j < g->m; j++) {
            switch(g->tab[i][j]){
                case MUR:
                    fputc('M', file);
                    break;

                case PION:
                    fputc('P', file);
                    break;
                
                case PIEGE:
                    fputc('Q', file);
                    break;

                case ARME:
                    fputc('B', file);
                    break;

                case RIEN:
                    fputc(' ', file);
                    break;

                default:
                    fputc('?', file);
                    break;
            }
        }

        fputc('\n', file);
    }

    fclose(file);
}