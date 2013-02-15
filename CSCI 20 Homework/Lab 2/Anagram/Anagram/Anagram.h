#ifndef ANAGRAM_H
#define ANAGRAM_H

class Anagram : public LetterBag {
	public:
		Anagram(string uString);
		string getString();
		void add();
		void remove();
		void clear();

	private:
		

}

#endif