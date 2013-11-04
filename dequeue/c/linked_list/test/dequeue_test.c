#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
// Don't forget to include your tested code up here!
#include "../src/dequeue.h"

#include <stdio.h>
#include <stdlib.h>

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void
test_create() {
	Dequeue *dequeue = createDequeue();
	
	CU_ASSERT_PTR_NOT_NULL(dequeue);
}

void
test_enqueue_front() {
	Dequeue *dequeue = createDequeue();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	enqueueFrontDequeue(dequeue, &value1);
	enqueueFrontDequeue(dequeue, &value2);
	enqueueFrontDequeue(dequeue, &value3);

	int size = sizeDequeue(dequeue);

	CU_ASSERT_EQUAL(size, 3);
}

void
test_dequeue_front() {
	Dequeue *dequeue = createDequeue();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	dequeue = enqueueFrontDequeue(dequeue, &value1);
	dequeue = enqueueFrontDequeue(dequeue, &value2);
	dequeue = enqueueFrontDequeue(dequeue, &value3);

	CU_ASSERT_EQUAL(3, sizeDequeue(dequeue));

	int *position3 = (int *)dequeueFrontDequeue(dequeue);
	int *position2 = (int *)dequeueFrontDequeue(dequeue);
	int *position1 = (int *)dequeueFrontDequeue(dequeue);

	CU_ASSERT_EQUAL(0, sizeDequeue(dequeue));

	CU_ASSERT_EQUAL(*position3, value3);
	CU_ASSERT_EQUAL(*position2, value2);
	CU_ASSERT_EQUAL(*position1, value1);
}

void
test_enqueue_back() {
	Dequeue *dequeue = createDequeue();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	enqueueBackDequeue(dequeue, &value1);
	enqueueBackDequeue(dequeue, &value2);
	enqueueBackDequeue(dequeue, &value3);

	int size = sizeDequeue(dequeue);

	CU_ASSERT_EQUAL(size, 3);
}

void
test_dequeue_back() {
	Dequeue *dequeue = createDequeue();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	dequeue = enqueueBackDequeue(dequeue, &value1);
	dequeue = enqueueBackDequeue(dequeue, &value2);
	dequeue = enqueueBackDequeue(dequeue, &value3);

	CU_ASSERT_EQUAL(3, sizeDequeue(dequeue));

	int *position3 = (int *)dequeueBackDequeue(dequeue);
	int *position2 = (int *)dequeueBackDequeue(dequeue);
	int *position1 = (int *)dequeueBackDequeue(dequeue);

	CU_ASSERT_EQUAL(0, sizeDequeue(dequeue));

	printf("\nPosition%d (back): %d\n", 3, *position3);
	printf("\nPosition%d (back): %d\n", 2, *position2);
	printf("\nPosition%d (back): %d\n", 1, *position1);

	CU_ASSERT_PTR_EQUAL(position3, &value3);
	CU_ASSERT_PTR_EQUAL(position2, &value2);
	CU_ASSERT_PTR_EQUAL(position1, &value1);
}

void
test_size() {
	Dequeue *dequeue = createDequeue();
	int size = sizeDequeue(dequeue);

	CU_ASSERT_EQUAL(size, 0);
}

int
main() {
	/*
	 * Not very safe code - a lot could potentially fail. Need to add some error
	 * handling. Not a terribly high priority, as the library is pretty
	 * well-tested, but still ought to be done.
	 */
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("Suite Name", init_suite, clean_suite);
		CU_add_test(suite, "Testing Create", test_create);
		CU_add_test(suite, "Testing Push To Front", test_enqueue_front);
		CU_add_test(suite, "Testing Dequeue From Front", test_dequeue_front);
		CU_add_test(suite, "Testing Push To Back", test_enqueue_back);
		CU_add_test(suite, "Testing Dequeue From Back", test_dequeue_back);
		CU_add_test(suite, "Testing Size", test_size);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
