#include <iostream>
#include "Frame.h"
using namespace std;

Frame :: Frame(bool lastFrm = false, int r1 = -1, int r2 = -1, int r3 = -1) {
	roll1 = r1;
	roll2 = r2;
	roll3 = r3;
	lastFrame = lastFrm;
	if (r1 < -1 || r1 > PINS) {
		roll1 = -1;
		roll2 = -1;
		roll3 = -1;
	} else if (roll1 == -1 || r2 < -1 || r2 > PINS) {
		roll2 = -1;
		roll3 = -1;
	} else if (roll1 == -1 || roll2 == -1 || r3 < -1 || r3 > PINS || lastFrm == false) {
		roll3 = -1;
	} else {
		lastFrame = lastFrm;
		roll1 = r1;
		roll2 = r2;
		roll3 = r3;
	}
}

bool Frame :: outOfRange(int rollNum, int max) {
	
}