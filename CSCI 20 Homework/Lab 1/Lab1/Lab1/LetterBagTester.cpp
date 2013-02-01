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

	 // Test isEmpty method takes bag
	 cout << "Should say the bag is empty." << endl;
	 if (Bag1.isEmpty()) {
		cout << "The bag is empty." << endl;
	 } else {
		cout << "The bag is not empty." << endl;
	 }

	 // Test operator== method
	 cout << "Should output the bags are not the same." << endl;
	 if (Bag1 == Bag2) {
		cout << "The bags are the same." << endl;
	 } else {
		cout << "The bags are not the same." << endl;
	 }

	 Bag1.add('a');
	 Bag1.add('a');
	 Bag1.add('b');
	 Bag1.add('c');
	 Bag2.add('a');

	 cout << "Should output the bags are the same." << endl;
	 if (Bag1 == Bag2) {
		cout << "The bags are the same." << endl;
	 } else {
		cout << "Error has occurred" << endl;
	 }

	 // Test the method operator!=
	 LetterBag Bag3;
	 Bag3.add('a');
	 LetterBag Bag4;
	 Bag4.add('f');

	 cout << "Should output the bags are different." << endl;
	 if (Bag3 != Bag4) {
		cout << "The bags are different." << endl;
	 } else {
		cout << "Error has occurred." << endl;
	 }

	 Bag3.clear();
	 Bag4.clear();

	 cout << "Should say the bags are the same." << endl;
	 if (Bag3 != Bag4) {
		 cout << "The bags are not the same." << endl;
	 } else {
		cout << "The bags are the same." << endl;
	 }

	 // Testing a bag with a large amount of items
	 vector<char> temp2(10000, 'a');
	 LetterBag Bag5(temp2);
	 Bag5.add('b');
	 Bag5.add('c');
	 Bag5.add('d');
	 Bag5.add('e');
	 Bag5.add('f');
	 cout << "Should output 10000: " << Bag5.getFrequency('a') << endl;
	 cout << "Should output 10005: " << Bag5.getCurrentSize() << endl;
	 cout << "Should say that it is empty." << endl;
	 if (Bag5.clear().isEmpty()) {
		cout << "Bag is empty." << endl;
	 } else {
		cout << "Bag is not empty." << endl;
	 }

	 if ((Bag5.add('a').isEmpty() ) == false) {
		cout << "Success!" << endl;
	 }



}