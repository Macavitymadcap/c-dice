CC=gcc
CFLAGS= -Wall -Wextra -Werror -std=c99 -g
LDFLAGS= -lm

roll: main.c dice.c parse.c dice.h parse.h
	$(CC) $(CFLAGS)  -o roll main.c dice.c parse.c $(LDFLAGS)

.PHONY: clean

clean:
	rm -f roll