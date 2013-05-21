#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "AnagramSet.h"
#include <string>
#include <iostream>
using namespace std;

class Dictionary {
	
	friend ostream &operator<<(ostream &out, Dictionary obj);
	
public:
		// Constructor 1
		Dictionary(string words[], int numWords, int tableSize);

		// Constructor 2
		Dictionary(int tableSize);

		bool contains(string word);
		void insert(string word);
		void remove(string word);
		AnagramSet getSet(string word);

private:

}

#endif;