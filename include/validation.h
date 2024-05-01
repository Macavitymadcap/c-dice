/**
 * @file validation.h
 * @brief Functions for validating input.
*/

#ifndef VALIDATION_H
#define VALIDATION_H

#include "parse.h"

/**
 * @brief Determine whether the character is a a standard arithemtic operator.
 * 
 * @returns 1 if a standard operator, else zero.
*/
int isValidOperator(char operator);

/**
 * @brief Determine whether the DiceRoll has a modifier
 * 
 * @returns 1 if it has a valid modifier, else zero. 
*/
int hasModifier(DiceRoll diceRoll);

/**
 * @brief Determine if an integer is outside of bounds 1-99999999.
 * @param value Integer to be checked.
 * @returns 1 if out of range, otherwise 0.
*/
int integerOutOfRange(int value);

/**
 * @brief Determine whether the DiceRoll has a defined numDice property.
 * @returns 1 if numDice is initialised and non-zero, otherwise 0.
*/
int hasNumDice(DiceRoll diceRoll);

/**
 * @brief Exit program if numeric roperties of diceRoll are out of bounds.
*/
void validateDiceRoll(DiceRoll diceRoll);

#endif
