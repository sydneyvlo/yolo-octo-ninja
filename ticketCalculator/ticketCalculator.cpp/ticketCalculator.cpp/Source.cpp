#include <iostream>
#include <string>
using namespace std;

int calcRPrice(double &tPrice, double &tRPrice, double &ROI);
int calcTAmount(int &tAmount, double &tPrice, double &tRPrice, double &ROI);
double calcROI(double &tPrice, double &tRPrice);

int main() {
	double tPrice = 0.0, tRPrice = 0.0, ROI = 0.0;
	int tAmount = 0, choice;
	bool again = false;
	string repeat;

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
		<< endl;
	
	cout << "Choose 1, 2, or 3: " << flush;
	cin >> choice;

	do {
		if (choice == 1) {
			calcRPrice();
		} else if (choice == 2) {
			calcTAmount(); 
		} else {
			calcROI();
		}

		cout << "Would you like to calculate anything else? (y/n)" << endl;
		getline(cin, repeat);
		if (repeat == "y") {
			again == true;
		} else {
			again == false;
		}
	} while (again);
}