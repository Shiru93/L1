#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "Fonctions_jeu.h"

#define TAILLE_PAROLES 100

void heurter_mur(Pion * p, Grille * g){
    if(g->tab[p->x][p->y] == MUR){
        p->x = p->x_old;
        p->y = p->y_old;
    }
}

// Quand le pion atterit sur une case PIEGE, enclenche un combat contre un monstre
void heurter_piege(Grille * g, Pion * p, Monstres ** tab, int * tmp){
    int x = rand() % 6;
    if(g->tab[p->x][p->y] == PIEGE){
        clear();
        while (p->pv > 0 && tab[x]->pv > 0){
            clear();
            attron(COLOR_PAIR(1));
            printw("Vous êtes sur le point d'affronter un monstres !\n");
            informations_monstres(tab, x);
            printw("\n");
            Pion_informations(p);
            printw("\n");
            combat(p, tab, x);
            refresh();

            printw("Appuyez sur une touche pour continuer...");
            
            refresh();
            getch();

            if(!victoire(tab, x, p)) attaque_monstre(p, tab, x);
            game_over(p, tmp);
            if(*tmp == 1) return;
        }
        attroff(COLOR_PAIR(1));
        fflush(stdout);
        // refresh();
        // getch();
    }
}

// Quand le pion atterit sur une case ARME, permet de récupérer une arme qui augmentera les stats du joueur
void heurter_arme(Grille * g, Pion * p, Armes ** tab){
    int x = rand() % 9;
    if(g->tab[p->x][p->y] == ARME){
        clear();
        attron(COLOR_PAIR(1));
        printw("Vous avez récupérer l'arme : %s (PV : %.3f / ATK : %.3f / DEF : %.3f)\n", tab[x]->nom, tab[x]->pv, tab[x]->atk, tab[x]->def);
        printw("Appuyez sur une touche pour continuer...\n");
        getch();
        p->pv += tab[x]->pv;

        if(p->atk + tab[x]->atk <= 400) p->atk += tab[x]->atk;
        else {
            if(p->compteur_arme == 0) {
                clear();
                printw("Vous : AAAAAARGH !!!\n");
                refresh();
                getch();

                printw("Vous : Qu'est-ce que c'était que ça ?\n");
                refresh();
                getch();
                
                printw("Vous : On dirait que mes armes ont étées maudits... Je ne peux plus les utiliser...\n");
                refresh();
                getch();

                p->compteur_arme++;
            }

            clear();
            printw("Hélas, vos stats d'ATK sont trop élevées\nDe ce fait, vous ne recevez aucun boost d'ATK\n");
            refresh();
            getch();
        }

        if(p->def + tab[x]->def <= 400) p->def += tab[x]->def;
        else {
            if(p->compteur_arme == 0) {
                clear();
                printw("Vous : AAAAAARGH !!!\n");
                refresh();
                getch();

                printw("Vous : Qu'est-ce que c'était que ça ?\n");
                refresh();
                getch();
                
                printw("Vous : On dirait que mes armes ont étées maudits... Je ne peux plus les utiliser...\n");
                refresh();
                getch();

                p->compteur_arme++;
            }

            clear();
            printw("Hélas, vos stats de DEF sont trop élevées\nDe ce fait, vous ne recevez aucun boost de DEF\n");
            refresh();
            getch();
        }

        if(p->def < 0) p->def = 0;
        Pion_informations(p);
        attroff(COLOR_PAIR(1));
        fflush(stdout);
        refresh();
        getch();
    }
}


// Affrontement contre le boss final
void heurter_boss(Grille * g, Pion * p, Monstres ** tab, int * tmp){
    int dante_or_vergil = rand() % 2;
    if(g->tab[p->x][p->y] == BOSS){
        clear();
        while (p->pv > 0 && tab[dante_or_vergil]->pv > 0){
            affrontement_boss(g, tab, p, dante_or_vergil, tmp);
        }
        attroff(COLOR_PAIR(1));
        fflush(stdout);
    }
}

