#include <stdlib.h>
#include "dice.h"

int rollDie(int faces)
{
    return (rand() % faces) + 1;
}

int rollDice(int numDice, int faces)
{
    int result = 0;

    for (int i = 0; i < numDice; i++)
    {
        result += rollDie(faces);
    }

    return result;
}