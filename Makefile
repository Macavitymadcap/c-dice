CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c17 -g
LDFLAGS=-lm
INCLUDE=-Iinclude

BUILD=build
ROLL=roll

SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, $(BUILD)/%.o, $(SRC))

$(shell mkdir -p $(BUILD))

$(ROLL): $(OBJ)
	$(CC) $(CFLAGS) -o $(ROLL) $(OBJ) $(LDFLAGS)

$(BUILD)/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(BUILD)/*.o $(ROLL) 
