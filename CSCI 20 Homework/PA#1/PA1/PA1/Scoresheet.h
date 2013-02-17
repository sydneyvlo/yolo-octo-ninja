#ifndef SCORESHEET_H
#define SCORESHEET_H


#include "Frame.h"
using namespace std;

class Scoresheet {
public:

	// create a blank Scoresheet.
	Scoresheet(); 

	// copy constructor
	Scoresheet(const Scoresheet & other) ;


	// assignment
	Scoresheet & operator=(const Scoresheet & other) ;

	// return true iff scoresheet is complete (all frames are over).
	bool isComplete() const ;  

	// return true iff scoresheet is blank (all frames are new).
	bool isBlank() const ;  

	// if the Scoresheet is blank, return false. 
	// otherwise undo the last roll and return true. 
	bool undoLastRoll();  

	// return a copy of the desired frame.  
	// if frameNum < 1 return frame 1. if frameNum > MAXFRAMES return frame MAXFRAMES.
	Frame getFrame(int frameNum) const;



	//   return false if...
	//       frameNumber is less than 1 or greater than currentFrameNum,
	//       f is a lastFrame but frameNumber != MAXFRAMES 
	//       f is not a lastFrame but frameNumber == MAXFRAMES,
	//       f is not over but frameNumber < MAXFRAMES and frame frameNumber+1 isn't new.
	//   otherwise set frame frameNumber to f and return true.
	//   update currentFrameNum, if necessary.
	bool setFrame(const Frame & f, int frameNumber) ;


	//  if the scoresheet is complete or rollValue is illegal return false.
	//  otherwise set the next roll of the current frame to rollvalue and return true.
	//  update currentFrameNum, if necessary.
	bool setNextRoll(int rollValue) ; 

	 // fill an array of scores for each scorable frame.
	 // if a frame is not scorable yet then its score value will be -1.
	 // example: if
	 //     Frame::PINS is 10, 
	 //	    frame1 is [X, ]  (A strike; Frame over),
	 //     frame2 is [7,/]  (A spare; Frame over),
	 //     frame3 is [6,/]  (A spare; Frame over),
	 //     frame4 is [X, ]  (A strike; Frame over),
	 //     frame5 is [9, ]  (Frame not over yet),
	 //     subsequent frames are all new,
	 //     then scores will get the following values: {20, 36, 56, -1, -1, -1, -1, -1, -1, -1}
	void getScores(int scores[]) ;
	
	// print the scoresheet along with current scores.
	void print() ;
	// I am going to create a temporary array and pass it into getScores then just print the information in the array.

	// a unique id assigned to this scoresheet.
	const int ID;

	// total number of frames in any scoresheet.
	// This will normally be 10 but you may want to use a smaller value for testing purposes.
	static const int MAXFRAMES = 3;  

	// return the current frame number (1 to MAXFRAMES) or -1 if the scoresheet is complete.
	int getCurrentFrameNum() const; 

private:
	Frame frames[MAXFRAMES+1];  // ignore frames[0]

	// current frame number (1 to MAXFRAMES).
	// frames before the current frame are never new. 
	// frames after the current frame are always new.
	int currentFrameNum; 

	static int count;   // initially 0. used to assign unique ids to each scoresheet.

};



#endif

