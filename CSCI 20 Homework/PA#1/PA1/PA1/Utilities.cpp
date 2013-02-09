#include "Utilities.h"


// display prompt and return user's input.
int getInt(string prompt) {
    int value;
    bool goodInput = false;
    cout << prompt << ": ";
    do {
        cin >> value;
        if (cin)
            goodInput = true;
        else {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(80,'\n');  // discard rest of line
        }
    } while (!goodInput);

	cin.ignore(80,'\n');  // discard rest of line
    return value;
}


int randomInt(int min, int max) {
	if (max < min) swap(min,max);
	return rand() % (max - min + 1) + min;
}

// user picks from a menu of choices. return pick as a number from 1 to numChnoices.
int getChoice(string choices[], int numChoices) {
    cout << endl << endl; 

    for (int i = 0; i < numChoices; i++) 
        cout	<< "\t" << char('a' + i) << ". " // choices are lettered
				<< choices[i] << endl;

    char choice, lastChoice = 'a' + numChoices - 1;

    do {
        cout << endl << "Enter your choice (a to " << lastChoice << ") : ";
        cin >> choice;
        cin.ignore(80,'\n');
    } while (choice < 'a' || choice > lastChoice);
	cout << endl;

    return choice - 'a' + 1;  // convert choice back to a number

}
