#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
#include "../src/dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void
test_create_dynamic_array() {
	array *array = arrayCreate();
	CU_ASSERT_PTR_NOT_NULL(array);
	CU_ASSERT_PTR_NULL(array -> array);
	CU_ASSERT_EQUAL(array -> size, 0);
	CU_ASSERT_EQUAL(array -> max_len, 0);
}

void
test_insert_into_empty_array() {
	array *array = arrayCreate();
	int *value1 = malloc(sizeof(int));
	*value1 = 5;
	array = arrayInsert(array, 0, value1);

	CU_ASSERT_PTR_NOT_NULL(array -> array);
	CU_ASSERT_PTR_NOT_NULL(array -> array[0]);
	CU_ASSERT_EQUAL(*(int *)(array -> array[0]), 5);
}

void
test_insert_into_nonempty_array() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	arrayInsert(array, 0, &value1);
	arrayInsert(array, 1, &value2);
	arrayInsert(array, 2, &value3);

	CU_ASSERT_EQUAL(array -> size, 3);
	CU_ASSERT_EQUAL(*(int *)array -> array[0], 1);
	CU_ASSERT_EQUAL(*(int *)array -> array[1], 2);
	CU_ASSERT_EQUAL(*(int *)array -> array[2], 3);
}

void
test_retrieve_element() {
	array *array = arrayCreate();

	int value = 1;

	arrayInsert(array, 0, &value);
	int *value1 = arrayRetrieve(array, 0);

	CU_ASSERT_PTR_EQUAL(value1, &value);
}

void test_update_element() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;

	arrayInsert(array, 0, &value1);
	arrayInsert(array, 1, &value2);

	arrayUpdate(array, 1, &value1);

	int *position1 = (int*)arrayRetrieve(array, 0);
	int *position2 = (int*)arrayRetrieve(array, 1);

	CU_ASSERT_EQUAL(array -> size, 2);
	CU_ASSERT_PTR_EQUAL(position1, position2);
	CU_ASSERT_PTR_EQUAL(position1, &value1);
}

void
test_remove_element() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	arrayInsert(array, 0, &value1);
	arrayInsert(array, 1, &value2);
	arrayInsert(array, 2, &value3);

	CU_ASSERT_EQUAL(array -> size, 3);

	arrayRemove(array, 1);

	CU_ASSERT_EQUAL(array -> size, 2);
	CU_ASSERT_EQUAL(*(int*)array -> array[0], 1);
	CU_ASSERT_EQUAL(*(int*)array -> array[1], 3);
	CU_ASSERT_PTR_NULL(array -> array[2]);
	CU_ASSERT_PTR_NULL(array -> array[4]);
}

void
test_push_head_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	printf("Pushing heads\n");
	arrayPushHead(array, &value1);
	arrayPushHead(array, &value2);
	arrayPushHead(array, &value3);

	printf("First: %d", *(int*)array -> array[0]);

	printf("Retrieving Values\n");
	printf("Retrieving 1st value");
	int position1 = *(int*)arrayRetrieve(array, 0);
	printf("Retrieving 2nd value");
	int position2 = *(int*)arrayRetrieve(array, 1);
	printf("Retrieving 3rd value");
	int position3 = *(int*)arrayRetrieve(array, 2);

	printf("Assertions\n");
	CU_ASSERT_EQUAL(array -> size, 3);
	CU_ASSERT_EQUAL(position1, 3);
	CU_ASSERT_EQUAL(position2, 2);
	CU_ASSERT_EQUAL(position3, 1);
}

void
test_peek_head_empty() {
	array *array = arrayCreate();

	void *position1 = arrayPeekHead(array);

	CU_ASSERT_EQUAL(array -> size, 0);
	CU_ASSERT_PTR_NULL(position1);
}

void
test_peek_head_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;

	arrayPushHead(array, &value1);
	arrayPushHead(array, &value2);

	int position1 = *(int*)arrayPeekHead(array);
	int position2 = *(int*)arrayRetrieve(array, 1);

	CU_ASSERT_EQUAL(array -> size, 2);
	CU_ASSERT_EQUAL(position1, 2);
	CU_ASSERT_EQUAL(position2, 1);
}

void
test_pop_head_empty() {
	array *array = arrayCreate();

	int *position1 = (int*)arrayPopHead(array);
	
	CU_ASSERT_EQUAL(array -> size, 0);
	CU_ASSERT_PTR_NULL(position1);
}

void
test_pop_head_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	arrayPushHead(array, &value1);
	arrayPushHead(array, &value2);
	arrayPushHead(array, &value3);

	int *position1 = (int*)arrayPopHead(array);
	int *position2 = (int*)arrayRetrieve(array, 0);
	int *position3 = (int*)arrayRetrieve(array, 1);
	
	CU_ASSERT_EQUAL(array -> size, 2);
	CU_ASSERT_PTR_NOT_NULL(position1);
	CU_ASSERT_PTR_EQUAL(position1, &value3);
	CU_ASSERT_PTR_EQUAL(position2, &value2);
	CU_ASSERT_PTR_EQUAL(position3, &value1);
}

