#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <math.h>
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

int isValidOperator(char operator)
{
    return operator == '+' || operator == '-' || operator == '*' || operator == '/';
}

int hasModifier(DiceRoll diceRoll)
{
    return diceRoll.operator && diceRoll.modifier && isValidOperator(*diceRoll.operator);
}

int applyModifier(int number, char operator, int modifier)
{
    switch (operator)
    {
    case '+':
        return number + modifier; 

    case '-':
        return number - modifier;

    case '*':
        return number * modifier;

    case '/':
        if (modifier == 0) 
        {
            fprintf(stderr, "Error: Division by zero\n");
            exit(1);
        }
        double result = (double)number / modifier;
        return (int)round(result);

    default:
        fprintf(stderr, "'%c' is not supported as an operator. Use one of +|-|*|/\n", operator);
        exit(1);
        break;
    }
}

int rollDieOrDice(DiceRoll diceRoll)
{
    int roll;

    if (diceRoll.numDice) 
    {
        roll = rollDice(*diceRoll.numDice, diceRoll.faces);
    }
    else
    {
       roll = rollDie(diceRoll.faces); 
    } 

    return roll;
}

// int* rollAdvantage(DiceRoll diceRoll)
// {
//     return [0, 0];
// }

// int* rollDisadvantage(DiceRoll diceRoll)
// {
//     return [0, 0];
// }

int rollCritical(DiceRoll diceRoll)
{
    int result = 0;

    for (int i = 0; i < 2; i++)
    {
        result += rollDieOrDice(diceRoll);
    }

    if (hasModifier(diceRoll))
    {
        return applyModifier(result, *diceRoll.operator, *diceRoll.modifier);
    }

    return result;
}