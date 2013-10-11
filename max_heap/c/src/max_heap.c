#include "max_heap.h"

Heap *
heapCreate(int starting_size) {
	Heap *heap = malloc(sizeof(Heap));

	heap -> array = calloc(starting_size, sizeof(int));
	heap -> size  = 0;
	heap -> insert  = &heapInsert;

	return heap;
}

Heap *
heapInsert(Heap *heap) {
	return heap;
}
