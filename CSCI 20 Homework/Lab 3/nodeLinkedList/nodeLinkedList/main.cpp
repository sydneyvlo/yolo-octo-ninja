#include <iostream>
#include <Windows.h>
using namespace std;

struct node {
	int info;
	node *link;
};

node* createNode(int val = 0) {
	node *temp;
	temp = new node;
	temp->info = val;
	return temp;
}

//first should not be null.
node* insertVal(node *first, int val) {
	int count = 0;
	bool inserted = false;

//	cout << "1" << endl;
	node *toBeAdded;
	toBeAdded = new node;
	toBeAdded->info = val;

//	cout << "2" << endl;
	//First node excluding the head. Aliases not creating new nodes.
	node *placeInList = first->link;

//	cout << "3" << endl;
	//Also first node exluding the head. Aliases not creating new nodes.
	node *prevInList = first->link;
	
//	cout << "4" << endl;

	// If this fails that means the linked list was empty. I just consisted of a headPtr;
	if (placeInList != NULL) {
		while (placeInList->link != NULL && !inserted) {
//		cout << "5x" << endl;
			if (val <= placeInList->info && count == 0) {
				first->link = toBeAdded;
				toBeAdded->link = placeInList;
				inserted = true;
			} else if (val <= placeInList->info) {
				cout << val << endl;
				cout << placeInList->info << endl;
				cout << "2 should be added here" << endl;
				prevInList->link = toBeAdded;
				toBeAdded->link = placeInList;
//				placeInList->link = toBeAdded;
				inserted = true;
			}
			prevInList = placeInList;
			placeInList = placeInList->link;
			count++;
		}

//		cout << "5" << endl;
		if (val <= placeInList->info && !inserted) {
			toBeAdded->link = prevInList->link;
			prevInList->link = toBeAdded;
		} else if (!inserted) {
			placeInList->link = toBeAdded;
			toBeAdded->link = NULL;
		}
	} else {
		first->link = toBeAdded;
		toBeAdded->link = NULL;
	}

	return first;

}

node* removeVal(node* first, int val, int &numRemoved) {
	int count = 0;
	node *prevInList = first->link;
	node *placeInList = first->link;
	node *toBeDeleted;
	while (placeInList->link != NULL) {
		if (placeInList->info == val && count == 0) {
			// Since the first node to be deleted
			// is the first node after the header, we make the headptr (first) point
			// to the second node after the head.
			first->link = placeInList->link;
			toBeDeleted = placeInList;
			placeInList = placeInList->link;
			delete toBeDeleted;
			numRemoved++;
		} else if (placeInList->info == val) {
			prevInList->link = placeInList->link;
			toBeDeleted = placeInList;
			placeInList = placeInList->link;
			delete toBeDeleted;
			numRemoved++;
		} else {
			count++;
			prevInList = placeInList;
			placeInList = placeInList->link;
		}
	}
	// This is dealing with the last node in the linked list. If the last node in the list is equal to the val,
	// just make the previous node link = NULL
	if (placeInList->info == val) {
		prevInList->link = NULL;
		delete placeInList;
		numRemoved++;
	}

	return first;
}

void print (node* first) {
//	cout << "Greetings from the print function." << endl;
	node* placeInList = first->link;
//	cout << "We make it here" << endl;
	if (placeInList != NULL) {
		cout << "[" << flush;
		while (placeInList->link != NULL) {
//			cout << "Greetings from the while loop in the print function." << endl;
			cout << "{" << placeInList->info << "}, " << flush;
			placeInList = placeInList->link;
		}

	cout << "{" << placeInList->info << "}" << flush;
	cout << "]" << endl;
	
	} else {
		cout << "[]" << endl;
	}
}

int main() {
	int numRemoved = 0;
	node* testNode;
	testNode = new node;
	testNode->link = NULL;

	cout << "Testing in: " << flush;
	for (int i = 1; i <=3; i++) {
		cout << i << " " << flush;
		Sleep(1000);
	}asdf

	cout << endl << "Goooooooooooooooo!" << endl;

	Sleep(2000);
	cout << endl;

	//Testing Print
	cout << "Should print out two empty braces." << endl;
	print(testNode);
	cout << endl;

	// Testing insertVal
	cout << "Inserting a 5." << endl;
	insertVal(testNode, 5);
	print(testNode);
	cout << endl;

	cout << "Inserting another 5." << endl;
	insertVal(testNode, 5);
	print(testNode);
	cout << endl;

	cout << "Inserting numbers 1 to 10." << endl;
	for (int i = 1; i <= 10; i++) {
		insertVal(testNode, i);
//		print(testNode);
	}
	
	print(testNode);

	cout << "Removing all instances of 5." << endl;
	removeVal(testNode, 5, numRemoved);
	print(testNode);
	cout << "numRemoved should equal 3: " << numRemoved << endl;
}