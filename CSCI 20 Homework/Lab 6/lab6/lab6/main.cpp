#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <queue>
using namespace std;




struct node  {
    char info;
    node *left;
    node *right;
};

void inorderTraversal(node  * p);   // print node data in order
void preorderTraversal(node  * p);  // print node data pre order
void postorderTraversal(node * p);  // print node data post order
void levelorderTraversal(node * p); // level order
//int leafCount(node * p);  // return number of leaves in p
//int height(node * p);  // return height of p
//string longestPath(node * p);  // most number of edges between p and a leaf
//string shortestPath(node * p); // least number of edges between p and a leaf
//int nodeCount(node * p);    // return number of nodes in p

node * makeARandomTree(int maxHeight); // This one is written for you.

//void deleteTree(node * p);  // delete all dynamically allocated memory for this tree
//void drawTree(node * p, bool condense);  // draw the tree. Use condensed spacing if condense == true.
node *  addTrees(node * leftT, node * rightT, char c);   // create a new tree with root c.
//bool isFull(node * p) ; // return true iff p is a full tree
//bool isComplete(node * p) ;  // return true iff p is a complete tree



int main() {

    bool done = false;
    while (!done) {
        int maxHeight;
        cout << "maximum height? (or -2 to quit): ";
        cin >> maxHeight;
        if (maxHeight < -1) {
            done = true;
		} else {  
          node * p = makeARandomTree(maxHeight);
//         drawTree(p, maxHeight > 4);  // used condensed spacing if maxHeight > 5
 
          cout << endl;
//          cout << "\tHeight = " << height(p ) << ", Leafcount = "
//               << leafCount(p) <<  ", NodeCount = " << nodeCount(p) << endl;
 
          cout <<    endl << "\tPre Order:     <";
          preorderTraversal(p);
          cout << ">" << endl << endl << "\tIn Order:      <";
          inorderTraversal(p);
          cout << ">" << endl; // <<endl <<  "\tPost Order:    < ";
//          postorderTraversal(p);
//          cout << "> 
		  cout << endl << endl <<  "\tLevel Order:   <";
          levelorderTraversal(p);
          cout << ">" << endl << endl;
 
//          cout << "\tShortest Path: < " << shortestPath(p) << ">" << endl << endl;
//          cout << "\tLongest Path:  < " << longestPath(p)   << ">" << endl << endl;    
//          cout << "\tThis tree " << (isFull(p) ? "is" : "is not" ) << " full. " << endl << endl;
//          cout << "\tThis tree " << (isComplete(p) ? "is" : "is not" ) << " complete. " << endl << endl;        
 
//          deleteTree(p);
       }  
    }
    cout << "Bye!" << endl;
    cin.get(); cin.get();
    return 0;
}

node * makeARandomTree(int height) {

    if (height < 0) return NULL;

    node * p = rand() % 5 != 0 ? makeARandomTree(height-1) : NULL;
    node * q = rand() % 5 != 0 ? makeARandomTree(height-1) : NULL;
 
    return addTrees(p,q, char('A' + rand() % ('Z' - 'A' + 1)));
}

void preorderTraversal(node *p) {
	if (p != NULL) {
		cout << p->info << flush;
		preorderTraversal(p->left);
		preorderTraversal(p->right);
	}
}


void postorderTraversal(node *p) {
	if (p != NULL) {
		postorderTraversal(p->right);
		postorderTraversal(p->left);
		cout << p->info << flush;
	}
}

void inorderTraversal(node  * p) {
	if (p != NULL) {
		inorderTraversal(p->left);
		cout << p->info << flush;
		inorderTraversal(p->right);
	}
}

node *  addTrees(node * leftT, node * rightT, char c) {
	node *newTree;
	newTree = new node;
	newTree->info = c;
	newTree->left = leftT;
	newTree->right = rightT;
	return newTree;
}

void levelorderTraversal(node * p) {

}