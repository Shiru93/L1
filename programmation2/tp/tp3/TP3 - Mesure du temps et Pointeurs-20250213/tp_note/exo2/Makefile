# Indiquer le compilateur
CC=gcc

# Options du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

# Déclarer ses propres variables
OBJETS=Equipe.o Match.o main_top14_etu.o
PROG=rugby

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG)

Equipe.o :  Equipe.c Equipe.h
	gcc -c $(CFLAGS) Equipe.c

Match.o : Match.c Match.h
	gcc -c $(CFLAGS) Match.c

main_top14_etu.o : main_top14_etu.c Equipe.h Match.h
	gcc -c $(CFLAGS) main_top14_etu.c

clean :
	rm $(PROG) $(OBJETS)