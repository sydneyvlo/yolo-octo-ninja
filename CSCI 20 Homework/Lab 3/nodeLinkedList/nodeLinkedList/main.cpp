#include <iostream>
using namespace std;

struct node {
	int info ;
	node *link;
};

node* createNode(int val = 0) {
	node temp;
	temp.info = val;
	temp.link = NULL;
	return &temp;
}

node* insertVal(node *first, int val) {
	node temp;
	temp.info = val;
	temp.link = first->link;
	first->link = &temp;
	return first;
}

node* removeVal(node* first, int val, int &numRemoved) {
	numRemoved = 0;
	node *prevInList = first;
	node *placeInList = first;
	node *toBeDeleted;
	while (placeInList->link != NULL) {
		if (placeInList->info == val) {
			//prevInList = placeInList->link;
			toBeDeleted = placeInList;
			if (first == placeInList) {
				first = placeInList->link;
			}
			placeInList = placeInList->link;
			delete toBeDeleted;
		} else {
			prevInList = placeInList;
			placeInList = placeInList->link;
		}
	}
	// This is dealing with the last node in the linked list. If the last node in the list is equal to the val,
	// just make the previous node link = NULL
	if (placeInList->info == val) {
		prevInList->link = NULL;
	}
}
















int main() {

}