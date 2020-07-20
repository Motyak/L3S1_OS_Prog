CC=gcc
SRC=src/Liste.c
OBJ=obj/Liste.o
HEAD=include/Liste.h

all: $(OBJ)

$(OBJ): $(SRC) $(HEAD)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)