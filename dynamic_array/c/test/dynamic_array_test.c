#include "/Users/cjpoll/local/include/CUnit/CUnit.h"
#include "/Users/cjpoll/local/include/CUnit/Basic.h"
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
	array = arrayInsert(array, 1, value1);

	CU_ASSERT_PTR_NOT_NULL(array -> array);
	CU_ASSERT_PTR_NOT_NULL(array -> array[0]);
	CU_ASSERT_EQUAL(*(int *)(array -> array[0]), 5);
}

void
test_insert_into_nonempty_array() {
	array *array = arrayCreate();
	int *value1 = malloc(sizeof(int));
	int *value2 = malloc(sizeof(int));
	int *value3 = malloc(sizeof(int));
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
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
