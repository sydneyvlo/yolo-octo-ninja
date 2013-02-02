#include <iostream>
#include "Frame.h"
using namespace std;

int main() {
	cout << "test1" << endl;
	Frame test1;
	cout << endl;

	cout << "test2" << endl;
	Frame test2(false, 5, 4);
	cout << endl;

	cout << "test3" << endl;
	Frame test3(true, 1, 2, 3);
	cout << endl;

	cout << "test4" << endl;
	Frame test4(false, 1, 2, 3);
	cout << endl;

	cout << "test5" << endl;
	Frame test5(false, -1, 5);
	cout << endl;

	cout << "test6" << endl;
	Frame test6(true, 1, 11, 5);
	cout << endl;
}