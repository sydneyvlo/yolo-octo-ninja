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
void goingDown(int sHeight, double gravity);
void goingUp(int sHeight, double gravity);
void simulator(int sHeight, double gravity);

int main() {
	
	double gravity;
	int sHeight;

	cout << "Enter a value for gravity: ";
	cin >> gravity;
	cout << "Enter a value for starting height: ";
	cin >> sHeight;
	system("cls");
	while(1) {
		//simulator(sHeight, gravity);
		goingDown(sHeight, gravity);
		goingUp(sHeight, gravity);
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

void goingDown(int sHeight, double gravity) {
	int nLine = sHeight;
	while (nLine != 1) {
		for (int i = 101; i > 0; i--) {
			if (i == nLine) {
				cout << "@@" << endl;
				Sleep(1);
			} else if (i == 1) {
				cout << "ZZZZZZZZZZ" << endl; // P.E.
				Sleep(1);
			} else {
				cout << endl;
				Sleep(1);
			}
		}
		system("cls");
		nLine--;
	}
}

void goingUp(int sHeight, double gravity) {
	int upToo = heightCalc(sHeight, gravity);
	int nLine = 2;
	while (nLine <= upToo) {
		for (int i = 101; i < 0; i--) {
			if (i == nLine) {
				cout << "@@" << endl;
				Sleep(1);
			} else if(i == 1) {
				cout << "ZZZZZZZZZZ" << endl;
				Sleep(1);
			} else {
				cout << endl;
				Sleep(1);
			}
		}

		system("cls");
		nLine++;
	}
}

void simulator(int sHeight, double gravity) {
	int nextHeight = sHeight;
	while (nextHeight > 0) {
		for (int i = 101; i > 0; i--) {
			if (i == 1) {
				cout << "ZZZZZZZZZZ" << endl; // Possible error, not sure if I really want the endl
				Sleep(100);
			} else if (i == nextHeight) {
				cout << "@@" << endl; // Same here
				Sleep(100);
			} else {
				cout << endl;
				Sleep(100);
			}
		}
		system("cls");
		nextHeight = heightCalc(nextHeight, gravity);
	}
}