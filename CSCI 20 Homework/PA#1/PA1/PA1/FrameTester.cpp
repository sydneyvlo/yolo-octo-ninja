// Frame Tester

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Frame.h"
using namespace std;






// print frame info with verbose == true.
void printFrame(const Frame & f) ;

int main() {
	cout << "Welcome to the Frame Tester." << endl << endl;
	Frame::setPins(getInt( "Enter the number of pins in a rack (3 to 20)"));
	cout << "There will be " << Frame::getPins() << " pins per rack." << endl;

	const int numChoices = 6;
    string choices[numChoices] = {   
							"Set Next Roll",
                            "Undo Last Roll", 
							"Display Maximum Allowed Roll", 
							"Create Nonfinal Frame", 
							"Create Final Frame", 
							"Quit"
                        };

    Frame f;  // defaults to nonfinal frame
	printFrame(f);
 
	int choice, temp, roll1, roll2, roll3;
    while ((choice = getChoice(choices, numChoices)) != numChoices) {

        switch(choice) {
         
            case 1:	if (!f.setNextRoll(getInt("Enter roll value or -1")))
						cout << "Illegal operation." << endl;	
																	break;  

			case 2: if (!f.undo()) 
						cout << "Nothing to undo for a new frame." << endl;
																	break;

            case 3: temp = f.nextRollMax();
					if (temp >= 0)
						cout << "Maximum allowed roll = " << temp;
					else cout << "Frame is over";
					cout << "." << endl;							
					break;
			 case 4: 
					roll1 = getInt("Roll1 value or -1");
					roll2 = getInt("Roll2 value or -1");  
					f = Frame(false, roll1, roll2);		// constructor should ignore illegal values					
																	break;

            case 5: 
					roll1 = getInt("Roll1 value or -1");
					roll2 = getInt("Roll2 value or -1");
					roll3 = getInt("Roll3 value or -1");
					f = Frame(true, roll1, roll2, roll3);  // constructor should ignore illegal values														
																	break;

		}
		printFrame(f);  // reprint the frame, whether or not it has been changed.
    }
    cout << "Bye!" << endl;
    return 0;
}




void printFrame(const Frame & f)  {
	cout << endl <<  "Current frame: " << f.toString(true) << endl;
}



