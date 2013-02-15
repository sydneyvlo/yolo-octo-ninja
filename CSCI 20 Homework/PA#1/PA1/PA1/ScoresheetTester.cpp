#include <iostream>
#include <string>
#include "Scoresheet.h"
#include "Utilities.h"

using namespace std;

int main() {
	cout << "Welcome to the Scoresheet Tester." << endl << endl;
	Frame::setPins(getInt( "Enter the number of pins in a rack (3 to 20)"));
	cout << "There are " << Frame::getPins() << " pins per rack" 
		<< " and " << Scoresheet::MAXFRAMES << " frames per scoresheet." << endl;

	const int numChoices = 6;
    string choices[numChoices] = {   
							"Set Next Roll",
							"Undo a Last Roll",
                            "Edit a Frame",
							"Empty Scoresheet",
							"Print Scoresheet",
							"Quit"
                        };

	int choice, frameNumber, roll1, roll2, roll3;
	Frame f;
	Scoresheet s;
    while ((choice = getChoice(choices, numChoices)) != numChoices) {

        switch(choice) {
			case 1:	if (!s.setNextRoll(getInt("Enter roll value or -1")))
						cout << "Illegal operation." << endl;	
					else cout << "Scoresheet updated." << endl; 
																break;
			case 2: 
					if (!s.undoLastRoll())
						cout << "Nothing to undo; Scoresheet is empty." << endl;	
					else cout << "Scoresheet was updated." << endl;
																break; 

            case 3: 
				frameNumber = getInt("Enter the frame number");
				roll1 = getInt("Roll1 value or -1");
				roll2 = getInt("Roll2 value or -1");
				roll3 = -1;
				if (frameNumber == Scoresheet::MAXFRAMES) roll3 = getInt("Roll3 value or -1");
				f = Frame(frameNumber == Scoresheet::MAXFRAMES, roll1, roll2, roll3);  
				if (!s.setFrame(f, frameNumber)) cout << "Illegal operation. " << endl;
				else cout << "Scoresheet updated." << endl;
																break;

            case 4:	s = Scoresheet();
																break;  

			case 5:  s.print();
																break;

          					
        }
		
    }
    cout << "Bye!" << endl;
	cin.get();  // you can take this out if you want
    return 0;
}


void printFrame(const Frame & f)  {
	cout << endl <<  "Current frame: " << f.toString(true) << endl;
}
