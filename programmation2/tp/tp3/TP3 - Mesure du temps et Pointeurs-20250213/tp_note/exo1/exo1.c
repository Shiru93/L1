#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXL 1000  // Taille maximale d'une matrice en nombre de lignes
#define MAXC 1000 // Taille maximale d'une matrice en nombre de colonnes
#define K 256

void remplir_matrice(int M[MAXL][MAXC], int V, int n, int m);
void afficher_matrice(int M[MAXL][MAXC], int n, int m);
void element_frequent(int M[MAXL][MAXC], int n, int m);
int element_frequent_rapide(int M[MAXL][MAXC], int n, int m);

int main(){
    int M[MAXL][MAXC], n, m, V;

    do
    {
        printf("Veuillez taper une valeur pour n et m : ");
        scanf("%d %d", &n, &m);
        printf("Même chose pour V (valeur maximale des nombres de la matrice) : ");
        scanf("%d", &V);
    } while (n <= 0 || m <= 0 || V <= 0);
    
    clock_t temps_initial; // Temps initial en micro-secondes
    clock_t temps_final; // Temps final en micro-secondes
    double temps_cpu; // Temps total en secondes

    temps_initial = clock();
    remplir_matrice(M, V, n, m);
    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    printf("remplir matrice met %f secondes en temps CPU\n", temps_cpu);

    temps_initial = clock();
    afficher_matrice(M, n, m);
    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    printf("afficher matrice met %f secondes en temps CPU\n", temps_cpu);

    if(n != m){
        puts("Ce n'est pas une matrice carrée");
        return 0;
    } else {
        temps_initial = clock();
        element_frequent(M, n, m);
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("L'algorithme lent met %f secondes en temps CPU\n", temps_cpu);

        temps_initial = clock();
        printf("L'élément le plus fréquent est : %d\n", element_frequent_rapide(M, n, m));
        temps_final = clock();
        temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;
        printf("L'algorithme rapide met %f secondes en temps CPU\n", temps_cpu);
    }

    return 0;
}

void remplir_matrice(int M[MAXL][MAXC], int V, int n, int m){
    srand((unsigned)time(NULL));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            M[i][j] = rand() % V+1;
}

void afficher_matrice(int M[MAXL][MAXC], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%7d", M[i][j]);
        putchar('\n');
    }

    putchar('\n');
}

void element_frequent(int M[MAXL][MAXC], int n, int m){
    int element, nb = 0, nb_max = 0, element_frequent = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            element = M[i][j];
            nb = 0;

            for(int k = 0; k < n; k++)
                for(int l = 0; l < m; l++) 
                    if(M[k][l] == element)
                        nb++;

            if(nb > nb_max){
                nb_max = nb;
                element_frequent = element;
            }
        }
    }

    printf("La valeur %d est répétée %d fois\n", element_frequent, nb_max);
}

int element_frequent_rapide(int M[MAXL][MAXC], int n, int m){
    int i, j, tab[MAXL] = {0}, max_freq = tab[0], max_elem = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(M[i][j] >= 0 && M[i][j] < MAXL)
                tab[M[i][j]]++;

    for(i = 1; i < MAXL; i++)
        if(tab[i] > max_freq){
            max_freq = tab[i];
            max_elem = i;
        }

    return max_elem;
}