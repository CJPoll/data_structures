#include "stack.h"

int
main () {
	printf("It's working\n");

	return 0;
}

Stack *
createStack() {
	Stack *stack = (Stack *)malloc(sizeof(struct Stack));
	return stack;
}

Stack *
push(Stack *stack, void *value) {
	LinkedList *linkedList = stack -> linkedList;
	pushValue(linkedList, value);
	return stack;
}

void *
popStack(Stack *stack) {
	LinkedList *linkedList = stack -> linkedList;
	void *value = pop(linkedList);
	return value;
}

void *
peekStack(Stack *stack) {
	LinkedList *linkedList = stack -> linkedList;
	int size = linkedList -> size;
	void *value = getValue(linkedList, size);
	return value;
}

Stack *
flush(Stack *stack) {
	LinkedList *linkedList = stack -> linkedList;

	while (linkedList -> size > 0) {
		removeValue(linkedList, 1);
	}

	return stack;
}

int
size(Stack *stack) {
	return stack -> linkedList -> size;
}

bool 
isEmpty(Stack *stack) {
	return size(stack) == 0;
}

