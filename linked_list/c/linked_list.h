#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

// What should this file do?
// Linked list (singly)

struct Node {
	struct Node *next;
	void *value;
};

typedef struct LinkedList {
	struct Node *head;
	struct Node *tail;
	int size;
} LinkedList;

/*
 * Public API
 */
LinkedList *createLinkedList();
LinkedList *insertValue(LinkedList *linkedList, void *value, int position);
LinkedList *pushValue(LinkedList *linkedList, void *value);
void *getValue(LinkedList *linkedList, int position);
LinkedList *removeValue(LinkedList *linkedList, int position);
void *pop(LinkedList *linkedList);

/*
 * Private API
 */
struct Node *traverseList(struct Node *node, const int position);

#endif
