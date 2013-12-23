#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct BST BST;

BST *createBST(int (*comparator) (void *, void *));
BST *insertBST(BST *bst, void *key, void *value);
BST *removeBST(BST *bst, void *key);
BST *searchBST(BST *bst, void *key);

bool containsBST(BST *bst, void *key);
int sizeBST(BST *bst);

void *minimumBST(BST *bst);
void *maximumBST(BST *bst);
void *predecessorBST(BST *bst, void *key);
void *successorBST(BST *bst);

bool isLeftChildBST(BST *parent, BST *child);
bool isRightChildBST(BST *parent, BST *child);
bool hasChildren(BST *bst);

#endif
