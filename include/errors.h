/**
 * @file errors.h
 * @brief Errors thrown by the program
*/

#ifndef ERRORS_H
#define ERRORS_H

#include <regex.h>

/**
 * @brief Exit program if regex fails to compile.
*/
void regexCompilationError(void);


/**
 * @brief Exit program if integer outside bounds is passed
 * @param value Less than 0 or greater than 99999999.
*/
void integerSizeError(int value);

/**
 * @brief Exit program if the dice notation is invalid.
 * @param notation String of the invalid dice notation.
*/
void invalidDiceNotationError(const char *notation);

/**
 * @brief Exit program if regex fails to compile.
 * @param reti Number indicating succes of match.
 * @param regex The attempted pattern match
*/
void regexMatchError(int reti, regex_t regex);

/**
 * @brief Exit program if division by zero is attempted.
*/
void zeroDivisionError(void);

/**
 * @brief Exit program if an invalid operator is provided in dice notation.
 * @param operator The invalid operator (not [+|-|*|/]).
*/
void invalidOperatorError(const char operator);

/**
 * @brief Exit program if invaild options and/or arguments are provided
 * @param programName The name of the program.
*/
void usageError(const char *programName);

#endif
