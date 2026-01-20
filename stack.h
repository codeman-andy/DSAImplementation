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
Returns true if the Stack is empty, false otherwise.
*/
extern bool isEmpty(Stack* stack);

/*
*stack: Pointer to a Stack

Prints the Stack in a top-to-bottom manner.
*/
extern void printStack(Stack* stack);

/*
*stack: Pointer to a Stack
*item: Pointer to store on the Stack

Pushes pointer to an item to the Stack
*/
extern void push(Stack* stack, void* item);

/*
*stack: Pointer to a Stack

Pops pointer at the top of the Stack and returns it.
*/
extern void* pop(Stack* stack);

/*
*stack: Pointer to a Stack

Returns pointer at the top of the Stack.
*/
extern void* top(Stack* stack);

/*
*stack: Pointer to a Stack

Empties the Stack.
*/
extern int clearStack(Stack* stack);

#endif