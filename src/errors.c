#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include "errors.h"
#include "printers.h"

void regexCompilationError(void)
{
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
}

void integerSizeError(int value)
{
    if (value == 0)
    {
        fprintf(stderr, "Inavild integer: %i. Minimum value is 1.\n", value);
    }
    else
    {
        fprintf(stderr, "Invalid integer: %i. Maximum value is 99999999\n", value);
    }
    exit(EXIT_FAILURE);
}

void invalidDiceNotationError(const char *notation)
{
    fprintf(stderr, "'%s' is not valid dice notation\n", notation);
    exit(EXIT_FAILURE);
}

void regexMatchError(int reti, regex_t regex)
{
    char errorBuffer[100];
    regerror(reti, &regex, errorBuffer, sizeof(errorBuffer));
    fprintf(stderr, "Regex match failed: %s\n", errorBuffer);
    exit(EXIT_FAILURE);
}

void zeroDivisionError(void)
{
    fprintf(stderr, "Error: Division by zero\n");
    exit(EXIT_FAILURE);
}

void invalidOperatorError(const char operator)
{
    fprintf(stderr, "'%c' is not supported as an operator. Use one of +|-|*|/\n", operator);
    exit(EXIT_FAILURE);
}

void randomSeedingError(void)
{
    fprintf(stderr, "Unable to seed random numbers\n");
    exit(EXIT_FAILURE);
}

void usageError(const char *programName)
{
    printUsage(programName);
    exit(EXIT_FAILURE);
}