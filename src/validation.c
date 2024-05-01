#include <stdlib.h>

#include "validation.h"
#include "errors.h"
#include "parse.h"

int isValidOperator(char operator)
{
    return operator== '+' || operator== '-' || operator== '*' || operator== '/';
}

int hasModifier(DiceRoll diceRoll)
{
    return *diceRoll.operator && *diceRoll.modifier && isValidOperator(*diceRoll.operator);
}

int integerOutOfRange(int value)
{
    const int MINIMUM = 1;
    const int MAXIMUM = 99999999;

    return value < MINIMUM || value > MAXIMUM;
}

int hasNumDice(DiceRoll diceRoll)
{
    return diceRoll.numDice != NULL && *diceRoll.numDice != 0;
}

void validateDiceRoll(DiceRoll diceRoll)
{
    if (hasNumDice(diceRoll))
    {
        if (integerOutOfRange(*diceRoll.numDice))
        {
            freeDiceRoll(&diceRoll);
            integerSizeError(*diceRoll.numDice);
        }
    }

    if (integerOutOfRange(diceRoll.faces))
    {
        freeDiceRoll(&diceRoll);
        integerSizeError(diceRoll.faces);
    }

    if (hasModifier(diceRoll))
    {
        if (integerOutOfRange(*diceRoll.modifier))
        {
            freeDiceRoll(&diceRoll);
            integerSizeError(*diceRoll.modifier);
        }
    }
}
