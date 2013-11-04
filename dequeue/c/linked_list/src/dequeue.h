#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct Dequeue Dequeue;

Dequeue *createDequeue();
Dequeue *enqueueFrontDequeue(Dequeue *dequeue, void *value);
Dequeue *enqueueBackDequeue(Dequeue *dequeue, void *value);

void *dequeueFrontDequeue(Dequeue *dequeue);
void *dequeueBackDequeue(Dequeue *dequeue);

int sizeDequeue(Dequeue *dequeue);

#endif
