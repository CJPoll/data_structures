#include "linked_list.h"

/*
 * Private API
 */
struct Node *traverseList(struct Node *node, const int position);

LinkedList *
createLinkedList() {
	//("Creating linked list\n");

	LinkedList *linkedList = malloc(sizeof(LinkedList));
	linkedList -> head = NULL;
	linkedList -> size = 0;

	//("Linked list size: %d\n", linkedList -> size);
	//("Created linked list\n");

	return linkedList;
};

LinkedList *insertList(LinkedList *linkedList, void *value, int position) {
	int size = linkedList -> size;
	if (size < position - 1) return linkedList;

	struct Node *prev = traverseList(linkedList -> head, position - 1);
	struct Node *new = malloc(sizeof(struct Node));

	if (position == 1 && prev == linkedList -> head) {
		new -> next = linkedList -> head;
		linkedList -> head = new;
	} else {
		new -> next = prev -> next;
		prev -> next = new;
	}

	new -> value = value;

	linkedList -> size++;

	return linkedList;
}

void *
retrieveList(LinkedList *linkedList, int position) {

	int size = linkedList -> size;
	void *value = 0;

	if (position <= size) {
		//("Retrieving value\n");
		struct Node *head = linkedList -> head;
		struct Node *target = traverseList(head, position);
		value = target -> value;
	}

	return value;
}

LinkedList *
removeList(LinkedList *linkedList, int position) {
	int size = linkedList -> size;
	if (size < 0 || size < position) return linkedList;

	struct Node *node = NULL;

	if (position == 1) {
		node = linkedList -> head;
		linkedList -> head = node -> next;
	} else {

		struct Node *prev = linkedList -> head;
		prev = traverseList(prev, position - 1);

		node = prev -> next;
		prev -> next = node -> next;
	}

	free(node);
	node = NULL;

	linkedList -> size--;

	return linkedList;
}

void *
popTailList(LinkedList *linkedList) {
	int size = linkedList -> size;
	struct Node *node = traverseList(linkedList -> head, size);
	void *value = node -> value;
	removeList(linkedList, size);
	return value;
}

void *
peekTailList(LinkedList *linkedList) {
	struct Node *node = traverseList(linkedList -> head, linkedList -> size);
	return node -> value;
}

LinkedList *
pushHeadList(LinkedList *linkedList, void *value) {
	insertList(linkedList, value, 1);

	return linkedList;
}

LinkedList *
pushTailList(LinkedList *linkedList, void *value) {
	insertList(linkedList, value, linkedList -> size + 1);

	return linkedList;
}

void *
peekHeadList(LinkedList *linkedList) {
	return retrieveList(linkedList, 1);
}

void *
popHeadList(LinkedList *linkedList) {
	struct Node *node = traverseList(linkedList -> head, 1);
	void *value = node -> value;
	removeList(linkedList, 1);
	return value;
}



// =============================================================================
// Private Functions
// ============================================================================



/*
 * Currently implemented recursively. We could just as easily implement the
 * function using a loop. Find out if the compiler being used supports tail
 * recursion; if so, then there's no reason to switch over to a loop.
 */
struct Node *
traverseList(struct Node *node, const int position) {
	if (node == NULL) return NULL;
	if (position <= 1) return node;
	return traverseList(node->next, position - 1);
}
