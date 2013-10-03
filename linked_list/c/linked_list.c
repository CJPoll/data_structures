#include "linked_list.h"



/*
 * Private API
 */
struct Node *traverseList(struct Node *node, const int position);



// =============================================================================
// Public Functions
// ============================================================================

int
main() {
	return 0;
}



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

LinkedList *insertValue(LinkedList *linkedList, void *value, int position) {
	//("Inserting value: %d\n", *(int*)value);
	int size = linkedList -> size;
	if (size < position - 1) return linkedList;

	struct Node *prev = traverseList(linkedList -> head, position - 1);
	struct Node *new = malloc(sizeof(struct Node));

	if (prev == NULL) {
		new -> next = NULL;
		linkedList -> head = new;
	} else {
		new -> next = prev -> next;
		prev -> next = new;
	}

	new -> value = value;

	linkedList -> size++;

	//("Inserted value: %d\n", *(int*)value);

	return linkedList;
}

LinkedList *
pushValue(LinkedList *linkedList, void *value) {
	//("Pushing value: %d\n", *(int*)value);

	int size = linkedList -> size;
	insertValue(linkedList, value, size + 1);

	//("Pushed value: %d\n", *(int*)value);

	return linkedList;
}

void *
getValue(LinkedList *linkedList, int position) {
	//("Getting value from linked list at position: %d\n", position);

	int size = linkedList -> size;
	void *value = 0;

	//("position: %d size: %d\n", position, size);
	if (position <= size) {
		//("Retrieving value\n");
		struct Node *head = linkedList -> head;
		struct Node *target = traverseList(head, position);
		value = target -> value;
	}

	//("Got value: %p from linked list at position: %d\n", value, position);

	return value;
}

LinkedList *
removeValue(LinkedList *linkedList, int position) {
	//("Removing node from position: %d\n", position);
	int size = linkedList -> size;
	if (size < 0 || size < position) return linkedList;
	struct Node *node = 0;
	if (size == 1) {
		node = linkedList -> head;
		linkedList -> head = NULL;
	} else {

		struct Node *prev = linkedList -> head;
		prev = traverseList(prev, position - 1);

		node = prev -> next;
		prev -> next = node -> next;
	}

	free(node);
	node = 0;

	linkedList -> size--;

	//("Removed node from position: %d\n", position);

	return linkedList;
}

void
*pop(LinkedList *linkedList) {
	int size = linkedList -> size;
	struct Node *node = traverseList(linkedList -> head, size);
	void *value = node -> value;
	removeValue(linkedList, size);
	return value;
}

void 
*peek(LinkedList *linkedList) {
	struct Node *node = traverseList(linkedList -> head, linkedList -> size);
	return node -> value;
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
