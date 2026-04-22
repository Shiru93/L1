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
    int M[MAXL][MAXC], n, m;

    do
    {
        printf("Veuillez taper une valeur pour n et m : ");
        scanf("%d %d", &n, &m);
    } while (n <= 0 || m <= 0);
    
    clock_t temps_initial; // Temps initial en micro-secondes
    clock_t temps_final; // Temps final en micro-secondes
    double temps_cpu; // Temps total en secondes

    temps_initial = clock();
    remplir_matrice(M, 10, n, m);
    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    printf("L'algorithme lent met %f secondes en temps CPU\n", temps_cpu);

    temps_initial = clock();
    afficher_matrice(M, n, m);
    temps_final = clock();
    temps_cpu = ((double)(temps_final - temps_initial)) / CLOCKS_PER_SEC;

    printf("L'algorithme rapide met %f secondes en temps CPU\n", temps_cpu);

    if(n != m){
        puts("Ce n'est pas une matrice carrée, force");
        return 0;
    } else {
        element_frequent(M, n, m);
        printf("L'élément le plus fréquent est : %d\n", element_frequent_rapide(M, n, m));
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

void element_frequent(int M[MAXL][MAXC], int n, int m) {
    int element, nb_max = 0;
    int element_frequent = 0;
    int freq[MAXL] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            element = M[i][j];
            freq[element]++;
            if (freq[element] > nb_max) {
                nb_max = freq[element];
                element_frequent = element;
            }
        }
    }

    printf("L'élément le plus fréquent est %d et est répété %d fois\n", element_frequent, nb_max);

    for (int i = 0; i < MAXL; i++) {
        if (freq[i] == nb_max && i != element_frequent) {
            printf("L'élément %d est également répété %d fois\n", i, nb_max);
        }
    }
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


    // int tcpt[K];
    // int i, j;

    // for(i = 0; i < n; i++){
    //     for(j = 0; j < n; j++){
    //         tcpt[M[i][j]]++;
    //     }
    // }
    
    // printf("L'élèment le plus fréquent est : %d\n", tcpt[0]);
}