#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
#include "../src/max_heap.h"

#include <stdio.h>
#include <stdlib.h>

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void
test_create_heap() {
	Heap *heap = heapCreate();
	
	CU_ASSERT_PTR_NOT_NULL(heap);
	CU_ASSERT_PTR_NOT_NULL(heap -> array);
	CU_ASSERT_EQUAL(heap -> size, 0);
}

void
test_get_left_child() {
	int left = getLeftChild(4);

	CU_ASSERT_EQUAL(left, 8);
}

void
test_get_right_child() {
	int left = getRightChild(4);

	CU_ASSERT_EQUAL(left, 9);
}

void
test_get_parent_even() {
	int child = 8;
	int parent_expect = 4;

	int parent = getParent(child);

	CU_ASSERT_EQUAL(parent_expect, parent);
}

void
test_get_parent_odd() {
	int child = 9;
	int parent_expect = 4;

	int parent = getParent(child);

	CU_ASSERT_EQUAL(parent_expect, parent);
}

void
test_insert_empty_heap() {
	Heap *heap = heapCreate();

	int value1 = 1;

	heap = heapInsert(heap, &value1);

	CU_ASSERT_PTR_NOT_NULL(heap -> array -> array[0]);
	CU_ASSERT_EQUAL(*(int*)heap -> array -> array[0], 1);
	CU_ASSERT_EQUAL(heap -> size, 1);
}

void
test_insert_filled_heap() {
	Heap *heap = heapCreate();

	int value1 = 1;
	int value2 = 2;

	heap = heapInsert(heap, &value1);
	heap = heapInsert(heap, &value2);

	CU_ASSERT_PTR_NOT_NULL(heap -> array -> array[0]);
	CU_ASSERT_PTR_NOT_NULL(heap -> array -> array[1]);
	CU_ASSERT_EQUAL(*(int*)heap -> array -> array[0], 2);
	CU_ASSERT_EQUAL(heap -> size, 2);
}

int main() {
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("heap", init_suite, clean_suite);
		CU_add_test(suite, "Testing create heap", test_create_heap);
		CU_add_test(suite, "Testing insert_into heap (empty)", test_insert_empty_heap);
		CU_add_test(suite, "Testing insert_into heap (filled)", test_insert_filled_heap);
		CU_add_test(suite, "Testing getLeftChild", test_get_left_child);
		CU_add_test(suite, "Testing getRightChild", test_get_right_child);
		CU_add_test(suite, "Testing getParent (Even)", test_get_parent_even);
		CU_add_test(suite, "Testing getParent (Odd)", test_get_parent_odd);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}
	return 0;
}
