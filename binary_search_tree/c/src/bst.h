#ifndef BST_H
#define BST_H

typedef struct BST BST;

BST *createBST(int (*comparator) (void *, void *));
BST *insertBST(BST *bst, void *value);
BST *removeBST(BST *bst, void *value);
BST *searchNLRBST(BST *bst, void *value);

#endif
