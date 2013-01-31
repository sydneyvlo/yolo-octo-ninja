#ifndef LETTERBAG_H 
#define LETTERBAG_H
#include <vector>

// This letter bag 
// This is so we can use this bag with multiple data types
// This indicates that this is a template definition
//template <class ItemType>

class LetterBag {
	
	public:

		// Constructor. Takes in no arguments. Will do absolutely nothing.
		LetterBag();

		// Put the letters from the vector v into the bag.
		LetterBag(const  std::vector<char> &v); // Why in the world did I need to use std::vector instead of vector.

		// Checks to see if the two bags contain the same content. No more no less.
		bool operator==(const LetterBag &other) const;

		// Is true if the two bags are not identical
		bool operator!=(const LetterBag &other) const;

		// Returns the current size of the bag.
		int getCurrentSize() const;

		// Returns true if the bag is empty. False if it is not.
		bool isEmpty() const;

		// Adds a character to the bag.
		LetterBag &add(char c);

		// Removes a character from the bag
		// pre condition: The item has to be present in the bag.
		// post condition: One instance of the item is removed.
		LetterBag &remove(char c);
		
		// Empties out the bag.
		//pre conditon: Non
		//post condition: Empty bag
		LetterBag &clear();

		// Returns the number of times that an item appears in the bag.
		int getFrequency(char c) const;

		// Returns a vector that is a duplicate of the bag.(Which in our case is an array).
		 std::vector<char> toVector() const;

	private:
		int Bag[27];


};

// #include "LetterBag.cpp"; // Include the implementation file.
//#include "LetterBag.cpp"
#endif