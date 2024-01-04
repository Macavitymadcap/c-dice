CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LDFLAGS=

roll: main.c dice.c parse.c dice.h parse.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o roll main.c dice.c parse.c

.PHONY: clean

clean:
	rm -f roll