#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

typedef struct Heap {
	array *array;
	int size;
} Heap;

Heap *heapCreate();
Heap *heapSort(Heap *heap);
Heap *heapInsert(Heap *heap, void *value);
void *heapPop(Heap *heap);
int getLeftChild(int parent);
int getRightChild(int parent);
int getParent(int child);

#endif
