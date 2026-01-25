#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
  void* items[128];
  int front;
  int rear;
} Queue;

/*
Places an item at the tail of a Queue.
*/
extern void Enqueue(Queue* queue, void* item);

/*
Removes the element at the front of a Queue.
*/
extern void Dequeue(Queue* queue);

#endif