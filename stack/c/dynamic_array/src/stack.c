#include "stack.h"

stack *
stackCreate() {
	stack *stack = malloc(sizeof(stack));
	stack -> array = arrayCreate();
	stack -> size = 0;
	return stack;
}

stack *
stackPush(stack *stack, void *value) {
	arrayPushTail(stack -> array, value);
	stack -> size = stack -> array -> size;
	return stack;
}

void *
stackPop(stack *stack) {
	void *value = arrayPopTail(stack -> array);
	stack -> size = stack -> array -> size;
	return value;
}

void *
stackPeek(stack *stack) {
	if (stack -> size == 0 || stack == NULL) {
		return NULL;
	}

	return arrayPeekTail(stack -> array);
}

stack *
stackFlush(stack *stack) {
	if (stack -> size == 0 || stack == NULL) {
		return stack;
	}

	while (stack -> size > 0) {
		stackPop(stack);
	}

	return stack;
}
