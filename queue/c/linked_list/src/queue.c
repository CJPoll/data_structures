#include "queue.h"
#include "linked_list.h"

struct Queue {
	LinkedList *list;
	int size;
};

Queue *
createQueue() {
	Queue *queue = malloc(sizeof(Queue));
	queue -> list = createLinkedList();
	queue -> size = 0;

	return queue;
}

Queue *
pushQueue(Queue *queue, void *value) {
	LinkedList *linkedList = queue -> list;
	pushTailList(linkedList, value);
	return queue;
}

void *
popQueue(Queue *queue) {
	LinkedList *linkedList = queue -> list;
	return popTailList(linkedList);
}

int
sizeQueue(Queue *queue) {
	return queue -> list -> size;
}

Queue *
flushQueue(Queue *queue) {
	free(queue -> list);
	queue -> list = createLinkedList();
	return queue;
}
