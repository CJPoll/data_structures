#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define FULLNESS_RATIO .75
#define EMPTINESS_RATIO .34

typedef struct int_array {
	void **array;
	int size;
	int max_len;
} array;

array *
arrayCreate();

array *
arrayPushHead(array *array, void *value);

void *
arrayPeekHead(array *array);

void *
arrayPopHead(array *array);

array *
arrayPushTail(array *array, void *value);

void *
arrayPeekTail(array *array);

void *
arrayPopTail(array *array);

array *
arrayInsert(array *array, int index, void *value);

array *
arrayRemove(array *array, int index);

void *
arrayRetrieve(array *array, int index);

array *
arrayUpdate(array *array, int index, void *value);

#endif
