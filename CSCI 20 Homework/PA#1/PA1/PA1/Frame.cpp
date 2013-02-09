#include <iostream>
#include <cstdlib>
#include "Frame.h"
#include <string>
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

//Derricks Shit
int Frame::nextRollMax() const {
	int notStrike = PINS - 1;
	if (isOver())
		return false;
	if (!(isLastFrame())) {									// not lastframe
		if (roll1 == -1) 									// -1 (return 10)
			return PINS;
		else if (roll1 >= 0 && roll1 <= notStrike)			// k (return pins - r1)
			return PINS - roll1;
		else												// strike == over
			return -1;
	}
	else {															// last frame
		if (roll1 == -1 && roll2 == -1)								// -1 , -1
			return PINS;
		else if ((roll1 >= 0 && roll1 <= notStrike) && roll2 == -1)	// k , -1
			return PINS - roll1;
		else if ((roll1 + roll2) == PINS)							// k , spare
			return PINS;
		else if (roll1 == PINS && roll2 == -1)						// strike, -1
			return PINS;
		else if (roll1 == PINS && (roll2 >= 0 && roll2 <= notStrike)) 	// strike, k
			return PINS - roll2;
		else if (roll1 == PINS && roll2 == PINS)					// strike, strike
			return PINS;
		else 
			return -1;
	}
}

bool Frame::setNextRoll(int rollValue) {
	int notStrike = PINS - 1;
	if (rollValue < -1 || rollValue > PINS)				// check if roll value is valid
		return false;
	if(isOver()) 
		return false;
	if(!(isLastFrame())) {								// not last frame
		if(rollValue == -1) {							// no efect
			return true;
		}
		else if ((roll1 == -1 && roll2 == -1)) { 				// -1, -1
			this->roll1 = rollValue;
			return true;
		}
		else if((roll1 >= 0 && roll1 <= notStrike) && roll2 == -1) {		// k, -1
			if ((roll1 + rollValue) > PINS)								// can't go over max			
				return false;
			else {
				this->roll2 = rollValue; 
				return true;
			}
		}
		else {
			return false;							//Strike, -1 (no change)
		}			
	}
	else	{													// last frame
		if(rollValue == -1)
			return true;
		else if (roll1 == -1 && roll2 == -1 && roll3 == -1) {			// -1, -1, -1
			this->roll1 = rollValue;
			return true;
		}
		else if((roll1 >= 0 && roll1 <= notStrike) && roll2 == -1 && roll3 == -1) { // k , -1 , -1 
			if ((roll1 + rollValue) > PINS)
				return false;		
			else { 
				roll2 = rollValue;
				return true;
			}
		}
		else if((roll1 + roll2) == PINS) {										// k, spare, -1
			roll3 = rollValue;
			return true;
		}
		else if (roll1 == PINS && roll2 == -1 && roll3 == -1) { 				// strike, -1 , -1
			roll2 = rollValue;
			return true;
		}
		else if ( roll1 == PINS && (roll2 >= 0 && roll2 == notStrike) && roll3 == -1) {		// strike, k, -1
			if ((roll2 + rollValue) > PINS)									// can't go over max
				return false;
			else {
				roll3 = rollValue;
				return true;
			}
		}
		else if (roll1 == PINS && roll2 == PINS && roll3 == -1) 		// strike, strike, -1
			roll3 = rollValue;
		else 
			return false;
	}
}

//Daniel's Shit
bool Frame::isLastFrame() const
{
	return(Frame::lastFrame);
}

int Frame::getPins()
{
	return(Frame::PINS);
}

void Frame::setPins(int pins)
{
	int minPins = 3;
	int maxPins = 20;
	if(pins < minPins)
	{
		Frame::PINS = 3;
	}
	if(pins > maxPins)
	{
		Frame::PINS = 20;
	}
	return;
}

string Frame::rollToString(int roll)
{
	char n[2];
	itoa(roll, n, 10);
	string num = string(n);
	return roll >= 0 ? num: " ";
}

int Frame::getTotal() const
{
	int sum = 0;
	int neg = -1;
	if(Frame::roll1 != neg)
	{
		sum+= Frame::roll1;
	}
	if(Frame::roll2 != neg)
	{
		sum+= Frame::roll2;
	}
	if(Frame::roll3 != neg)
	{
		sum+= Frame::roll3;
	}
	return sum;
}

int Frame::getRoll1() const
{
	return(Frame::roll1);
}

int Frame::getRoll2() const
{
	return(Frame::roll2);
}

int Frame::getRoll3() const
{
	return(Frame::roll3);
}

bool Frame::isSpare() const
{
	if(Frame::roll1 != Frame::PINS && 
		(Frame::roll1 + Frame::roll2) == Frame::PINS)
	{
		return true;
	}
	return false;
}

bool Frame::isStrike() const
{
	if(Frame::roll1 == Frame::PINS)
	{
		return true;
	}
	return false;
}

bool Frame::isNew() const
{
	int neg = -1;
	if(Frame::roll1 == neg && Frame::roll2 == neg &&
		Frame::roll1 == neg)
	{
		return true;
	}
	return false;
}

int Frame::bonusStrikes() const
{
	int strike = 10;
	int count = 0;
	if(Frame::lastFrame != true)
	{
		return 0;
	}
	else
	{
		if(Frame::roll1 == strike)
		{
			count++;
		}
		if(Frame::roll2 == strike)
		{
			count++;
		}
		if(Frame::roll3 == strike)
		{
			count++;
		}
	}
	return count;
}

