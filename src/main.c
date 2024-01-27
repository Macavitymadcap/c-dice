#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dice.h"
#include "parse.h"

int main(int argc, char *argv[])
{
    // advantage critical disadvantage scores
    // char *options = "acds";
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s notation\n", argv[0]);
        return 1;
    }
    
    DiceRoll diceRoll = parseNotation(argv[1]);
    
    srand(time(0));

    int roll = rollDieOrDice(diceRoll); 

    if (hasModifier(diceRoll))
    {
        roll = applyModifier(roll, *diceRoll.operator, *diceRoll.modifier);
    }

    freeDiceRoll(&diceRoll);

    printf("Roll %s: %i\n", argv[1], roll);
        
    return 0;
}