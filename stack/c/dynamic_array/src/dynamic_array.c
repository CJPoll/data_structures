#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

array *
arrayCreate() {
	array *array = malloc(sizeof(array));
	return array;
}

static array *
shiftUp(array *array) {

	for (int i = array -> size; i >= 0; i--) {
		void *swap = *(array -> array + i);
		*(array -> array + i) = *(array -> array + i + 1);
		*(array -> array + i + 1) = swap;
	}

	return array;
}

static array *
shiftDown(array *array, int startPosition) {
	for (int i = startPosition - 1; i < array -> size - 1; i++) {
		void *swap = *(array -> array + i);
		*(array -> array + i) = *(array -> array + i + 1);
		*(array -> array + i + 1) = swap;
	}

	return array;
}

static array *
arrayBuild(array *array) {
	if (array -> array == NULL) {
		array -> array = calloc(5, sizeof(void*));
		array -> max_len = 5;
	}
	return array;
}

array *
arrayInsert(array *array, int position, void *value) {
	array = arrayBuild(array);
	*(array -> array + position - 1) = value;
	array -> size++;

	return array;
}

void *
arrayRetrieve(array *array, int position) {
	return *(array -> array + (position - 1));
}

array *
arrayRemove(array *array, int position) {

	/*
	 * If the position is invalid, ignore the function call.
	 */
	if (position > array -> size || position < 0) {
		return array;
	}

	/*
	 * Set the position to NULL
	 */
	*(array -> array + (position - 1)) = NULL;

	/*
	 * Shift the values (up/down?).
	 */
	shiftDown(array, position);

	array -> size--;

	return array;
}

array *
arrayPushHead(array *array, void *value) {
	array = arrayBuild(array);
	if (array -> size + 1 > array -> max_len) {
		//TODO: handle expanding array
	}

	shiftUp(array);

	arrayInsert(array, 1, value);

	return array;	
}

void *
arrayPeekHead(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	return arrayRetrieve(array, 1);
}

void *
arrayPopHead(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	void *value = arrayRetrieve(array, 1);

	array = arrayRemove(array, 1);

	return value;
}

array *
arrayPushTail(array *array, void *value) {
	arrayBuild(array);
	arrayInsert(array, array -> size + 1, value);
	return array;
}

void *
arrayPeekTail(array *array) {
	arrayBuild(array);
	return arrayRetrieve(array, array -> size);
}

void *
arrayPopTail(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	void *value = arrayRetrieve(array, array -> size);

	array = arrayRemove(array, array -> size);

	return value;
}
