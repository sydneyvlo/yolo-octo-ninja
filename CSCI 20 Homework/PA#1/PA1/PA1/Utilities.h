#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
using namespace std;

// get an integer from the user
int getInt(string prompt);	


// display a list of up to 26 choices and return user's selection
// choices are listed alphabetically, starting with 'a'.
// user choice is returned as an int (a --> 1, b --> 2 etc).
int getChoice(string choices[], int numChoices) ;

// get a random integer
int randomInt(int min, int max);

#endif