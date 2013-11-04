#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define CP_FULLNESS_RATIO .7

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
arrayInsert(array *array, int position, void *value);

array *
arrayRemove(array *array, int position);

void *
arrayRetrieve(array *array, int position);

#endif
