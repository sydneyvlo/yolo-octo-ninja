#include "Frame.h"
 #include "Scoresheet.h"


//const int Scoresheet::MAXFRAMES;
/***
Scoresheet :: Scoresheet() : ID(count++) {
}

Scoresheet :: Scoresheet(const Scoresheet &other) : ID(count++) {
}

Scoresheet &operator
***/





void Scoresheet :: getScores(int scores[]) {
	for (int i = 1; i < (MAXFRAMES + 1); i++) {
		// We treat frames that are not the last frame differently.
		if (i != MAXFRAMES) {
			// Three possiblities for scoring if it is not the last frame.
			// Open Frame or Spare or Strike

			// If it is a spare I want to do 10 + whatever the next roll is.
			if (frames[i].isSpare()) {
				// In order to score a spare you need to know the value of the next roll and if the roll of the next frame is -1 that means the roll has yet to be determined.
				if (frames[i+1].getRoll1() != -1) {
					// The previous frame needs to have a score for any future frame to be scored.
					if (frames[i-1].getTotal() != -1) {
						// The current score is dependent on past scores and the rolls of the next frame.
						scores[i-1] = 10 + frames[i+1].getRoll1() + scores[i-2];
					} else {
						scores[i-1] = -1;
					}
				} else {
					scores[i-1] = -1;
				}
			} else if (frames[i].isStrike()) {
				if (frames[i+1].getRoll1() != -1) {
					// This below if statement is for scoring the first frame because you don't need to go back to previous frames to get the current score because it is first.
					if (i != 1) {
						if (frames[i+1].isStrike()) {
							scores[i-1] = frames[i].getPins() + frames[i].getPins() + frames[i+2].getRoll1() + scores[i-2];
						} else {
							scores[i-1] = frames[i].getPins() + frames[i+1].getRoll1() + frames[i+1].getRoll2() + scores[i-2];
						}
					} else {
						if (frames[i+1].isStrike()) {
							scores[i-1] = frames[i].getPins() + frames[i].getPins() + frames[i+2].getRoll1();
						} else {
							scores[i-1] = frames[i].getPins() + frames[i+1].getRoll1() + frames[i+1].getRoll2();
						}
					}
				} else {
					scores[i-1] = -1;
				}
			// This is for the openframe scenario
			} else {
				if (i != 1) {
					scores[i-1] = scores[i-2] + frames[i].getRoll1() + frames[i].getRoll2();
				} else {
					scores[i-1] = frames[i].getRoll1() + frames[i].getRoll2();
				}
			}
		}
	}
}

void Scoresheet :: print() {
	int *scores;
	scores = new int [MAXFRAMES+1];
	getScores(scores);
	
	for (int i = 1; i < (MAXFRAMES+1); i++) {
		if (i != MAXFRAMES) {
			cout << "[" << flush;
			if (frames[i].isOver()) {
				if (frames[i].bonusSpare()) {
					cout << frames[i].getRoll1() << ",/," << frames[i].getRoll3() << flush;
				} else if (frames[i].bonusStrikes()) {
					cout << "X,X, " << frames[i].getRoll3() << flush;
				} else {
					cout << frames[i].getRoll1() << "," << frames[i].getRoll2() << flush;
				}
			} 
		} else {
			cout << "[" << flush;
			if (frames[i].isOver()) {
				if (frames[i].isStrike()) {
					cout << setw(5) << "X,  " << flush;
//				cout << "\t" << flush;
				} else if (frames[i].isSpare()) {
					cout << setw(5) << frames[i].getRoll1() << ",/" << flush;
//				cout << "\t" << flush;
				} else {
					cout << setw(5) << frames[i].getRoll1() << "," << frames[i].getRoll2() << flush;
//				cout << "\t" << flush;
				}
			} else {
				if (frames[i].getRoll1() != -1) {
					cout << setw(5) << frames[i].getRoll1() << ", " << flush;
				} else {
					cout << " , " << flush;
				}
			}

		}
		
		cout << "]" << flush;
		cout << "\t" << flush;
	}

	cout << endl;

	for (int i = 0; i < (MAXFRAMES); i++) {
		if (scores[i] != -1) {
			cout << setw(7) << scores[i] << flush;
			cout << "\t" << flush;
		} else {
			cout << setw(7) << "_______" << flush;
			cout << "\t" << flush;
		}
	}

	delete scores;
}

/***
int Scoresheet::getCurrentFrameNum() const
{
	return (Scoresheet::currentFrameNum);
}

Scoresheet::Scoresheet() : ID(count++)
{
	for(int i = 1; i < MAXFRAMES; i++)
	{
		Scoresheet::frames[i] = Frame::Frame f;
	}
}

Scoresheet::Scoresheet(const Scoresheet & other)
{
	Scoresheet frames();
	for(int i = 1; i < MAXFRAMES; i++)
	{
		Scoresheet::frames[i] = other.frames[i];
	}
}

Scoresheet & Scoresheet::operator=(const Scoresheet & other)
{
	for(int i = 1; i < MAXFRAMES; i++)
	{
		this->frames[i].lastFrame = other.frames[i].lastFrame;
		this->frames[i].roll1 = other.frames[i].roll1;
		this->frames[i].roll2 = other.frames[i].roll2;
		this->frames[i].roll3 = other.frames[i].roll3;
	}
}

bool Scoresheet::isComplete() const
{
	bool complete = true;
	for(int i = 1; i < MAXFRAMES; i++)
	{
		if(!(this->frames[i].isOver()))
		{
			complete = false;
		}
	}
	return complete;
}

bool Scoresheet::isBlank() const
{
	bool blank = true;
	for (int i = 1; i < MAXFRAMES; i++)
	{
		if(!(this->frames[i].isNew()))
		{
			blank = false;
		}
	}
	return blank;
}

bool Scoresheet::undoLastRoll()
{
	if(this->isBlank())
	{
		return false;
	}
	this->frames[currentFrameNum].undo();
	return true;
}

Frame Scoresheet::getFrame(int frameNum) const
{
	int minFrame = 1;
	if(frameNum < numFrames)
	{
		return(this->frames[minFrames]);
	}
	else if(frameNum > MAXFRAMES)
	{
		return(this->frames[MAXFRAMES]);
	}
	else
	{
		return(this->frames[frameNum]);
	}
}

bool Scoresheet::setNextRoll (int rollValue) {
	if (isComplete () || rollValue < 0 || rollValue > 10) return false;
	else {
		frames[getCurrentFrameNum()] = rollValue;
		currentFrameNum++;
		return true;
	}
	
	//  if the scoresheet is complete or rollValue is illegal return false.
	//  otherwise set the next roll of the current frame to rollvalue and return true.
	//  update currentFrameNum, if necessary.
}

***/
