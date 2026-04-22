#include <stdio.h>

int main(){
    int a[5];
    int i = 10;
    a[i] = 12; // Erreur !
    printf("Valeur de a[%d] = %d\n", i, a[i]);
    return 0;
}