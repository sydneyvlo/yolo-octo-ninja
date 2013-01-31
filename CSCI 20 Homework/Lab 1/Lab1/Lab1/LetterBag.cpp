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