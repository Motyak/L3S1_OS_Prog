#!/bin/sh
printf "Suppression des fichiers .o précompilés\n\n"
rm obj/*.o
printf "compilation de Liste.c\n\n"
gcc -c src/Liste.c -o obj/Liste.o
printf "compilation de main.c\n\n"
gcc -c src/main.c -o obj/main.o
printf "construction du prog main\n\n"
gcc obj/Liste.o obj/main.o -o bin/main
