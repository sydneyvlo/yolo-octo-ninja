#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

// Global Variables
const float RESTITUTION = 0.75;


int heightCalc(int sHeight, double gravity);
void simulator(int height);

int main() {
	
	double gravity;
	int sHeight;

	cout << "Enter a value for gravity: " << endl;
	cin >> gravity;
	cout << "Enter a value for starting height: " << endl;
	cin >> sHeight;

	while(cin>>) {
		simulator(sHeight);
	}
	
}

int heightCalc(int sHeight, double gravity) {
	double v1, v2;
	int h2;
	v1 = sqrt((2 * gravity * sHeight));
	v2 = RESTITUTION * v1;
	h2 = (pow(v2,2)/2)/gravity;

	return h2;
}