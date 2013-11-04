#include "max_heap.h"

static Heap * heapify(Heap *heap);

Heap *
heapCreate() {
	Heap *heap = malloc(sizeof(Heap));

	heap -> array = arrayCreate();
	heap -> size  = 0;

	return heap;
}

Heap *
heapInsert(Heap *heap, void *value) {
	array *array = heap -> array;
	arrayPushTail(array, value);
	heap -> size = heap -> array -> size;
	heapify(heap);
	return heap;
}

Heap *
heapify(Heap *heap) {
	if (heap -> size == 1) return heap;

	array *array = heap -> array;
	int size = heap -> size;
	int parent = getParent(size);

	int leftPosition = getLeftChild(size / 2);
	int largest = size;
	if (leftPosition <= size) {
		int left = *(int*)getLeftChild(size)
	}
	int rightPosition = getRightChild(size);

	void *left = arrayRetrieve(array, leftPosition - 1);
	void *right = arrayRetrieve(array, rightPosition - 1);

	

	return heap;
}

int
getLeftChild(int parent) {
	return parent * 2;
}

int
getRightChild(int parent) {
	return parent * 2 + 1;
}

int
getParent(int child) {
	if (child <=1 ) return child;

	return child / 2;
}
