#include "Frame.h"
#include "Scoresheet.h"


const int Scoresheet::MAXFRAMES = 3;

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