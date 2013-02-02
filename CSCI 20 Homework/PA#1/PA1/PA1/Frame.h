#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Frame {

	// don't change this
	friend ostream & operator<< (ostream & out, const Frame & f) {
		return out << f.toString(); 
	}

public:

	// constructor.
	// initialize lastFrame, roll1, roll2 and roll3 to lastFrm, r1, r2 and r3 respectively.
	// if r1 is illegal set all rolls to -1
	// if r2 is illegal set roll2 and roll3 to -1.
	// if r3 is illegal set roll3 to -1.
	// illegal values are those which are... 
	//   meaningless (< -1 or > PINS),
	//   impossible  (e.g. a 9 for roll2 where PINS == 10 and roll1 is 5),
	//   out of sequence (e.g. a 3 for roll2 where roll1 is still -1),
	//   beyond the last allowed roll (e.g. a 5 for roll3 where lastFrame == false).
	// a value of -1 is legal and means "no roll"
	// examples, assuming PINS == 10...
	//    Frame(true,-1, 3,-1)  --> roll1 = roll2 = roll3 = -1.         (r2 is illegal.)
	//    Frame(true, 0,-1, 3)  --> roll1 = 0, roll2 = roll3 = -1.      (r3 is illegal.)
	//    Frame(true, 4, 6, 0)  --> roll1 = 4, roll2 = 6, roll3 = 0.    (all parameters are legal.)
	//    Frame(true, 4, 7, 0)  --> roll1 = 4, roll2 = -1, roll3 = -1.  (r2 is illegal.)
	//    Frame(true,11, 1, 3)  --> roll1 = roll2 = roll3 = -1.         (r1 is illegal.)
	//    Frame(false,4, 6, 0)  --> roll1 = 4, roll2 = 6, roll3 = -1.   (r3 is illegal.)
	//    Frame(false,-2, 1,-1) --> roll1 = -1, roll2 = -1, roll3 = -1. (r1 is illegal.)
	Frame(bool lastFrm = false, int r1 = -1, int r2 = -1, int r3 = -1 ) ;

	// return the number of rolls already completed during this frame.
	// examples, assuming PINS == 10...
	//   (-1,-1,-1) --> return 0.
	//   (2,-1, -1) --> return 1
	//   (5, 3,-1)  --> return 2.
	//   (4, 6, 3)  --> return 3.
	int rollCount() const;

	// Undo the last roll if there is one and return true. Otherwise return false.
	// More precisely, if rollCount() == k, then...
	//   if k == 0, return false,
	//   if k > 0,  set  rollK to -1 and return true.
	bool undo();
		
	// return the maximum possible value for the next roll in this frame or -1 if the frame is over.
	// examples, assuming PINS == 10...
	//	 roll1 = -1 --> return 10
	//   roll1 =  0,  roll2 == -1 --> return 10
	//   roll1 == 6,  roll2 == -1 --> return 4
	//   roll1 == 10, roll2 == -1, lastFrame == true  --> return 10
	//   roll1 == 10, roll2 == 7,  lastFrame == true  --> return  3
	//   roll1 == 6,  roll2 == 4,  lastFrame == true  --> return 10
	//   roll1 == 6,  roll2 == 3,  lastFrame == true  --> return -1
	//   roll1 == 6,  roll2 == 4,  lastFrame == false --> return -1
	int nextRollMax() const ;


	//  if the roll value is legal, set next roll to that value and return true. 
	//  if the roll value is not legal or the frame if over, return false.
	//  a roll value of -1 is legal but had no effect (since the next roll must already have value -1).

	//  examples..
	//    roll1 ==-1, roll2 == -1, PINS == 10, rollValue ==-1 --> leave frame unchanged and return true.
	//    roll1 ==-1, roll2 == -1, PINS == 10, rollValue == 4 --> set roll1 to 4 and return true.
	//    roll1 == 9, roll2 == -1, PINS == 10, rollValue == 0 --> set roll2 to 0 and return true.
	//    roll1 == 9, roll2 == -1, PINS == 10, rollValue == 2 --> leave frame unchanged and return false. (impossible roll value.)
	//    roll1 == 5, roll2 ==  4, PINS == 10 --> leave frame unchanged and return false  (frame is over.)
	bool setNextRoll(int rollValue) ;

	
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
	string toString(bool verbose = false) const;
	

	// return true iff all three roll values are -1.
	//( you only need to check roll1 since roll1 == 0 means roll2 and roll2 should also be zero.)
	bool isNew() const ;  


	// return true iff no more rolls are allowed for this Frame.
	// for example if lastFrame == false, and roll1 == PINS.
	bool isOver() const ;

	// return true iff roll1 == PINS  (a strike)
	bool isStrike() const ;

	// return true iff roll1 != PINS and roll1+roll2 == PINS (a spare)
	bool isSpare() const ;

	// if not last frame return 0.
	// if last frame, return number of strikes obtained for the bonus rolls (0, 1, or 2).
	int bonusStrikes() const;

	// if not last frame return false.
	// if last frame and a spare was obtained after a strike, return true.
	bool bonusSpare() const;

	// return roll1
	int getRoll1() const ;

	// return roll2
	int getRoll2() const ;

	// return roll3
	int getRoll3() const ;

	// return sum of roll1, roll2 and roll3, omitting values equal to -1.
	// example: if the roll values are [3,5,-1], getTotal will return 8.
	int getTotal() const ;


	// set Frame::PINS to a value between 3 and 20 inclusive.
	// if PINS < 3 then set Frame::PINS to 3.
	// if PINS > 20 then set Frame::PINS to 20
	static void setPins(int PINS = 10);  // default to PINS = 10.
	

	// return Frame::PINS
	static int getPins(); 

	// return Frame::lastFrame
	bool isLastFrame() const;

private:
	static int PINS;   // initialized to 10 in the implementation file ("Ten pin bowling"). 
	int		 roll1,	   // number of pins knocked down on first roll or -1 (no first roll yet).
			 roll2,    // number of pins knocked down on second roll or -1 (no second roll yet).
			 roll3;    // number of pins knocked down on third roll or -1 (no third roll yet).
	bool lastFrame;    // true iff this is a last frame
	static string rollToString(int roll);
	static bool outOfRange(int rollNum, int max);
	bool cusOutOfRange(int rollNum, int max);
};

#endif
