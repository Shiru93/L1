CC=gcc

CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS=liste.o main.o
PROG=guichets

all : $(OBJETS)
	gcc $(OBJETS) -o $(PROG)

liste.o : liste.c liste.h
	gcc -c $(CFLAGS) liste.c

Poste.o : Poste.c Poste.h
	gcc -c $(CFLAGS) Poste.c

main.o : main.c liste.h Poste.h
	gcc -c $(CFLAGS) main.c

clean :
	rm $(PROG) $(OBJETS)