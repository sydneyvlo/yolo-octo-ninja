#include <iostream>
#include "Frame.h"
using namespace std;

int Frame :: PINS = 10;

Frame :: Frame(bool lastFrm, int r1, int r2, int r3) {
	roll1 = r1;
	roll2 = r2;
	roll3 = r3;
	lastFrame = lastFrm;
	if (cusOutOfRange(1, PINS)) {
		cout << "r1 is illegal" << endl;
		roll1 = -1;
		roll2 = -1;
		roll3 = -1;
		cout << "roll1: " << roll1 << endl;
		cout << "roll2: " << roll2 << endl;
		cout << "roll3: " << roll3 << endl;
	} else if ((roll1 == -1 && roll2 != -1) || cusOutOfRange(2, PINS)) {
//		cout << lastFrm << " " << r1 << " " << r2 << " " << r3 << endl;
		cout << "r2 is illegal" << endl;
		roll2 = -1;
		roll3 = -1;
		cout << "roll1: " << roll1 << endl;
		cout << "roll2: " << roll2 << endl;
		cout << "roll3: " << roll3 << endl;
	} else if (((roll1 == -1 || roll2 == -1) && roll3 != -1) || cusOutOfRange(3, PINS) || lastFrm == false) {
		cout << "r3 is illegal" << endl;
		roll3 = -1;
				cout << "roll1: " << roll1 << endl;
		cout << "roll2: " << roll2 << endl;
		cout << "roll3: " << roll3 << endl;
	} else {
		cout << "Successful values" << endl;
		cout << "roll1: " << roll1 << endl;
		cout << "roll2: " << roll2 << endl;
		cout << "roll3: " << roll3 << endl;
	}

}

int Frame :: rollCount() const {
	return 1;
}

bool Frame :: undo() {
	return false;
}

int Frame :: nextRollMax() const {
	return 1;
}

bool Frame :: setNextRoll(int rollValue) {
	return false;
}

string Frame :: toString(bool verbose) const {
	return "";
}

bool Frame :: isNew() const {
	return false;
}

bool Frame :: isOver() const {
	return false;
}

bool Frame :: isStrike() const {
	return false;
}

bool Frame :: isSpare() const {
	return false;
}

int Frame :: bonusStrikes() const {
	return 1;
}

bool Frame :: bonusSpare() const {
	return false;
}

int Frame :: getRoll1() const {
	return 1;
}

int Frame :: getRoll2() const {
	return 1;
}

int Frame :: getRoll3() const {
	return 1;
}

int Frame :: getTotal() const {
	return 1;
}

void Frame :: setPins(int PINS) {

}

int Frame :: getPins() {
	return 1;
}

bool Frame :: isLastFrame() const {
	return false;
}

string Frame :: rollToString(int roll) {
	return "";
}

bool Frame :: outOfRange(int rollNum, int max) {
	return "";
}

// Depending on the roll number I am going to check if the previous roll
// isn't -1 and if it isn't I am going to substract the x amount of
// previous rolls from the max.
bool Frame :: cusOutOfRange(int rollNum, int max) {
	if (rollNum == 1) {
		if (roll1 < -1 || roll1 > max) {
			return true;
		} else {
			return false;
		}
	} else if (rollNum == 2) {
		if (roll2 < -1 || roll2 > (max - roll1)) {
			return true;
		} else {
			return false;
		}
	} else if (rollNum == 3) {
		if (roll3 < -1 || roll3 > max) {
			return true;
		} else {
			return false;
		}
	}

	return true;
}