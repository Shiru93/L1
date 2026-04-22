# Indiquer le compilateur
CC=gcc

# Options du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

# Déclarer ses propres variables
OBJETS=flotte_voiture.o main.o
PROG=voiture

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG)

flotte_voiture.o : flotte_voiture.c flotte_voiture.h
	gcc -c $(CFLAGS) flotte_voiture.c

main.o : main.c flotte_voiture.h
	gcc -c $(CFLAGS) main.c

clean :
	rm $(PROG) $(OBJETS)