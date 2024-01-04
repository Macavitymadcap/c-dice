#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "parse.h"

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
