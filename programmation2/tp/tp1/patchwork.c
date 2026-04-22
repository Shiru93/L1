#include <stdio.h>

char motif_carre_NO_SE(int i, int j, int n);

int main(){
    int n, i = n / 2, j = n / 2;

    do
    {
        printf("Veuillez taper une valeur entière positif paire : ");
        scanf("%d", &n);
    } while (n <= 0 || n % 2 != 0);

    while(j < n){
        putchar(motif_carre_NO_SE(i, j, n));
        j++;
    }

    putchar('\n');

    return 0;
}

char motif_carre_NO_SE(int i, int j, int n){
    if(j == 0 || i == 0 || n -1 == j || n - 1 == i)
        return '*';
    return ' ';
}