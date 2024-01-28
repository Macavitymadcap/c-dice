CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c17 -g
LDFLAGS=-lm -lssl -lcrypto
INCLUDE=-Iinclude

SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, build/%.o, $(SRC))

roll: $(OBJ)
	$(CC) $(CFLAGS) -o roll $(OBJ) $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

.PHONY: clean

clean:
	rm -f build/*.o roll 
