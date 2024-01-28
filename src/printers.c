#include <stdlib.h>
#include <stdio.h>

void printUsage(const char *programName)
{
    fprintf(stderr, "Usage: %s [OPTIONS] [NOTATION]\n", programName);
}

void printHelp(const char *programName)
{
    printUsage(programName);
    printf("Roll dice based on the provided options and notation.\n\n");
    printf("Options:\n");
    printf("\t-a\t Roll at advantage (twice, high to low)\n");
    printf("\t-c\t Roll a critical hit (double the dice)\n");
    printf("\t-d\t Roll at disadvantage (twice, low to high)\n");
    printf("\t-h\t Display this help text\n");
    printf("\t-s\t Roll ability scores (6 4d6 - the lowest)\n");
    printf("\nIf no option is provided the NOTATION is rolled normally.\n");
    printf("\n");
    printf("Arguments:\n");
    printf("\tNOTATION Follows the format 'XdY?Z', where: \n");
    printf("\t  - X:\tOptional number of dice to be rolled\n");
    printf("\t  - dY:\tKind of die to roll, Y being the number of faces\n");
    printf("\t  - ?:\tOptional operator [+|-|*|/] used to apply a modifier\n");
    printf("\t  - Z:\tOptional modifier applied to the roll\n");
    printf("\nAll integer values must be in range 1-99999999\n");
    printf("\n");
    printf("Examples:\n");
    printf("\t%s -a d20-1\n", programName);
    printf("\t%s -c 4d6+3\n", programName);
    printf("\t%s -d 1d20\n", programName);
    printf("\t%s -s\n", programName);
    printf("\t%s 3d12*2\n", programName);
    printf("\t%s d100/2\n", programName);
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