CC=gcc
SRC=../libListe/src/Liste.c src/main.c
OBJ=../libListe/obj/Liste.o obj/main.o
EXEC=bin/main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@

../libListe/obj/Liste.o: ../libListe/src/Liste.c ../libListe/include/Liste.h
	$(CC) -c ../libListe/src/Liste.c -o ../libListe/obj/Liste.o

obj/main.o: ../libListe/src/Liste.c ../libListe/include/Liste.h
	$(CC) -c src/main.c -o obj/main.o

clean:
	rm -rf $(OBJ)