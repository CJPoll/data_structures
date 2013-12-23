#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
// Don't forget to include your tested code up here!

#include <stdio.h>
#include <stdlib.h>
#include "../src/bst.h"

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

int
integer_compare(void *int1, void* int2) {
	int value1 = *(int*)int1;
	int value2 = *(int*)int2;

	if (value1 == value2) return 0;
	if (value1 < value2) return -1;
	return 1;
}

void
testIntegerCompare(void) {
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	// Equal 
	CU_ASSERT_EQUAL(integer_compare(&value2, &value2), 0);
	
	// Less than
	CU_ASSERT_EQUAL(integer_compare(&value1, &value2), -1);

	// Greater than
	CU_ASSERT_EQUAL(integer_compare(&value3, &value1), 1);
}

void
testCreateBST() {
	BST *bst = NULL;
	bst = createBST(&integer_compare);
	int size = sizeBST(bst);

	CU_ASSERT_PTR_NOT_NULL(bst);
	CU_ASSERT_EQUAL(size, 0);

	free(bst);
}

void
testInsertBST() {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	int size = sizeBST(bst);

	CU_ASSERT_EQUAL(size, 3);
	CU_ASSERT_TRUE(containsBST(bst, &value1));
	CU_ASSERT_TRUE(containsBST(bst, &value2));
	CU_ASSERT_TRUE(containsBST(bst, &value3));
	CU_ASSERT_FALSE(containsBST(bst, &value4));

	free(bst);
}

void
testChildren() {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	BST *tree1 = searchBST(bst, &value1);
	BST *tree2 = searchBST(bst, &value2);
	BST *tree3 = searchBST(bst, &value3);

	CU_ASSERT_PTR_EQUAL(tree2, bst);

	CU_ASSERT_TRUE(isLeftChildBST(bst, tree1));
	CU_ASSERT_TRUE(isRightChildBST(bst, tree3));

	CU_ASSERT_FALSE(hasChildren(tree1));
	CU_ASSERT_TRUE(hasChildren(tree2));
	CU_ASSERT_FALSE(hasChildren(tree3));
	free(bst);
}

void
testRemoveLeafBST() {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	removeBST(bst, &value3);

	int size = sizeBST(bst);

	CU_ASSERT_EQUAL(size, 2);
	CU_ASSERT_TRUE(containsBST(bst, &value1));
	CU_ASSERT_TRUE(containsBST(bst, &value2));
	CU_ASSERT_FALSE(containsBST(bst, &value3));
	CU_ASSERT_FALSE(containsBST(bst, &value4));

	free(bst);
}

void
testRemoveNotLeafBST() {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	CU_ASSERT_TRUE(hasChildren(bst));
	removeBST(bst, &value2);

	int size = sizeBST(bst);

	CU_ASSERT_EQUAL(size, 3);

	CU_ASSERT_TRUE(containsBST(bst, &value1));
	CU_ASSERT_TRUE(containsBST(bst, &value2));
	CU_ASSERT_TRUE(containsBST(bst, &value3));

	free(bst);
}

void
testMinimum(void) {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	void *minimum = minimumBST(bst);

	CU_ASSERT_PTR_EQUAL(minimum, &value1);
}

void
testMaximum(void) {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	void *maximum = maximumBST(bst);

	CU_ASSERT_PTR_EQUAL(maximum, &value3);
}

void
testPredecessor(void) {
	BST *bst = createBST(&integer_compare);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertBST(bst, &value2, &value2);
	insertBST(bst, &value1, &value1);
	insertBST(bst, &value3, &value3);

	void *pos1 = predecessorBST(bst, &value1);
	void *pos2 = predecessorBST(bst, &value2);
	void *pos3 = predecessorBST(bst, &value3);

	CU_ASSERT_PTR_EQUAL(pos1, &value2);
	CU_ASSERT_PTR_EQUAL(pos3, &value2);
	CU_ASSERT_PTR_EQUAL(pos2, NULL);
}

int
main() {
	/*
	 * Not very safe code - a lot could potentially fail. Need to add some error
	 * handling.
	 */
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("Suite Name", init_suite, clean_suite);
		CU_add_test(suite, "Testing Integer Comparison", testIntegerCompare);
		CU_add_test(suite, "Testing BST Creation", testCreateBST);
		CU_add_test(suite, "Testing BST Insertion", testInsertBST);
		CU_add_test(suite, "Testing BST Left Child", testChildren);
		CU_add_test(suite, "Testing BST RemoveLeaf", testRemoveLeafBST);
		CU_add_test(suite, "Testing BST RemoveNOTLeaf", testRemoveNotLeafBST);
		CU_add_test(suite, "Testing BST Minimum", testMinimum);
		CU_add_test(suite, "Testing BST Maximum", testMaximum);
		CU_add_test(suite, "Testing BST Predecessor", testPredecessor);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
