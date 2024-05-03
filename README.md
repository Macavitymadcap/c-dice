# c-dice

A simple program for rolling D&D dice implemented in C compiled with gcc for linux.

# Requirements
- math.h

# Usage

Compile with `make`, then run: `./roll [OPTIONS] [NOTATION]`

```
OPTIONS:
    -a    Roll at advantage (twice, high to low)
    -c    Roll a critical hit (double the dice)
    -d    Roll at disadvantage (twice, low to high)
    -h    Display this help text
    -s    Roll ability scores (6 4d6 - the lowest)

NOTATION Follows the format 'XdY?Z', where: 
    - X:  optional number of dice to be rolled
    - dY: the kind of die to roll, Y being the number of faces
    - ?:  optional operator [+|-|*|/] which applies the modifier to the roll
    - Z:  optional modifier applied to the roll
```