#include <iostream>
#include "LetterBag.h"
using namespace std;

int main() {
	LetterBag Bag1;
	// Testing the current size method and the add function
	cout << "Should output zero: " << Bag1.getCurrentSize() << endl;
	Bag1.add('a');
	cout << "Should output one: " << Bag1.getCurrentSize() << endl;
	Bag1.add('b');
	cout << "Should output two: " << Bag1.getCurrentSize() << endl;
	Bag1.add('c');
	cout << "Should output three: " << Bag1.getCurrentSize() << endl;

	// Testing toVector method;
	vector<char> vBag1 = Bag1.toVector();
	cout << "Should output a, b, and c." << endl;
	 for (int i = 0; i < 3; i++) {
		cout << vBag1[i] << endl;
	 }

	 // Testing constructor that takes in a vector as an argument
	 LetterBag Bag2(vBag1);
	 cout << "Should output three: " << Bag2.getCurrentSize() << endl;

	 // Testing the remove function
	 Bag1.remove('c');
	 cout << "Should output two: " << Bag1.getCurrentSize() << endl;

	 // Test Clear method
	 Bag1.clear();
	 cout << "Should output zero: " << Bag1.getCurrentSize() << endl;

	 // Test isEmpty method
	 cout << "Should say the bag is empty." << endl;
	 if (Bag1.isEmpty()) {
		cout << "The bag is empty." << endl;
	 } else {
		cout << "The bag is not empty." << endl;
	 }



}