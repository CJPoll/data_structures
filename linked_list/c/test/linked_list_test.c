#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
// Don't forget to include your tested code up here!
#include "../src/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void
test_create_list() {
	LinkedList *list = createLinkedList();

	CU_ASSERT_PTR_NOT_NULL(list);
	CU_ASSERT_PTR_NOT_NULL(list);
	CU_ASSERT_EQUAL(list -> size, 0);
}

void
test_insert_list() {
	LinkedList *list = createLinkedList();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertList(list, &value1, 1);
	insertList(list, &value2, 1);
	insertList(list, &value3, 1);

	int position1 = *(int*)list -> head -> value;
	int position2 = *(int*)list -> head -> next -> value;
	int position3 = *(int*)list -> head -> next -> next -> value;

	CU_ASSERT_EQUAL(position1, 3);
	CU_ASSERT_EQUAL(position2, 2);
	CU_ASSERT_EQUAL(position3, 1);
}

void
test_push_tail() {
	LinkedList *list = createLinkedList();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	pushTailList(list, &value1);
	pushTailList(list, &value2);
	pushTailList(list, &value3);

	int *position1 = (int*)list -> head -> value;
	int *position2 = (int*)list -> head -> next -> value;
	int *position3 = (int*)list -> head -> next -> next -> value;

	CU_ASSERT_EQUAL(position1, &value1);
	CU_ASSERT_EQUAL(position2, &value2);
	CU_ASSERT_EQUAL(position3, &value3);
}

void
test_pop_tail() {
	LinkedList *list = createLinkedList();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	pushTailList(list, &value1);
	pushTailList(list, &value2);
	pushTailList(list, &value3);

	int *position3 = (int*)popTailList(list);
	printf("\n");
	printf("Position3: %d\n", *position3);
	int *position2 = (int*)popTailList(list);
	printf("Position2: %d\n", *position2);
	int *position1 = (int*)popTailList(list);
	printf("Position1: %d\n", *position1);

	CU_ASSERT_EQUAL(position3, &value3);
	CU_ASSERT_EQUAL(position2, &value2);
	CU_ASSERT_EQUAL(position1, &value1);
}

void
test_pop_head() {
	LinkedList *list = createLinkedList();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	insertList(list, &value1, 1);
	insertList(list, &value2, 1);
	insertList(list, &value3, 1);

	int *position1 = (int *)popHeadList(list);
	int *position2 = (int *)popHeadList(list);
	int *position3 = (int *)popHeadList(list);

	CU_ASSERT_PTR_EQUAL(position1, &value3);
	CU_ASSERT_PTR_EQUAL(position2, &value2);
	CU_ASSERT_PTR_EQUAL(position3, &value1);

	CU_ASSERT_EQUAL(list -> size, 0);
}

int
main() {
	/*
	 * Not very safe code - a lot could potentially fail. Need to add some error
	 * handling.
	 */
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("linked_list", init_suite, clean_suite);
		CU_add_test(suite, "Testing List Creation", test_create_list);
		CU_add_test(suite, "Testing List Insertion", test_insert_list);
		CU_add_test(suite, "Testing List Push Tail", test_push_tail);
		CU_add_test(suite, "Testing List Popping From Head", test_pop_head);
		CU_add_test(suite, "Testing List Popping From Tail", test_pop_tail);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
