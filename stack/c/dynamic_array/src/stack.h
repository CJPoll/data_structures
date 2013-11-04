#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

typedef struct stack {
	array *array;
	int size;
} stack;

stack *
stackCreate();

stack *
stackPush(stack *stack, void *value);

void *
stackPop(stack *stack);

void *
stackPeek(stack *stack);

stack *
stackFlush(stack *stack);

#endif
