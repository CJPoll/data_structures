#include "/usr/local/include/CUnit/CUnit.h"
#include "/usr/local/include/CUnit/Basic.h"
// Don't forget to include your tested code up here!

#include <stdio.h>
#include <stdlib.h>

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void
test_function() {
}

int
main() {
	/*
	 * Not very safe code - a lot could potentially fail. Need to add some error
	 * handling.
	 */
	if (CU_initialize_registry() == CUE_SUCCESS) {
		CU_pSuite suite = CU_add_suite("Suite Name", init_suite, clean_suite);
		CU_add_test(suite, "Testing Something", test_function);
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_basic_run_tests();
	}

	CU_cleanup_registry();

	return 0;
}
