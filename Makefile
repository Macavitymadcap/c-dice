CC=gcc
CFLAGS=-o

dice: dice.c
	$(CC) $(CFLAGS) dice dice.c

.PHONY: clean

clean:
	rm -f *.o $(objects) dice