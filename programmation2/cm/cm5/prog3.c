#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f = fopen("notes.txt", "r");
    if(!f){
        printf("Erreur d'ouverture\n");
        return 1;
    }
    
    char ligne[100];
    char nom[30], commentaire[100];
    int note;

    while(fgets(ligne, sizeof(ligne), f)) {
        if(sscanf(ligne, "%49[^0-9] %d %49[^\n]", nom, &note, commentaire) == 3){
            printf("Matière : %s, Note : %d, Commentaire : %s\n", nom, note, commentaire);
        } else {
            printf("Format incorrect : %s\n", ligne);
        }
    }

    fclose(f);

    return 0;
}