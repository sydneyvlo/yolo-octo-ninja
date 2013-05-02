#ifndef IS_COMPLETE_H
#define IS_COMPLETE_H

struct node  {
    char info;
    node *left;
    node *right;
};

bool isComplete(node *p); //return true iff p is a complete tree

#endif;