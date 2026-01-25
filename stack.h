#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

typedef struct Stack {
    LinkedListNode* top;
} Stack;

/*
Returns a pointer to the newly-created Stack.
*/
extern Stack* createStack();

/*
Returns true if a Stack is empty, false otherwise.
*/
extern bool isEmpty(Stack* stack);

/*
Prints a Stack in a top-to-bottom manner.
*/
extern void printStack(Stack* stack);

/*
Pushes an item to the top of a Stack.
*/
extern void push(Stack* stack, void* item);

/*
Pops item at the top of a Stack and returns it.
*/
extern void* pop(Stack* stack);

/*
Returns item at the top of a Stack.
*/
extern void* top(Stack* stack);

/*
Empties out a Stack.
*/
extern int clearStack(Stack* stack);

#endif