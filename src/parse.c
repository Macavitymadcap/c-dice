#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "parse.h"
#include "errors.h"

// String representation of the Regular expression for dice notation
const char *DICE_NOTATION = "^([0-9]*)*d*([0-9]+)([+-/*]?)*([0-9]*)$";

DiceRoll parseNotation(const char *notation)
{
    DiceRoll diceRoll = {NULL, 0, NULL, NULL};

    regex_t regex;
    regmatch_t matches[5];
    int reti;

    reti = regcomp(&regex, DICE_NOTATION, REG_EXTENDED);
    if (reti)
    {
        regexCompilationError();
    }

    reti = regexec(&regex, notation, 5, matches, 0);
    if (!reti)
    {
        if (matches[1].rm_so != -1)
        {
            char *endPointer;
            diceRoll.numDice = (int *)malloc(sizeof(int));
            char numDiceString[10] = "";
            strncpy(numDiceString, &notation[matches[1].rm_so], matches[1].rm_eo - matches[1].rm_so);
            *(diceRoll).numDice = strtol(numDiceString, &endPointer, 10);
        }

        if (matches[2].rm_so != -1)
        {
            char *endPointer;
            char facesString[10] = "";
            strncpy(facesString, &notation[matches[2].rm_so], matches[2].rm_eo - matches[2].rm_so);
            diceRoll.faces = strtol(facesString, &endPointer, 10);
        }

        if (matches[3].rm_so != -1)
        {
            diceRoll.operator=(char *) malloc(sizeof(char));
            *(diceRoll).operator= notation[matches[3].rm_so];
        }

        if (matches[4].rm_so != -1)
        {
            char *endPointer;
            diceRoll.modifier = (int *)malloc(sizeof(int));
            char modifierString[10] = "";
            strncpy(modifierString, &notation[matches[4].rm_so], matches[4].rm_eo - matches[4].rm_so);
            *(diceRoll).modifier = strtol(modifierString, &endPointer, 10);
        }
    }
    else if (reti == REG_NOMATCH)
    {
        invalidDiceNotationError(notation);
    }
    else
    {
        regexMatchError(reti, regex);
    }

    regfree(&regex);

    return diceRoll;
}

void freeDiceRoll(DiceRoll *diceRoll)
{
    free(diceRoll->numDice);
    free(diceRoll->operator);
    free(diceRoll->modifier);
}
