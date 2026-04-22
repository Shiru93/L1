CC=gcc

CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS=armes.o monstres.o Fonctions_jeu.o Grille.o Pion.o main.o
PROG=jeu

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG) -lncurses

Grille.o : Grille.c Grille.h
	gcc -c $(CFLAGS) Grille.c

Pion.o : Pion.c Pion.h Grille.h Fonctions_jeu.h monstres.h armes.h
	gcc -c $(CFLAGS) Pion.c

Fonctions_jeu.o : Fonctions_jeu.c Fonctions_jeu.h Pion.h monstres.h armes.h
	gcc -c $(CFLAGS) Fonctions_jeu.c

monstres.o : monstres.c monstres.h Grille.h

armes.o : armes.c armes.h armes.h

main.o : main.c Grille.h Pion.h Fonctions_jeu.h monstres.h armes.h
	gcc -c $(CFLAGS) main.c

clean :
	rm $(PROG) $(OBJETS)