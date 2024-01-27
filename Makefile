CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c17 -g
LDFLAGS=-lm

SRC=src/main.c src/dice.c src/parse.c
OBJ=$(patsubst src/%.c, build/%.o, $(SRC))

roll: $(OBJ)
	$(CC) $(CFLAGS) -o roll $(OBJ) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -Iinclude -c -o $@ $<

.PHONY: clean

clean:
	rm -f build/*.o roll
