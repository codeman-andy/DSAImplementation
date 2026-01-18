#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

typedef struct Stack {
    LinkedListNode* top;
} Stack;

extern Stack* createStack();
extern bool isEmpty(Stack* stack);
extern void printStack(Stack* stack);
extern void push(Stack* stack, void* item);
extern void* pop(Stack* stack);
extern void* top(Stack* stack);
extern int clearStack(Stack* stack);

#endif