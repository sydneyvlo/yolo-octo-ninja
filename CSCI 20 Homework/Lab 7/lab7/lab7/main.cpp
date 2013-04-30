#include <iostream>
using namespace std;

struct node {
	int info;
	node *left;
	node *right;
};

int main() {
	node *treeRoot;
	node *child1;
	node *child11;
	node *child12;
	node *child2;
	node *child21;
	node *child22;

	//////////////// 25 ///////////////
	//      20               15
	//   18    15         10     9

	
	// Root
	treeRoot->info = 25;
	treeRoot->left = child1;
	treeRoot->right = child2;

	// Child 1
	child1->info = 20;
	child1->left = child11;
	child1->right = child12;

	// Child 2
	child2->info = 15;
	child2->left = child21;
	child2->right = child22;
	
	// Child 11 and child 12
	child11->info = 18;
	child12->info = 15;
	child11->left = NULL;
	child12->right = NULL;

	// Child 21 and child 22
	child21->info = 10;
	child22->info = 9;
	child21->left = NULL; // means they are leaves.
	child22->right = NULL;


	


}