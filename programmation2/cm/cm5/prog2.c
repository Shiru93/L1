#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f = fopen("notes.txt", "r");
    if(!f){
        printf("Erreur d'ouverture\n");
        return 1;
    }

    int nb_matieres;
    if(fscanf(f, "%d", &nb_matieres) != 1){
        printf("Erreur de lecture du nombre de matières\n");
        fclose(f);
        return 1;
    }

    printf("Nombre de matières : %d\n", nb_matieres);
    
    char nom[30], commentaire[100];
    int note;

    for(int i = 0; i < nb_matieres; i++){
        if(fscanf(f, "%s %d %s\n", nom, &note, commentaire) != 3){
            printf("Erreur de lecture à la ligne %d\n", i + 1);
            continue;
        }

        printf("Matière : %s, Note : %d, Commentaire : %s\n", nom, note, commentaire);
    }

    fclose(f);

    return 0;
}