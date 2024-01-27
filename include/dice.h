/**
 * @file dice.h
 * @brief Functions for rolling dice
*/
#ifndef DICE_H
#define DICE_H

#include "parse.h"

/**
 * @brief String representing a roll at advantage.
*/
extern const char *ADVANTAGE;

/**
 * @brief String representing a roll of a critical hit.
*/
extern const char *CRITICAL;

/**
 * String representing a roll at disadvantage.
*/
extern const char *DISADVANTAGE;

/**
 * @brief String representing a roll of ability scores.
*/
extern const char *SCORES;

/**
 * @breif String representing a standard roll.
*/
extern const char *STANDARD;

/**
 * @brief number of dice rolled for an ability score
*/
extern int const ABILITY_SCORE_DICE;

/**
 * @brief Number of ability scores.
*/
extern int const ABILITY_SCORES;

/**
 * @brief Number of times to roll for advantage or disadvantage.
*/
extern int const VANTAGE_ROLLS;

/**
 * @brief Roll a die with a number of faces.
 * 
 * @param faces The number of faces on the die.
 * @returns The result of the roll.
*/
int rollDie(int faces);

/**
 * @brief Roll a number of dice with a number of faces.
 * 
 * @param numDice The number of dice to roll.
 * @param faces The number of faces on the dice.
 * @returns The result of the roll.
*/
int rollDice(int numDice, int faces);

/**
 * @brief Call rollDie or rollDice depending on the presence of numDice.
 * 
 * @param diceRoll The parsed dice notation to be rolled.
 * @returns The result of the roll. 
*/

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
 * @brief Apply an arithmetic modifier to number.
 * 
 * @param number The number upon which to apply the operation.
 * @param operator Standard arithmetic operator: +|-|*|/.
 * @param modifier The modifier to apply to the number with the operator.
 * @returns The result of applying the operation to the number.
*/
int applyModifier(int number, char operator, int modifier);

/**
 * @brief Roll a die or multiple dice.
 * @param diceRoll The parsed constieunts of a roll.
 * @returns The result of the roll.
*/
int rollDieOrDice(DiceRoll diceRoll);


/**
 * Roll a die or dice and apply a modifier if present.
 * @param diceRoll The parse constiuents of a roll.
 * @returns The result of the roll with modifier applied if present.
*/
int rollStandard(DiceRoll diceRoll);

/**
 * @brief Sorts an array of integers in ascending order.
 * @param arr Array of integers.
 * @param size The length of the array.
*/
void sortDescending(int arr[], int size);

/**
 * @brief Roll 4d6 and return the total ignoreing the lowest roll.
 * @returns The total of the 3 highest dice rolled. 
*/
int rollAbility(void);

/**
 * @brief Roll 6 ability scores, each 4d6 - the lowest roll.
 * @param results Array into which the results will be written.
*/
void rollScores(int results[]);

/**
 * @brief Roll twice and return both ordered high to low.
 * @param diceRoll Parsed dice notation to be rolled.
 * @param results Array into which the results will be written.
*/
void rollAdvantage(DiceRoll diceRoll, int results[]);

/**
 * @brief Roll twice and return both ordered low to high.
 * @param diceRoll Parsed dice notation to be rolled.
 * @param results Array into which the results will be written.
*/
void rollDisadvantage(DiceRoll diceRoll, int results[]);

/**
 * @brief Roll the dice twice and then apply modifiers.
 * 
 * @param diceRoll Parsed dice notation to be rolled.
 * @returns Result of the critical roll.
*/
int rollCritical(DiceRoll diceRoll);

#endif