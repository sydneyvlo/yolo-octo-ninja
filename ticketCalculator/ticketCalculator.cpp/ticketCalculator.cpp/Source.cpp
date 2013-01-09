#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void prompt(int &choice);
void calcRPrice(double &tPrice, double &tRPrice, double &ROI);
void calcTAmount(int &tAmount, double &tPrice, double &tRPrice, double &ROI, double &profit);
void calcROI(double &tPrice, double &tRPrice);

int main() {
	double tPrice = 0.0, tRPrice = 0.0, ROI = 0.0, profit;
	int tAmount = 0, choice;
	bool again = false;
	char repeat;
	
	// Lets turn the prompt up there into a function. So we can repeatedly call it in the do while loop.

	do {
		prompt(choice);
		if (choice == 1) {
			calcRPrice(tPrice, tRPrice, ROI);
		} else if (choice == 2) {
//			calcTAmount(); 
		} else {
//			calcROI();
		}

		cout << "Would you like to calculate anything else? (y/n)" << flush;
		cin >> repeat;
		if (repeat == 'y') {
			again = true;
		} else {
			again = false;
			cout << "See ya next time." << endl;
		}
	} while (again);
}

void prompt(int &choice) {
	cout << "Menu\n" 
	<< endl 
	<< "1. Calculate the resell price needed to \
		  \nmatch return on investment percentage. \n"
	<< endl		
	<< "2. Calculate the amount of tickets needed to \
		  \nmeet a desired profit at a certain return on \
		  \ninvestment based on the original ticket price and resell price.\n" 
	<< endl 
	<< "3. Calculate the return on investment based \
		  \noriginal ticket price and ticket resell price.\n" 
	<< endl << endl;

	cout << "Choose 1, 2, or 3: " << flush;
	cin >> choice;
}

void calcRPrice(double &tPrice, double &tRPrice, double &ROI) {
	cout << "Enter a return on investment percentage: " << flush;
	cin >> ROI;
	cout << "Enter the original ticket price: " << flush;
	cin >> tPrice;
	tRPrice = tPrice * (ROI/100) + tPrice;
	cout << "The resell price needed in order to match the ROI is: " << \
		setprecision(4) << "$" << tRPrice << endl;
}

void calcTAmount(int &tAmount, double &tPrice, double &tRPrice, double &ROI, double &profit) {

}