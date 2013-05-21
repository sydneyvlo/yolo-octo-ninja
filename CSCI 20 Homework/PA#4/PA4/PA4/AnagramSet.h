#ifndef ANAGRAM_SET_H
#define	ANAGRAM_SET_H

#include <string>
#include <iostream>
using namespace std;

class AnagramSet: public Dictonary {
	friend ostream &operator<<(ostream &out, AnagramSet obj);

public:

	// Constructor 1
	AnagramSet(string key);
	int getSize();

private:

}

#endif;