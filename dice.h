#ifndef DICE_H
#define DICE_H

/**
 * @brief Roll a die with a number of faces.
 * 
 * @param faces (int) - The number of faces on the die.
 * @returns (int) - The result of the roll.
*/
int rollDie(int faces);

/**
 * @brief Roll a number of dice with a number of faces.
 * 
 * @param numDice (int) - The number of dice to roll.
 * @param faces (int) - The number of faces on the dice.
 * @returns (int) - the result of the roll.
*/
int rollDice(int numDice, int faces);

/**
 * @brief Determine whether the character is a a standard arithemtic operator
 * 
 * @returns (int) - 0 if a standard operator, else non-zero;
*/
int isValidOperator(char operator);

/**
 * @brief Apply an arithmetic modifier to number.
 * 
 * @param number (int) - The number upon which to apply the operation.
 * @param operator (char) - Standard arithmetic operator: +|-|*|/.
 * @param modifier (int) - The modifier to apply to the number with the operator.
 * @returns (int) - The result of applying the operation to the number.
*/
int applyModifier(int number, char operator, int modifier);

#endif