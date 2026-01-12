typedef struct Queue {
  void* items[128];
  int front;
  int rear;
} Queue;

extern void Enqueue(Queue* queue, void* item);
extern void Dequeue(Queue* queue);