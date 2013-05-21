#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary {
	
	friend ostream &operator<<(ostream &out, Dictionary obj);
	
public:
		
		// Constructor
		Dictionary(string words[], int numWords, int tableSize);
	

private:

}

#endif;