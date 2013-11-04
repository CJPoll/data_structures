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
LinkedList *
createLinkedList();

LinkedList *
insertList(LinkedList *linkedList, void *value, int position);

LinkedList *
pushTailList(LinkedList *linkedList, void *value);

LinkedList *
pushHeadList(LinkedList *linkedList, void *value);

void *
retrieveList(LinkedList *linkedList, int position);

LinkedList *
removeList(LinkedList *linkedList, int position);

void *
popTailList(LinkedList *linkedList);

void *
popHeadList(LinkedList *linkedList);

void *
peekTailList(LinkedList *linkedList);

void *
peekHeadList(LinkedList *linkedList);


/*
 * Private API
 */
struct Node *traverseList(struct Node *node, const int position);

#endif
