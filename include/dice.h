#ifndef DICE_H
#define DICE_H

#include "parse.h"

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
 * @brief Call rollDie or rollDice depending on the presence of numDice.
 * 
 * @param diceRoll (DiceRoll) - The parsed dice notation to be rolled.
 * @returns (int) - the result of the roll. 
*/

/**
 * @brief Determine whether the character is a a standard arithemtic operator.
 * 
 * @returns (int) - 0 if a standard operator, else non-zero.
*/
int isValidOperator(char operator);

/**
 * @brief Determine whether the DiceRoll has a modifier
 * 
 * @returns (int) 0 if it has a valid modifier, else non-zero. 
*/
int hasModifier(DiceRoll diceRoll);

/**
 * @brief Apply an arithmetic modifier to number.
 * 
 * @param number (int) - The number upon which to apply the operation.
 * @param operator (char) - Standard arithmetic operator: +|-|*|/.
 * @param modifier (int) - The modifier to apply to the number with the operator.
 * @returns (int) - The result of applying the operation to the number.
*/
int applyModifier(int number, char operator, int modifier);

/**
 * @brief Roll a die or multiple dice and apply modifier.
 * @param (DiceRoll) diceRoll The parsed constieunts of a roll.
 * @returns (int) The result of the roll.
*/
int rollDieOrDice(DiceRoll diceRoll);

// /**
//  * @brief Roll twice and return both ordered high to low.
//  * 
//  * @param diceRoll (DiceRoll) - Parsed dice notation to be rolled.
//  * @returns (int*) - The results ordered highest to lowest.
// */
// int* rollAdvantage(DiceRoll diceRoll);

// /**
//  * @brief Roll twice and return both ordered low to high.
//  * 
//  * @param diceRoll (DiceRoll) - Parsed dice notation to be rolled.
//  * @returns (int*) - The results ordered lowest to highest.
// */
// int* rollDisadvantage(DiceRoll diceRoll);

/**
 * @brief Roll the dice twice and then apply modifiers.
 * 
 * @param diceRoll (DiceRoll) - Parsed dice notation to be rolled.
 * @returns (int) - Result of the critical roll.
*/
int rollCritical(DiceRoll diceRoll);
#endif
