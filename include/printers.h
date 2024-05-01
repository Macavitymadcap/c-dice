/**
 * @file printers.h
 * @brief Functions for printing outputs.
*/

#ifndef PRINTERS_H
#define PRINTERS_H

#include "parse.h"

/**
 * @brief Prints the intended usage for the program.
 * @param programName The nme of the program.
*/
void printUsage(const char *programName);


/**
 * @brief Prints out the help text for the program.
 * @param programName The name of the program.
*/
void printHelp(const char* programName);

/**
 * @brief Print an array of rolls.
 * @param rollType String of the roll's type (Advantage, Disavantage or Scores).
 * @param notation The dice notation rolled (set to NULL for Scores).
 * @param results The array of rolls to be printed.
 * @param size The length of the results array.
*/
void printRollArray(const char *rollType, const char *notation, int results[], int size);

/**
 * @brief Print the result of a roll.
 * @param notation String of the dice notation rolled.
 * @param rollType String of the roll's type (Standard or Critical).
 * @param result The result of the roll.
*/
void printRoll(const char* notation, const char* rollType, int result);

#endif
