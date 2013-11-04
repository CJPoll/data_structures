#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
#include "../src/stack.h"
#include "../src/dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>


int
init_suite(void) { return 0; }

int
clean_suite(void) { return 0; }

void
test_create_stack() {
	stack *stack = stackCreate();
	CU_ASSERT_PTR_NOT_NULL(stack);
}

void
test_push_stack_empty() {
	stack *stack = stackCreate();

	int pageNumber = 394;
	
	stackPush(stack, &pageNumber);

	int *tail = (int*)stack -> array -> array[0];

	CU_ASSERT_EQUAL(stack -> size, 1);
	CU_ASSERT_PTR_EQUAL(tail, &pageNumber);
}

void
test_pop_stack_empty() {
	stack *stack = stackCreate();

	int *poppedValue = (int*)stackPop(stack);

	CU_ASSERT_EQUAL(stack -> size, 0);
	CU_ASSERT_PTR_NULL(poppedValue);
}

void 
test_push_stack_filled() {
	stack *stack = stackCreate();
	
	int value1 = 3;
	int value2 = 2;
	int value3 = 1;

	stack = stackPush(stack, &value1);
	stack = stackPush(stack, &value2);
	stack = stackPush(stack, &value3);

	CU_ASSERT_EQUAL(stack -> size, 3);

	int *position1 = (int*) stack -> array -> array[2];
	int *position2 = (int*) stack -> array -> array[1];
	int *position3 = (int*) stack -> array -> array[0];

	CU_ASSERT_PTR_EQUAL(position1, &value3);
	CU_ASSERT_EQUAL(position2, &value2);
	CU_ASSERT_EQUAL(position3, &value1);
}

void test_pop_stack_filled() {
	stack *stack = stackCreate();
	
	int value1 = 3;
	int value2 = 2;
	int value3 = 1;

	stack = stackPush(stack, &value1);
	stack = stackPush(stack, &value2);
	stack = stackPush(stack, &value3);

	CU_ASSERT_EQUAL(stack -> size, 3);
	CU_ASSERT_PTR_EQUAL((int*)stackPop(stack), &value3);
	CU_ASSERT_PTR_EQUAL(stackPop(stack), &value2);
	CU_ASSERT_PTR_EQUAL(stackPop(stack), &value1);
	// Now that we've popped off all values, we need to see if the size has been
	// updated correctly
	CU_ASSERT_EQUAL(stack -> size, 0);
}

void
test_peek_stack_empty() {
	stack *stack = stackCreate();

	int *position1 = stackPeek(stack);
	
	CU_ASSERT_EQUAL(stack -> size, 0);
	CU_ASSERT_PTR_NULL(position1);
}

void
test_peek_stack_filled() {
	stack *stack = stackCreate();

	int value1 = 3;
	int value2 = 2;
	int value3 = 1;

	stack = stackPush(stack, &value1);
	stack = stackPush(stack, &value2);
	stack = stackPush(stack, &value3);

	int *position3 = stackPeek(stack);

	CU_ASSERT_EQUAL(stack -> size, 3);
	CU_ASSERT_PTR_EQUAL(position3, &value3);
}

void
test_flush_stack_empty() {
	stack *stack = stackCreate();

	stack = stackFlush(stack);

	CU_ASSERT_EQUAL(stack -> size, 0);
}

void
test_flush_stack_filled() {
	stack *stack = stackCreate();

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	stack = stackPush(stack, &value1);
	stack = stackPush(stack, &value2);
	stack = stackPush(stack, &value3);

	stack = stackFlush(stack);

	int *position1 = (int*)stackPop(stack);

	CU_ASSERT_PTR_NOT_NULL(stack);
	CU_ASSERT_EQUAL(stack -> size, 0);
	CU_ASSERT_PTR_NULL(position1);
}

int main() {
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("stack_array", init_suite, clean_suite);
		
		CU_add_test(suite, "Testing Creation", test_create_stack);
		CU_add_test(suite, "Testing Pushing (empty)", test_push_stack_empty);
		CU_add_test(suite, "Testing Pushing (filled)", test_push_stack_filled);
		CU_add_test(suite, "Testing Popping (empty)", test_pop_stack_empty);
		CU_add_test(suite, "Testing Popping (filled)", test_pop_stack_filled);
		CU_add_test(suite, "Testing Peeking (empty)", test_peek_stack_empty);
		CU_add_test(suite, "Testing Peeking (filled)", test_peek_stack_filled);
		CU_add_test(suite, "Testing Flushing (empty)", test_flush_stack_empty);
		CU_add_test(suite, "Testing Flushing (filled)", test_flush_stack_filled);

		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();
}
