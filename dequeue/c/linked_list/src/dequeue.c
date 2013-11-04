#include <stdlib.h>
#include "dequeue.h"
#include "linked_list.h"

struct Dequeue {
	int size;
	LinkedList *list;
};

Dequeue *
createDequeue() {
	Dequeue *dequeue = malloc(sizeof(Dequeue));
	dequeue -> size = 0;
	dequeue -> list = createLinkedList();

	return dequeue;
}

int sizeDequeue(Dequeue *dequeue) {
	return dequeue -> list -> size;
}

Dequeue *
enqueueBackDequeue(Dequeue *dequeue, void *value) {
	pushTailList(dequeue -> list, value);

	return dequeue;
}

Dequeue *
enqueueFrontDequeue(Dequeue *dequeue, void *value) {
	pushHeadList(dequeue -> list, value);

	return dequeue;
}

void *
dequeueBackDequeue(Dequeue *dequeue) {
	void *value = popTailList(dequeue -> list);
	return value;
}

void *
dequeueFrontDequeue(Dequeue *dequeue) {
	void *value = popHeadList(dequeue -> list);
	return value;
}

