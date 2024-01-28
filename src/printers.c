#include <stdlib.h>
#include <stdio.h>

#include "parse.h"

void printUsage(const char *programName)
{
    fprintf(stderr, "Usage: %s [OPTIONS] [NOTATION]\n", programName);
}

void printHelp(const char *programName)
{
    printUsage(programName);
    printf("Roll dice based on the provided options and notation.\n\n");
    printf("Options:\n");
    printf("  -a\tRoll at advantage (twice, high to low)\n");
    printf("  -c\tRoll a critical hit (double the dice)\n");
    printf("  -d\tRoll at disadvantage (twice, low to high)\n");
    printf("  -h\tDisplay this help text\n");
    printf("  -s\tRoll ability scores (6 4d6 - the lowest)\n");
    printf("\n");
    printf("Arguments:\n");
    printf("  NOTATION  <string> Follows the format 'XdY?Z', where: \n");
    printf("\t- X:  optional number of dice to be rolled\n");
    printf("\t- dY: the kind of die to roll, Y being the number of faces\n");
    printf("\t- ?:  optional operator [+|-|*|/] which applies the modifier to the roll\n");
    printf("\t- Z:  optional modifier applied to the roll\n");
    printf("\n");
    printf("Examples:\n");
    printf("  %s -a d20-1\n", programName);
    printf("  %s -c 4d6+3\n", programName);
    printf("  %s -d 1d20\n", programName);
    printf("  %s -s\n", programName);
    printf("  %s 3d12*2\n", programName);
    printf("  %s d100/2\n", programName);
}

void printRollArray(const char *rollType, const char *notation, int results[], int size)
{
    printf("Roll ");
    if (notation != NULL)
    {
        printf("%s ", notation);
    }

    printf("(%s): ", rollType);

    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            printf("%i\n", results[i]);
        }
        else
        {
            printf("%i, ", results[i]);
        }
    }
}

void printRoll(const char *notation, const char *rollType, int result)
{
    printf("Roll %s (%s): %i\n", notation, rollType, result);
}