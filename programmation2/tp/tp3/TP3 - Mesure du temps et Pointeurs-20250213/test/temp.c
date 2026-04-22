#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp;
    char c;

    fp = fopen("nouveau.txt", "w");
    fprintf(fp, "%s %s %s %d", "Nous", "sommes", "en", 2025);
    fclose(fp);

    fp = fopen("nouveau.txt", "r");
    fscanf(fp, "%c", &c);
    while(!feof(fp)){
        printf("%c", c);
        fscanf(fp, "%c", &c);
    }
    printf("\n");
    fclose(fp);
    return EXIT_SUCCESS;
}