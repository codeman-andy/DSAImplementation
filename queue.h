#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
  void* items[128];
  int front;
  int rear;
} Queue;

/*
*queue: Pointer to a Queue
*item: Pointer to add to the Queue

Places a new pointer at the tail of the Queue.
*/
extern void Enqueue(Queue* queue, void* item);

/*
*queue: The pointer to a Queue

Takes out the first element from the Queue.
*/
extern void Dequeue(Queue* queue);

#endif