// Fonction utilisé dans toutes les fonctions mettant en scène un combat
void combat(Pion * p, Monstres ** tab, int x){
    int choix;
    float degats;
    printw("Le combat commence !\n");
    printw("Choisissez l'attaque à lancer : \n");
    printw("1. Attaque enchaînée (ATK : x1.0)\n");
    printw("2. Charge (ATK : x1.5 / DEF : -15.0)\n");
    printw("3. Explosion d'énergie (PV : 1 / ATK : x4.5)\n");
    printw("Votre choix : ");
    refresh();

    do
    {
        choix = getch();
        beep();
    } while (choix < '1' || choix > '3');

    switch(choix - '0'){
        case 1:
            degats = (p->atk * 1.0) - tab[x]->def;
            if(degats < 0) degats = 0;
            printw("Vous avez choisi l'Attaque enchaînée !\n%s prend %.3f dégats !\n", tab[x]->nom, degats);
            tab[x]->pv -= degats;
            break;

        case 2:
            degats = (p->atk * 1.5) - tab[x]->def;
            if(degats < 0) degats = 0;
            printw("Vous avez choisi la Charge !\nPar conséquent, %s prend %.3f dégats et vous perdez %.3f en défense !\n", tab[x]->nom, degats, -15.0);
            tab[x]->pv -= degats;
            p->def -= 15.0;
            if(p->def <= 0) p->def = 0;
            break;

        case 3:
            degats = (p->atk * 4.5) - tab[x]->def;
            if(degats < 0) degats = 0;
            printw("Vous avez choisi l'Explosion d'énergie !\nPar conséquent, %s prend %.3f dégats et il vous reste %.3f pv !\n", tab[x]->nom, degats, 1.0);
            tab[x]->pv -= degats;
            p->pv = 1.0;
            break;
    }

    refresh();
}

// Fonction qui permet aux monstres d'attaquer
void attaque_monstre(Pion * p, Monstres ** tab, int x){
    float degats;
    if(p->pv > 0) {
        degats = tab[x]->atk - p->def;
        if(degats < 0) degats = 0;
        p->pv -= degats;
        printw("\n\n%s vous attaque, vous subissez %.3f dégâts", tab[x]->nom, degats);
        printw("\nAppuyez sur une touche pour continuer...");
        refresh();
        getch();
    }
}

// Fonction de fin de jeu qui se lance quand on a perdu
void game_over(Pion * p, int * tmp){
    if(p->pv <= 0){
        clear();
        printw("GAME OVER !");
        printw("\nAppuyez sur une touche pour continuer...");
        refresh();
        getch();
        *tmp = 1;
    }
}

// Fonction qui s'enclenche en cas de victoire face à un monstre
int victoire(Monstres ** tab, int x, Pion * p){
    int recompense = 1 + rand() % (4 - 2);
    if(tab[x]->pv > 0) return 0;
    clear();
    printw("Vous avez vaincu %s !\n", tab[x]->nom);
    getch();
    printw("En récompense vous gagnez : ");
    switch(recompense){
        case 1:
            printw("PV + 100\n");
            p->pv += 100;
            Pion_informations(p);
            break;
        
        case 2:
            printw("ATK + 50\n");
            p->atk += 50;
            Pion_informations(p);
            break;

        case 3:
            printw("DEF + 50\n");
            p->def += 50;
            Pion_informations(p);
            break;
    }
    refresh();
    getch();

    return 1;

}

// Fonction qui lance l'affrontement contre le boss
void affrontement_boss(Grille * g, Monstres ** tab, Pion * p, int x, int * tmp){
    clear();
    attron(COLOR_PAIR(1));
    printw("ATTENTION !!!\nVOUS AFFRONTEZ UN BOSS !!!\nLE BOSS %s !!!\n", tab[x]->nom);
    informations_monstres(tab, x);
    printw("\n");
    Pion_informations(p);
    printw("\n");
    combat(p, tab, x);
    refresh();
    
    printw("Appuyez sur une touche pour continuer...");
    
    refresh();
    
    getch();
    
    // victoire(tab, dante_or_vergil, p);
    attaque_monstre(p, tab, x);
    defaite_boss(tab, p, x, tmp);
}

