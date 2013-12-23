#include "bst.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct BST {
	BST *parent;
	BST *left;
	BST *right;

	int (*comparator) (void *, void *);

	void *key;
	void *value;
};

BST *createBST(int (*comparator) (void *, void *)) {
	BST *bst = malloc(sizeof(BST));
	memset(bst, 0, sizeof(BST));

	bst -> comparator = comparator;
	bst -> parent = NULL;
	bst -> left = NULL;
	bst -> right = NULL;
	bst -> value = NULL;

	return bst;
}

BST *insertBST(BST *bst, void *key, void *value){
	if (bst -> key == NULL) {
		bst -> key = key;
		bst -> value = value;
		return bst;
	} else {

		int comparison = bst -> comparator(key, bst -> key);

		if (comparison < 0) {
			if (bst -> left == NULL) {
				BST *child = createBST(bst -> comparator);
				child -> value = value;
				child -> parent = bst;

				bst -> left = child;
			}

			insertBST(bst -> left, key, value);
		}

		if (comparison >= 0) {
			if (bst -> right == NULL) {
				BST *child = createBST(bst -> comparator);
				child -> value = value;
				child -> parent = bst;

				bst -> right = child;
			}

			insertBST(bst -> right, key, value);
		}

		return bst;
	}
}

BST *removeBST(BST *bst, void *key){
	BST *removing = searchBST(bst, key);

	if ((removing != NULL) && (hasChildren(removing) == false)) {
		printf("IS REMOVING!!!\n");
		BST *parent = removing -> parent;

		if (parent != NULL && isLeftChildBST(parent, removing)) {
			parent -> left = NULL;
		} else if (parent != NULL && isRightChildBST(parent, removing)) {
			parent -> right = NULL;
		}

		free(removing);
	}

	return bst;
}

BST *searchLNRBST(BST *bst, void *key){
	if (key) {

	}
	return bst;
}

bool
containsBST(BST *bst, void *key) {
	return searchBST(bst, key) != NULL;
}

BST *
searchBST(BST *bst, void *key) {
	int comparison = bst -> comparator(key, bst -> key);

	if (comparison == 0) return bst;
	if (comparison < 0 && bst -> left == NULL) return NULL;
	if (comparison > 0 && bst -> right == NULL) return NULL;

	if (comparison < 0) return searchBST(bst -> left, key);
	if (comparison > 0) return searchBST (bst -> right, key);

	return NULL;
}

int
sizeBST(BST *bst) {
	if (bst == NULL || bst -> key == NULL) return 0;
	return sizeBST(bst -> left) + sizeBST(bst -> right) + 1;
}

bool
isLeftChildBST(BST *parent, BST *child) {
	return parent -> left == child;
}

bool
isRightChildBST(BST *parent, BST *child) {
	return parent -> right == child;
}

bool
hasChildren(BST *bst) {
	if (bst -> left != NULL && bst -> left -> key != NULL) return true;
	if (bst -> right != NULL && bst -> right -> key != NULL) return true;
	return false;
}

void *
minimumBST(BST *bst) {
	if (bst -> left == NULL || bst -> left -> key == NULL) {
		return bst -> key;
	}

	return minimumBST(bst -> left);
}

void *
maximumBST(BST *bst) {
	if (bst -> right == NULL || bst -> right -> key == NULL) {
		return bst -> key;
	}

	return minimumBST(bst -> right);
}

void *
predecessorBST(BST *bst, void *key) {
	BST *child = searchBST(bst, key);
	if (child == NULL || child -> parent == NULL) return NULL;
	return child -> parent -> key;
}
