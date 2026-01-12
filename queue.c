#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Enqueue(Queue *queue, void *item) {
	if (queue->front == -1 && queue->rear == -1) {
		queue->front = queue->rear = 0;
	} else if ((queue->rear + 1) == 128) {
		printf("Memory Full\n"); exit(1);
	} else {
		queue->rear = (queue->rear + 1);
	}
	queue->items[queue->rear] = item;
}

void Dequeue(Queue *queue) {
	if (queue->front == -1 && queue->rear == -1) return;
	if ((queue->front + 1) > queue->rear) {
		queue->front = queue->rear = -1;
	} else {
		queue->front = (queue->front + 1);
	}
}