bool Frame::bonusSpare() const
{
	if(Frame::lastFrame != true && (Frame::isStrike() && Frame::roll2 != Frame::PINS &&
		(Frame::roll2 + Frame::roll3) == Frame::PINS))
	{
		return true;
	}
	return false;
}

bool Frame::isOver() const
{
	int neg = -1;
	if((Frame::lastFrame == true) && ((Frame::isStrike() &&
		(Frame::roll2 != neg) && (Frame::roll3 != neg)) ||
		(((Frame::roll1 + Frame::roll2) == Frame::PINS) && (Frame::roll3 != neg)) ||
		((Frame::roll1 != neg) && (Frame::roll2 != neg) && (Frame::roll3 != neg))))
	{
		return true;
	}
	else if((Frame::lastFrame == false) && ((Frame::isStrike()) &&
			(Frame::roll2 == neg) && (Frame::roll3 == neg) ||
			(Frame::isSpare() && Frame::roll3 == neg) ||
			((Frame::roll1 != neg) && (Frame::roll2 != neg) &&
			(Frame::roll3 != neg))))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Larry's shit
int Frame::rollCount () const {
	int count = 0;
	if (roll1 >= 0) count++;
	if (roll2 >= 0) count++;
	if (roll3 >= 0) count++;
	return count;
	
	// return the number of rolls already completed during this frame.
	// examples, assuming PINS == 10...
	//   (-1,-1,-1) --> return 0.
	//   (2,-1, -1) --> return 1
	//   (5, 3,-1)  --> return 2.
	//   (4, 6, 3)  --> return 3.
}

bool Frame::undo () {
	int count = rollCount ();
	if (count == 0) return false;
	else {
		if (count == 3) roll3 = -1;
		if (count == 2) roll2 = -1;
		if (count == 1) roll1 = -1;
		return true;
	}
	
	// Undo the last roll if there is one and return true. Otherwise return false.
	// More precisely, if rollCount() == k, then...
	//   if k == 0, return false,
	//   if k > 0,  set  rollK to -1 and return true.
}

string Frame::toString (bool verbose) const {
	string s;

	if (!lastFrame) s = "[" + rollToString(roll1) + "," + rollToString(roll2) + "]";
	else s = "[" + rollToString(roll1) + "," + rollToString(roll2) + "," + rollToString(roll3) + "]";

	if(verbose){
		s += "  (";
		
		//new frame
		if (roll1 < 0) s += "New frame";
		
		//strike
		if (!lastFrame && roll1 == PINS) s += "A strike; ";
		if (lastFrame && roll1 == PINS) s += "A strike";
		
		//spare
		if (!lastFrame && ((roll1 + roll2) == PINS)) s += "A spare; "; 
		if (lastFrame && ((roll1 + roll2) == PINS)) s += "A spare";
		
		//open
		if (!lastFrame && roll1 >= 0 && roll1 < PINS && roll2 >= 0 && roll2 < PINS) s += "An open; ";
		if (lastFrame && roll1 >= 0 && roll1 < PINS && roll2 >= 0 && roll2 < PINS && roll3 >= 10 && roll3 < PINS) s += "An open; ";
		
		//bonus strikes and spares
		if (lastFrame && roll1 == PINS && roll2 == PINS && roll3 != PINS) s += " plus one bonus strike; ";
		if (lastFrame && ((roll1 + roll2) == PINS) && roll3 == PINS) s += " plus one bonus strike; ";
		if (lastFrame && roll1 == PINS && roll2 == PINS && roll3 == PINS) s += " plus two bonus strikes; ";
	    if (lastFrame && roll1 == PINS && ((roll2 + roll3) == PINS)) s += " plus one bonus spare; ";
		
		//frame not over
		if (!lastFrame && roll1 >= 0 && roll1 != PINS && roll2 < 0) s += "Frame not over yet";
		if (lastFrame && roll1 >= 0 && roll2 < 0) s += "Frame not over yet";
		if (lastFrame && roll1 >= 0 && roll2 >= 0 && roll3 < 0) s += "Frame not over yet";
		
		//frame over 
		if (!lastFrame && roll1 == PINS)
		if (!lastFrame && roll1 >= 0 && roll2 >= 0) s += "Frame over";
		if (lastFrame && roll1 >= 0 && roll2 >= 0 && roll3 >= 0) s += "Frame over";
		
		
		s += ")";
	}
	
	return s;
	//  return a string representing contents of this frame.
	//  if lastFrame is false, use format [A, B].
	//  if lastFrame is true use format [A, B, C].
	//  A, B and C may be numbers (1 to PINS) or symbols: "X" (strike), "-" (0), "/" (spare), " " (-1).
	//  note that roll1 == 0 and roll2 == PINS is a spare, not a strike.
	//  for the lastFrame, a bonus strike or spare is possible, e.g. [X,3,/], [4,/,X], [X,X,4] and [X,X,X].
	//  if verbose is true, append a description of the frame, including one or more of the phrases below.
	//     "A strike, "A spare", "An open", "plus one bonus strike", "plus two bonus strikes", 
	//     "plus one bonus spare", "Frame over", "New frame" and "Frame not over yet"
	//  run the sample program to see what the formatting should look like.
}