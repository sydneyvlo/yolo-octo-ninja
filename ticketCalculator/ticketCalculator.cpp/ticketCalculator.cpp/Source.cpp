#include <iostream>
#include <string>
using namespace std;

int main() {
	double tPrice = 0.0, tRPrice = 0.0, rOi = 0.0;
	int tAmount = 0, choice;

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
}