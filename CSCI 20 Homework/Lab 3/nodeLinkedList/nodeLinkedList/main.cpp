#include <iostream>
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

	cout << "1" << endl;
	node *toBeAdded;
	toBeAdded = new node;
	toBeAdded->info = val;

	cout << "2" << endl;
	//First node excluding the head. Aliases not creating new nodes.
	node *placeInList = first->link;

	cout << "3" << endl;
	//Also first node exluding the head. Aliases not creating new nodes.
	node *prevInList = first->link;
	
	cout << "4" << endl;

	// If this fails that means the linked list was empty. I just consisted of a headPtr;
	if (placeInList != NULL) {
		while (placeInList->link != NULL && !inserted) {
		cout << "5x" << endl;
			if (val <= placeInList->info && count == 0) {
				first->link = toBeAdded;
				toBeAdded->link = placeInList;
				inserted = true;
			} else if (val <= placeInList->info) {
				toBeAdded->link = placeInList->link;
				placeInList->link = toBeAdded;
				inserted = true;
			}
			prevInList = placeInList;
			placeInList = placeInList->link;
			count++;
		}

		cout << "5" << endl;
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
	}

	return first;
}

void print (node* first) {
	cout << "Greetings from the print function." << endl;
	node* placeInList = first->link;
	cout << "We make it here" << endl;
	while (placeInList->link != NULL) {
		cout << "Greetings from the while loop in the print function." << endl;
		cout << "{" << placeInList->info << "}, " << flush;
		placeInList = placeInList->link;
	}

	cout << "{" << placeInList->info << "}" << endl;
}

int main() {
	node* testNode;
	testNode = new node;
	testNode->link = NULL;

	insertVal(testNode, 5);
	cout << "Before the print function call." << endl;
	print(testNode);
}