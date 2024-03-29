/**
 * @file parse.h
 * @brief Parse a string of dice notation into its constiuents.
*/

#ifndef PARSE_H
#define PARSE_H

/**
 * @struct DiceRoll
 * @brief The components of standard dice notation.
*/
typedef struct 
{
    int *numDice;   /** Pointer to the number of dice (optional) */
    int faces;      /** Required: Number of faces on die/dice */
    char *operator; /** Pointer to the operator (optional) */
    int *modifier;  /** Pointer to the modifer applied with the operator to the roll (optional) */
} DiceRoll;

/**
 * @brief Parse the given string of dice notation into a DiceRoll.
 * 
 * @param notation A string of dice notation
 * @returns The parsed components of the dice notation
*/
DiceRoll parseNotation(const char *notation);

/**
 * @brief Free the given DiceRoll from memory.
 * 
 * @param diceRoll The DiceRoll to be freed from memory.
*/
void freeDiceRoll(DiceRoll *diceRoll);

#endif
