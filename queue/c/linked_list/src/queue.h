#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;

Queue *
createQueue();

Queue *
pushQueue(Queue *queue, void *value);

void *
popQueue(Queue *queue);

int
sizeQueue(Queue *queue);

Queue *
flushQueue(Queue *queue);

void
destroyQueue(Queue *queue);

#endif
