#include <stdio.h>
#include <stdlib.h>

struct matiere_s {
    char nom[30];
    char note[3];
    char commentaire[30];
};

typedef struct matiere_s matiere_t;

int main(int argc, char ** argv){
    FILE * f;
    matiere_t * m;
    int nb_ligne, i;

    if((f = fopen(argv[1], "r")) != NULL){
        fscanf(f, "%d\n", &nb_ligne);
        printf("Le nombre de ligne est %d\n", nb_ligne);

        m = (matiere_t *)malloc(sizeof(matiere_t) * nb_ligne);
        fread(m, sizeof(matiere_t), nb_ligne, f);

        for(i = 0; i < nb_ligne; i++){
            m[i].nom[29] = '\0';
            printf("--------------------\n");
            printf("Nom du cours : %s\n", m[i].nom);

            m[i].note[2] = '\0';
            printf("Note : %s\n", m[i].note);

            m[i].commentaire[29] = '\0';
            printf("Commentaire : %s\n", m[i].commentaire);
        }

        free(m);
        fclose(f);
    } else {
        printf("Le fichier %s n'existe pas\n", argv[1]);
        return EXIT_SUCCESS;
    }
}