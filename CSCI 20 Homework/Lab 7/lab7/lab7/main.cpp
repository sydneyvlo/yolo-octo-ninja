#include <iostream>
using namespace std;

struct node {
	int info;
	node *left;
	node *right;
};

node *find (int n, node *root);

int main() {
	node *treeRoot = new node;
	node *child1 = new node;
	node *child11 = new node;
	node *child12 = new node;
	node *child2 = new node;
	node *child21 = new node;
	node *child22 = new node;
	node *temp;

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

	cout << "n = 20" << endl;
	temp = find(20, treeRoot);
	cout << "The node should contain the value 20: " << temp->info << endl << endl;

	//Bug. It returns 25
//	cout << "n = 30" << endl;
//	temp = find(30, treeRoot);
//	cout << "The node should contain the value NULL: " << temp->info << endl << endl;

	cout << "n = 18" << endl;
	temp = find(18, treeRoot);
	cout << "The node should contain the value 18: " << temp->info << endl << endl;

	cout << "n = 9" << endl;
	temp = find(9, treeRoot);
	cout << "The node should contain the value 9: " << temp->info << endl << endl;

}

node *find (int n, node *root) {
	if (n == root->info) {
		return root;
	}

	if (root == NULL) {
		return root;
	}

	if (n == root->left->info) {
		return root->left;
	} else if (n == root->right->info) {
		return root->right;
	} else if (n < root->right->info && root->left->info) {
		if (find(n, root->left) == NULL) {
			return find(n, root->right);
		} else {
			return find(n, root->left);
		}
	} else if (n < root->right->info) {
		return find(n, root->right);
	} else {
		return find(n, root->left);
	}

/***
	if (n < root->left->info && n < root->right->info) {
//		node *temp = find(n, root->left);
		if (find(n, root->left) == NULL) {
			return find(n, root->right);
		} else {
			return root->left;
		}
	} else {
		if (n <= root->left->info) {
			return find(n, root->left);
		} else if (n <= root->right->info) {
			return find(n, root->right);
		}
	}
***/
}

