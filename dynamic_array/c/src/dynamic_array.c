#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

#define FULLNESS_RATIO .8

array *
arrayCreate() {
	array *array = malloc(sizeof(array));
	return array;
}

array *
arrayInsert(array *array, int position, void *value) {
	void **innerArray = array -> array;
	if (innerArray == NULL) {
		array -> array = calloc(5, sizeof(void*));
		innerArray = array -> array;
		array -> max_len = 5;
	}

	*(innerArray + position - 1) = value;

	return array;
}
