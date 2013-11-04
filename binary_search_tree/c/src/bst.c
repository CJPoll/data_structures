#include "bst.h"
#include <stdlib.h>

struct BST {
	BST *parent;
	BST *left;
	BST *right;

	int (*comparator) (void *, void *);

	void *value;
};

BST *createBST(int (*comparator) (void *, void *)) {
	BST *bst = malloc(sizeof(BST));

	bst -> comparator = comparator;
	bst -> parent = NULL;
	bst -> left = NULL;
	bst -> right = NULL;
	bst -> value = NULL;

	return bst;
}

BST *insertBST(BST *bst, void *value){
	if (bst -> value == NULL) {
		bst -> value = value;
		return bst;
	} 

	int comparison = bst -> comparator(bst -> value, value);

	if (comparison < 0) {
		if (bst -> left == NULL) {
			BST *child = createBST(bst -> comparator);
			child -> value = value;
			child -> parent = bst;
		}
		else {
			
		}
	}
	return bst;
}

BST *removeBST(BST *bst, void *value){
	void *i = value;
	i++;
	return bst;
}

BST *searchNLRBST(BST *bst, void *value){
	return bst;
}
