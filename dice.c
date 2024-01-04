#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isNumber(char *input);
int rollDie(int faces);
int rollDice(int numDice, int faces);

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {
        printf("Usage: %s [numDice] faces\n", argv[0]);
        return 1;
    }

    // Seed random numbers
    srand(time(0));

    // Check arguments are valid
    for (int i = 1; i < argc; i++)
    {
        if (!isNumber(argv[i]))
        {
            printf("Error: numDice and faces must be integers\n");
            return 1;
        }
    }

    // Parse arguments
    int numDice = (argc == 2) ? 1 : atoi(argv[1]);
    int faces = (argc == 2) ? atoi(argv[1]) : atoi(argv[2]);
    
    // Roll the dice
    int roll = rollDice(numDice, faces);
    printf("Rolling %id%i: %i\n", numDice, faces, roll);
    
    return 0;
}

bool isNumber(char *input)
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }

    return true;
}

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