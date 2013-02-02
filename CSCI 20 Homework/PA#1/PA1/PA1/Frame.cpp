#include <iostream>
#include "Frame.h"
using namespace std;

Frame :: Frame(bool lastFrm = false, int r1 = -1, int r2 = -1, int r3 = -1) {
	roll1 = r1;
	roll2 = r2;
	roll3 = r3;
	lastFrame = lastFrm;
	if (cusOutOfRange(1, PINS)) {
		roll1 = -1;
		roll2 = -1;
		roll3 = -1;
	} else if (roll1 == -1 || cusOutOfRange(2, PINS)) {
		roll2 = -1;
		roll3 = -1;
	} else if (roll1 == -1 || roll2 == -1 || cusOutOfRange(3, PINS) || lastFrm == false) {
		roll3 = -1;
	}

}

// Depending on the roll number I am going to check if the previous roll
// isn't -1 and if it isn't I am going to substract the x amount of
// previous rolls from the max.
bool Frame :: cusOutOfRange(int rollNum, int max) {
	if (rollNum == 1) {
		if (roll1 <= -1 || roll1 > max) {
			return true;
		} else {
			return false;
		}
	} else if (rollNum == 2) {
		if (roll2 <= -1 || roll2 > (max - roll1)) {
			return true;
		} else {
			return false;
		}
	} else if (rollNum == 3) {
		if (roll3 <= -1 || roll3 > max) {
			return true;
		} else {
			return false;
		}
	}
}