void
test_push_tail_empty() {
	array *array = arrayCreate();

	int value1 = 5;

	array = arrayPushTail(array, &value1);

	int *position1 = arrayRetrieve(array, 0);

	CU_ASSERT_EQUAL(array -> size, 1);
	CU_ASSERT_PTR_EQUAL(position1, &value1);
}

void
test_push_tail_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	array = arrayPushTail(array, &value1);
	array = arrayPushTail(array, &value2);
	array = arrayPushTail(array, &value3);

	int *position1 = arrayRetrieve(array, 0);
	int *position2 = arrayRetrieve(array, 1);
	int *position3 = arrayRetrieve(array, 2);

	CU_ASSERT_EQUAL(array -> size, 3);
	CU_ASSERT_PTR_EQUAL(position1, &value1);
	CU_ASSERT_PTR_EQUAL(position2, &value2);
	CU_ASSERT_PTR_EQUAL(position3, &value3);
}

void
test_peek_tail_empty() {
	array *array = arrayCreate();

	int value1 = 238;

	array = arrayPushTail(array, &value1);

	int *tail = (int*)arrayPeekTail(array);

	CU_ASSERT_EQUAL(array -> size, 1);
	CU_ASSERT_PTR_EQUAL(tail, &value1);
}

void
test_peek_tail_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	arrayPushTail(array, &value1);
	arrayPushTail(array, &value2);
	arrayPushTail(array, &value3);

	int *position3 = arrayPeekTail(array);

	CU_ASSERT_EQUAL(array -> size, 3);
	CU_ASSERT_PTR_EQUAL(position3, &value3);
}

void
test_pop_tail_empty() {
	array *array = arrayCreate();

	int *tail = arrayPopTail(array);

	CU_ASSERT_EQUAL(array -> size, 0);
	CU_ASSERT_PTR_NULL(tail);
}

void
test_pop_tail_filled() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	array = arrayPushTail(array, &value1);
	array = arrayPushTail(array, &value2);
	array = arrayPushTail(array, &value3);

	int *position3 = arrayPopTail(array);
	int *position2 = arrayPopTail(array);
	int *position1 = arrayPopTail(array);

	CU_ASSERT_EQUAL(array -> size, 0);
	CU_ASSERT_PTR_EQUAL(position3, &value3);
	CU_ASSERT_PTR_EQUAL(position2, &value2);
	CU_ASSERT_PTR_EQUAL(position1, &value1);
}

void
test_expand_array() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;

	array = arrayPushTail(array, &value1);
	array = arrayPushTail(array, &value2);
	array = arrayPushTail(array, &value3);
	array = arrayPushTail(array, &value4);

	CU_ASSERT_EQUAL(array -> size, 4);
	CU_ASSERT_EQUAL(array -> max_len, 9);

	CU_ASSERT_PTR_EQUAL((int*)array -> array[0], &value1);
	CU_ASSERT_PTR_EQUAL((int*)array -> array[1], &value2);
	CU_ASSERT_PTR_EQUAL((int*)array -> array[2], &value3);
	CU_ASSERT_PTR_EQUAL((int*)array -> array[3], &value4);
}

void
test_contract_array() {
	array *array = arrayCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;

	array = arrayPushTail(array, &value1);
	array = arrayPushTail(array, &value2);
	array = arrayPushTail(array, &value3);
	array = arrayPushTail(array, &value4);

	CU_ASSERT_EQUAL(array -> max_len, 9);
	
	arrayPopTail(array);
	arrayPopTail(array);

	CU_ASSERT_EQUAL(array -> max_len, 5);
}

int
main() {
	/*
	 * Not very safe code - a lot could potentially fail. Need to add some error
	 * handling.
	 */
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("dynamic_array", init_suite, clean_suite);
		CU_add_test(suite, "Testing Creation", test_create_dynamic_array);
		CU_add_test(suite, "Testing Insertion (when empty)", test_insert_into_empty_array);
		CU_add_test(suite, "Testing Insertion (when not empty)", test_insert_into_nonempty_array);
		CU_add_test(suite, "Testing Retrieval", test_retrieve_element);
		CU_add_test(suite, "Testing Removal", test_remove_element);
		CU_add_test(suite, "Testing Updating", test_update_element);
		CU_add_test(suite, "Testing Push Head (filled & empty)", test_push_head_filled);
		CU_add_test(suite, "Testing Peek Head (when empty)", test_peek_head_empty);
		CU_add_test(suite, "Testing Peek Head (when not empty)", test_peek_head_filled);
		CU_add_test(suite, "Testing Pop Head (when empty)", test_pop_head_empty);
		CU_add_test(suite, "Testing Pop Head (when not empty)", test_pop_head_filled);
		CU_add_test(suite, "Testing Push Tail (when empty)", test_push_tail_empty);
		CU_add_test(suite, "Testing Push Tail (when not empty)", test_push_tail_filled);
		CU_add_test(suite, "Testing Peek Tail (when empty)", test_peek_tail_empty);
		CU_add_test(suite, "Testing Peek Tail (when not empty)", test_peek_tail_filled);
		CU_add_test(suite, "Testing Pop Tail (when empty)", test_pop_tail_empty);
		CU_add_test(suite, "Testing Pop Tail (when not empty)", test_pop_tail_filled);
		CU_add_test(suite, "Testing expand array", test_expand_array);
		CU_add_test(suite, "Testing contract array", test_contract_array);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
