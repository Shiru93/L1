CC=gcc

CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS=Fonctions_UNDO.o Fonctions_jeu.o Grille.o Pion.o main.o
PROG=jeu

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG) -lncurses

Grille.o : Grille.c Grille.h
	gcc -c $(CFLAGS) Grille.c

Pion.o : Pion.c Pion.h Grille.h Fonctions_jeu.h Fonctions_UNDO.h
	gcc -c $(CFLAGS) Pion.c

Fonctions_jeu.o : Fonctions_jeu.c Fonctions_jeu.h Fonctions_UNDO.h
	gcc -c $(CFLAGS) Fonctions_jeu.c

Fonctions_UNDO.o : Fonctions_UNDO.c Fonctions_UNDO.h Pion.h
	gcc -c $(CFLAGS) Fonctions_UNDO.c

main.o : main.c Grille.h Pion.h Fonctions_jeu.h Fonctions_UNDO.h
	gcc -c $(CFLAGS) main.c

clean :
	rm $(PROG) $(OBJETS)