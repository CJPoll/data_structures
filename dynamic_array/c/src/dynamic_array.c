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
shiftDown(array *array, int startIndex) {
	for (int i = startIndex; i < array -> size - 1; i++) {
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

static array *
arrayExpand(array *array) {
	int currentMax = array -> max_len;
	int targetMax = currentMax * 1.8;

	array -> array = realloc(array -> array, targetMax * sizeof(void *));

	array -> max_len = targetMax;

	return array;
}

static array *
arrayContract(array *array) {
	int currentMax = array -> max_len;
	int targetMax = currentMax * .66;

	array -> array = realloc(array -> array, targetMax * sizeof(void *));

	array -> max_len = targetMax;

	return array;
}

array *
arrayInsert(array *array, int index, void *value) {
	array = arrayBuild(array);

	if (array -> size + 1 >= array -> max_len * FULLNESS_RATIO) {
		arrayExpand(array);
	}

	*(array -> array + index) = value;

	array -> size++;

	return array;
}

void *
arrayRetrieve(array *array, int index) {
	return *(array -> array + index);
}

array *
arrayRemove(array *array, int index) {

	if (index > array -> size || index < 0) {
		return array;
	}

	if ((array -> size) - 1 <= array -> max_len * EMPTINESS_RATIO && array -> max_len - 1 >= 8) {
		array = arrayContract(array);
	}

	*(array -> array + (index)) = NULL;

	shiftDown(array, index);

	array -> size--;

	return array;
}

array *
arrayPushHead(array *array, void *value) {
	array = arrayBuild(array);
	if (array -> size + 1> array -> max_len) {
		//TODO: handle expanding array
	}

	shiftUp(array);

	arrayInsert(array, 0, value);

	return array;	
}

void *
arrayPeekHead(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	return arrayRetrieve(array, 0);
}

void *
arrayPopHead(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	void *value = arrayRetrieve(array, 0);

	array = arrayRemove(array, 0);

	return value;
}

array *
arrayPushTail(array *array, void *value) {
	arrayBuild(array);
	arrayInsert(array, array -> size, value);
	return array;
}

void *
arrayPeekTail(array *array) {
	arrayBuild(array);
	return arrayRetrieve(array, array -> size - 1);
}

void *
arrayPopTail(array *array) {
	if (array == NULL || array -> size == 0) {
		return NULL;
	}

	void *value = arrayRetrieve(array, array -> size - 1);


	array = arrayRemove(array, array -> size - 1);

	return value;
}

array *
arrayUpdate(array *array, int index, void *value) {
	if (array == NULL 
			|| array -> size == 0 
			|| index > array -> size 
			|| index < 1) {
		return NULL;
	}

	*(array -> array + index) = value;
	
	return array;
}

