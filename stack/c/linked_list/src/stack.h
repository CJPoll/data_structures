#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef int bool;
#define true 1
#define false 0

typedef struct Stack {
	LinkedList *linkedList;
} Stack;

Stack *createStack();
Stack *pushStack(Stack *stack, void *value);
void  *popStack(Stack *stack);
void *peekStack(Stack *stack);
Stack *flushStack(Stack *stack);
int size(Stack *stack);
bool isEmpty(Stack *stack);
int main();

#endif
