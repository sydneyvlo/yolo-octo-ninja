#include <iostream>
#include "LetterBag.h"
#include <vector>
#include <stdio.h>
#include <ctype.h>
using namespace std;



//template <class ItemType>
LetterBag :: LetterBag() {
	for (int i = 1; i < 27; i++) {
		Bag[i] = 0;
	}
}

//template <class ItemType>
LetterBag :: LetterBag(const  std::vector<char> &v) {
	for (int i = 1; i < 27; i++) {
		Bag[i] = 0;
	}
	int vSize = v.size();
	int cNum;
	for (int i = 0; i < vSize; i++) {
		if (isalpha(v[i])) {
			cNum = int(v[i]);
			Bag[cNum - 96]++;
		}
	}
}

bool LetterBag :: operator==(const LetterBag &other) const {
	for (int i = 1; i < 27; i++) {
		if (Bag[i] != other.Bag[i]) {
			return false;
		}
	}

	return true;
}

bool LetterBag :: operator!=(const LetterBag &other) const {
	if (!operator==(other)) {
		return true;
	}

	return false;
}

int LetterBag :: getCurrentSize() const {
	int size = 0;
	for (int i = 1; i < 27; i++) {
		size += Bag[i];
	}

	return size;
}

bool LetterBag :: isEmpty() const {
	LetterBag temp;
	if (operator==(temp)) {
		return true;
	}

	return false;
}

LetterBag & LetterBag :: add(char c) {
	int cNum = int(c);
	Bag[cNum - 96]++;
	return *this;
}

LetterBag & LetterBag :: remove(char c) {
	int cNum = int(c);
	Bag[cNum - 96]--;
	return *this;
}

LetterBag & LetterBag :: clear() {
	for (int i = 1; i < 27; i++) {
		Bag[i] = 0;
	}

	return *this;
}

int LetterBag :: getFrequency(char c) const {
	int cNum = int(c);
	return Bag[cNum - 96];
}

vector<char> LetterBag :: toVector() const {
	std::vector<char> temp;
	int nChar;
	for (int i = 1; i < 27; i++) {
		for (int n = 0; n < Bag[i]; n++) {
			nChar = i + 96;
			temp.push_back(char(nChar));
		}
	}

	return temp;
}