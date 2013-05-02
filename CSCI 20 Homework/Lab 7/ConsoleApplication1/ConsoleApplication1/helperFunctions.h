#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

struct node  {
    char info;
    node *left;
    node *right;
};

int height(node *tree);
bool isLeaf(node *tree);

#endif;