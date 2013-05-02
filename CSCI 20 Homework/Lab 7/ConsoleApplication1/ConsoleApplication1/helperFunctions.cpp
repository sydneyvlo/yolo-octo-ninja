#include <iostream>
#include "helperFunctions.h"
using namespace std;

int height(node *p) {
// since the root start with the height of 0 if it is not NULL
	if(p == NULL) return -1;
	int hLeft = height(p->left);
	int hRight = height(p->right);

	if(hLeft > hRight) return hLeft + 1;
	else return hRight + 1;
}

bool isLeaf(node *tree) {
	if (tree->left == NULL && tree->right == NULL) {
		return true;
	} else {
		return false;
	}
}

bool isFullTree(node *tree) {
	if (tree->left != NULL && tree->right != NULL) {
		return true;
	} else {
		return false;
	}
}