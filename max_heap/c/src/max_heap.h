#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	void *array;
	int size;
	struct Heap *(*insert)(struct Heap*);
} Heap;

Heap *heapCreate(int starting_size);
Heap *heapInsert(Heap *heap);
void *heapPop(Heap *heap);

#endif
