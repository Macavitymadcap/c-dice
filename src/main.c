#define _GNU_SOURCE

#include <openssl/rand.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "printers.h"
#include "dice.h"
#include "parse.h"
#include "errors.h"

int main(int argc, char *argv[])
{
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
            free(rollType);
            printUsage(argv[0]);
            exit(EXIT_FAILURE);

        default:
            free(rollType);
            exit(EXIT_FAILURE);
        }
    }
    
    unsigned char seed[8];
    if (RAND_bytes(seed, sizeof(seed)) != 1)
    {   
        free(rollType);
        randomSeedingError();
    }

    srand(*((unsigned int *)seed));

    if (strcmp(rollType, SCORES) == 0)
    {
        int scores[ABILITY_SCORES];
        rollScores(scores);
        printRollArray(SCORES, NULL, scores, ABILITY_SCORES);
        free(rollType);
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

    if (strcmp(rollType, ADVANTAGE) == 0)
    {
        int results[VANTAGE_ROLLS];
        rollAdvantage(diceRoll, results);
        printRollArray(ADVANTAGE, notation, results, VANTAGE_ROLLS);
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
        printRollArray(DISADVANTAGE, notation, results, VANTAGE_ROLLS);
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
