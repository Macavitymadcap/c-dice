#define _GNU_SOURCE

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "printers.h"
#include "dice.h"
#include "parse.h"

int main(int argc, char *argv[])
{
    // advantage critical disadvantage help scores
    char *options = "acdhs";
    int opt;

    char *rollType = malloc(15 * sizeof(char));
    strncpy(rollType, STANDARD, strlen(STANDARD));

    while ((opt = getopt(argc, argv, options)) != -1)
    {
        switch (opt)
        {
        case 'a': 
            strncpy(rollType, ADVANTAGE, strlen(ADVANTAGE));
            break;

        case 'c':
            strncpy(rollType, CRITICAL, strlen(CRITICAL));
            break;

        case 'd':
            strncpy(rollType, DISADVANTAGE, strlen(DISADVANTAGE));
            break;

        case 'h':
            printHelp(argv[0]);
            exit(EXIT_SUCCESS);

        case 's':
            strncpy(rollType, SCORES, strlen(SCORES));
            break;

        case '?':
            printUsage(argv[0]);
            exit(EXIT_FAILURE);

        default:
            exit(EXIT_FAILURE);
        }
    }

    if (strcmp(rollType, SCORES) == 0)
    {
        int scores[ABILITY_SCORES];
        rollScores(scores);
        printRollArray(rollType, NULL, scores, 6);
        exit(EXIT_SUCCESS);
    }

    char *notation = NULL;

    if (optind < argc)
    {
        notation = argv[optind];
    }
    else
    {
        printUsage(argv[0]);
        exit(EXIT_FAILURE);
    }

    DiceRoll diceRoll = parseNotation(notation);
    
    srand(time(0));

    if (strcmp(rollType, ADVANTAGE) == 0)
    {
        int results[VANTAGE_ROLLS]; 
        rollAdvantage(diceRoll, results);
        printRollArray(ADVANTAGE, notation, results, 2);
    }
    else if (strcmp(rollType, CRITICAL) == 0)
    {
        int result = rollCritical(diceRoll);
        printRoll(notation, CRITICAL, result);
    }
    else if (strcmp(rollType, DISADVANTAGE) == 0)
    {
        int results[VANTAGE_ROLLS];
        rollDisadvantage(diceRoll, results);
        printRollArray(DISADVANTAGE, notation, results, 2);
    }
    else
    {
        int result = rollStandard(diceRoll);
        printRoll(notation, STANDARD, result);
    }

    freeDiceRoll(&diceRoll);
    free(rollType);
        
    exit(EXIT_SUCCESS);
}
