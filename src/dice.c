#include <stdlib.h>
#include <math.h>

#include "dice.h"
#include "validation.h"
#include "errors.h"

const char *ADVANTAGE = "Advantage";
const char *CRITICAL = "Critical";
const char *DISADVANTAGE = "Disadvantage";
const char *SCORES = "Ability Scores";
const char *STANDARD = "Standard";

int const ABILITY_SCORE_DICE = 4;
int const ABILITY_SCORES = 6;
int const VANTAGE_ROLLS = 2;

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
            zeroDivisionError();
        }
        double result = (double)number / modifier;
        return (int)round(result);

    default:
        invalidOperatorError(operator);
        return 0;
    }
}

int rollDieOrDice(DiceRoll diceRoll)
{
    int roll;

    if (hasNumDice(diceRoll))
    {
        roll = rollDice(*diceRoll.numDice, diceRoll.faces);
    }
    else
    {
        roll = rollDie(diceRoll.faces);
    }

    return roll;
}

int rollStandard(DiceRoll diceRoll)
{
    int result = rollDieOrDice(diceRoll);

    if (hasModifier(diceRoll))
    {
        return applyModifier(result, *diceRoll.operator, * diceRoll.modifier);
    }

    return result;
}

void sortDescending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int rollAbility(void)
{
    int score[ABILITY_SCORE_DICE];

    for (int i = 0; i < ABILITY_SCORE_DICE; i++)
    {
        score[i] = rollDie(6);
    }

    sortDescending(score, ABILITY_SCORE_DICE);

    return score[0] + score[1] + score[2];
}

void rollScores(int results[])
{
    for (int i = 0; i < ABILITY_SCORES; i++)
    {
        results[i] = rollAbility();
    }

    sortDescending(results, ABILITY_SCORES);
}

void rollAdvantage(DiceRoll diceRoll, int results[])
{
    int rollA = rollStandard(diceRoll);
    int rollB = rollStandard(diceRoll);

    if (rollA >= rollB)
    {
        results[0] = rollA;
        results[1] = rollB;
    }
    else
    {
        results[0] = rollB;
        results[1] = rollA;
    }
}

void rollDisadvantage(DiceRoll diceRoll, int results[])
{
    int rollA = rollStandard(diceRoll);
    int rollB = rollStandard(diceRoll);

    if (rollA <= rollB)
    {
        results[0] = rollA;
        results[1] = rollB;
    }
    else
    {
        results[0] = rollB;
        results[1] = rollA;
    }
}

int rollCritical(DiceRoll diceRoll)
{
    int result = 0;

    for (int i = 0; i < 2; i++)
    {
        result += rollDieOrDice(diceRoll);
    }

    if (hasModifier(diceRoll))
    {
        return applyModifier(result, *diceRoll.operator, * diceRoll.modifier);
    }

    return result;
}
