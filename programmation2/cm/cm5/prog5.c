#include <stdio.h>
#include <stdlib.h>

float * Chargement(char * nomFichier, int * adrNbElem);
void Sauvegarde(float * tableau, int nb, char * nomFichier);

int main(void){
    int nb;
    float * tableau = LectureTableau(&nb);
    Sauvegarde(tableau, nb, "monfichier.dat");
    free(tableau);
    return 0;
}

// Lecture d'un fichier binaire
// Chargement d'un tableau depuis un fichier
float * Chargement(char * nomFichier, int * adrNbElem){
    int n;
    float * tableau;
    FILE * fp = fopen(nomFichier, "rb");
    if(!fp){
        perror("Erreur d'ouverture du fichier");
        exit(1);
    }

    fread(&n, sizeof(int), 1, fp);
    *adrNbElem = n;
    tableau = (float *)malloc(n * sizeof(float));
    fread(tableau, sizeof(float), n, fp);
    fclose(fp);

    return tableau;
}

// Ecriture dans un fichier binaire
// Sauvegarde d'un tableau dans un fichier
void Sauvegarde(float * tableau, int nb, char * nomFichier){
    FILE * fp = fopen(nomFichier, "wb");
    if(!fp){
        perror("Erreur d'ouverture du fichier");
        exit(1);
    }

    fwrite(&nb, sizeof(int), 1, fp);
    fwrite(tableau, sizeof(float), nb, fp);
    fclose(fp);
}