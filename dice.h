#ifndef DICE_H
#define DICE_H

/**
* Returns the result of rolling a die with a given number of faces
* 
* @param faces (int) - The number of faces on the die
* returns int - the result of the roll
*/
int rollDie(int faces);

/**
* Returns the result of rolling a number of dice with a given number of faces
* 
* @param numDice (int) - The number of dice to roll
* @param faces (int) - The number of faces on the dice
* @returns (int) - the result of the roll
*/
int rollDice(int numDice, int faces);

#endif