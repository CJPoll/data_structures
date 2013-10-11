#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct int_array {
	void **array;
	int size;
	int max_len;
} array;

array *
arrayCreate();

array *
arrayPush(array *array, void *value);

int *
arrayPop(array *array);

array *
arrayInsert(array *array, int position, void *value);

array *
arrayRemove(array *array, int position);

#endif