// Fonction qui se lance en cas de défaite face au boss
void defaite_boss(Monstres ** tab, Pion * p, int x, int * tmp){
    char paroles[TAILLE_PAROLES];
    clear();
    printw("%s vous a vaincu et vous nargue...\n", tab[x]->nom);
    refresh();
    getch();

    printw("HAHAHA t'es un peu trop nul\nJe sais même pas d'où t'es venu l'arrogance de venir m'affronter\n");
    refresh();
    getch();

    printw("Bon... ne perdons pas de temps inutiles\nQuelles sont tes dernières paroles ?\n");
    getch();
    refresh();
    echo();
    scanw("%s", paroles);
    noecho();
    refresh();

    if(strcmp(paroles, "FuckLesEtudes") == 0) fin_secrete(tmp);
    else fin_classique(tmp);
}

// Fin secrète
void fin_secrete(int * tmp){
    printw("HAHAHA toi je t'aime bien\n");
    refresh();
    getch();

    printw("Eteins moi cet écran et retourne réviser\n");
    refresh();
    getch();

    printw("T'as les partiels qui approchent\n");
    refresh();
    getch();

    *tmp = 1;
}

// Fin classique
void fin_classique(int * tmp){
    printw("Ce sont ça tes dernière paroles ?\n");
    refresh();
    getch();

    printw("Allez quoi, tu peux faire mieux que ça\n");
    refresh();
    getch();

    printw("Pfff... tu me déçois.\n");
    refresh();
    getch();

    printw("Je m'attendais à meilleur de ta part, que tu me réserves une botte secrète\n");
    refresh();
    getch();

    printw("Que tu me divertisses un peu\n");
    refresh();
    getch();

    printw("Bon... tant pis\n");
    refresh();
    getch();

    printw("Il est temps de mettre un terme à cette discussion\n");
    refresh();
    getch();

    printw("Adieu");
    refresh();
    getch();

    *tmp = 1;
}

void histoire_jeu(){
    clear();
    printw("Inconnu 1 : A l'aiiiiiiide !!!...\n");
    refresh();
    getch();

    printw("Inconnu 2 : Aaaaaaaargh !!!...\n");
    refresh();
    getch();

    printw("Inconnu 3 : NON PAS MA FILLE, S'IL VOUS PLAIT...\n");
    refresh();
    getch();

    printw("\nHaut-parleur : Attention à tous les habitants de cette ville...\n");
    refresh();
    getch();

    printw("Haut-parleur : Ceci n'est pas un exercice...\n");
    refresh();
    getch();

    printw("Haut-parleur : Veuillez évacuer les lieux sur le champs...\n");
    refresh();
    getch();

    printw("\nVous : Haaa... Haaa...\n");
    refresh();
    getch();

    printw("Vous : Mais... haaa... qu'est-ce qui se passe...\n");
    refresh();
    getch();

    printw("Vous : Quel était cet explosion à l'instant...\n");
    refresh();
    getch();

    printw("Vous : Et... Pourquoi il y a une fissure dans le ciel...\n");
    refresh();
    getch();

    printw("Vous : Haaa... J'ai l'impression que les dimensions s'entre-mêles\n");
    refresh();
    getch();

    printw("Vous : C... C'est... C'est moi ou il y a vraiment un monstres en train de déguster une fille et sa maman !!!\n");
    refresh();
    getch();

    printw("Vous : Mais qu'est-ce qu'il se passe bon sang ?\n");
    refresh();
    getch();

    printw("Vous : En temps que soldat... Il faut vite que je retrouve mes armes et que je mette fin à ce cauchemar\n");
    refresh();
    getch();
}