# Indiquer le compilateur
CC=gcc

# Options du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

# Déclarer ses propres variables
OBJETS=polynome.o main.o
PROG=polynome

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG) -lm

polynome.o :  polynome.c polynome.h
	gcc -c $(CFLAGS) polynome.c -lm

main.o : main.c polynome.h
	gcc -c $(CFLAGS) main.c -lm

clean :
	rm $(PROG) $(OBJETS)