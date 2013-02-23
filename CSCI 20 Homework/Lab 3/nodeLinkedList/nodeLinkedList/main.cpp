#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

struct node {
	int info;
	node *link;
};

node* createNode(int val = 0) {
	node *temp;
	temp = new node;
	temp->info = val;
	temp->link = NULL;
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
//				cout << val << endl;
//				cout << placeInList->info << endl;
//				cout << "2 should be added here" << endl;
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

node* findVal(int val, node* first) {
	node* prevInList = first->link;
	node* placeInList = first->link;

	while(val > placeInList->info && placeInList->link != NULL) {
		prevInList = placeInList;
		placeInList = placeInList->link;
	}

	if (placeInList->link == NULL) {
		if (val > placeInList->info) {
			return placeInList;
		}
	} else {
		return prevInList;
	}

}

node* insertSortedArray(node* first, int nums[], int length) {
	for (int i = 0; i < length; i++) {
		insertVal(first, nums[i]);
	}

	return first;
}

node* clear(node* first) {
	node* placeInList = first->link;
	node* toBeDeleted;
	first->link = NULL;
	if (placeInList != NULL) {
		while (placeInList->link != NULL) {
			toBeDeleted = placeInList;
			placeInList = placeInList->link;
			delete toBeDeleted;
		}
		
		delete placeInList;
	}
	
	return first;
}

void reversePrint(node* first) {
	vector<int> temp;
	node* placeInList = first->link;
	
	if (placeInList != NULL) {
		while(placeInList->link != NULL) {
			temp.push_back(placeInList->info);
			placeInList = placeInList->link;
		}

		temp.push_back(placeInList->info);
		cout << "[" << flush;
		for (int i = temp.size() - 1; i >= 0; i--) {
			if (i == 0) {
				cout << "{" << temp[i] << "}";
			} else {
				cout << "{" << temp[i] << "}," << flush;
			}
		}

		cout << "]" << endl;
	} else {
		cout << "[]" << endl;
	}

}

node* copyList(node* first) {
	node*temp = createNode();
	node* placeInList = first->link;

	if (placeInList != NULL) {
		while(placeInList->link != NULL) {
			insertVal(temp, placeInList->info);
			placeInList = placeInList->link;
		}

		insertVal(temp, placeInList->info);
	}

	return temp;
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
	}

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

	cout << "Removing the last node 10." << endl;
	removeVal(testNode, 10, numRemoved);
	print(testNode);
	cout << "numRemoved should equal 4: " << numRemoved << endl;

	node* testNode2;
	testNode2 = new node;
	testNode2->link = NULL;
	node *temp;
	insertVal(testNode2, 1);
	insertVal(testNode2, 3);
	insertVal(testNode2, 4);
	temp = findVal(2, testNode2);
	cout << "Should return a node with info 1." << endl;
	cout << "Node's info is: " << temp->info << endl;

	temp = findVal(5, testNode2);
	cout << "Should return a node with info 4." << endl;
	cout << "Node's info is: " << temp->info << endl;

	insertVal(testNode2, 2);
	temp = findVal(2, testNode2);
	cout << "Should return a node with info 1." << endl;
	cout << "Node's info is: " << temp->info << endl << endl;

	node* testNode3;
	testNode3 = new node;
	testNode3->link = NULL;
	cout << "Printing an empty node." << endl;
	print(testNode3);

	int anArray[] = {1, 3, 5};

	cout << "Inserting an array of values 1-6. odds." << endl;
	insertSortedArray(testNode3, anArray, 3);
	print(testNode3);

	int anArray2[] = {2, 4, 6};
	cout << "Inserting an array of values 1-6 evens." << endl;
	insertSortedArray(testNode3, anArray2, 3);
	print(testNode3);

	cout << "Copying the above list." << endl;
	node* testNode4 = copyList(testNode3);
	print(testNode4);

	cout << "Print the above node in reverse order." << endl;
	reversePrint(testNode3);

	cout << "Deleteing the above linked-list and going to print it." << endl;
	clear(testNode3);
	print(testNode3);


}