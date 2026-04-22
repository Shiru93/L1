#include <stdio.h>

int main(){
    char ligne[] = "Jean 25 180.5";
    char nom[50];
    int age;
    float taille;

    sscanf(ligne, "%s %d %f", nom, &age, &taille);
    printf("Nom : %s, Age : %d, Taille : %.1f cm\n", nom, age, taille);

    return 0;
}