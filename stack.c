#include "stack.h"



//Stack* stack;
/*
Stack* __initStack() {
    stack = (Stack*) calloc(1, sizeof(Stack));

    return stack;
}*/

bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

Stack* createStack() {
    return (Stack*) calloc(1, sizeof(Stack));
}

void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is currently empty.\n");
        return;
    }

    printf("Stack:\n");
    printListNEWLINE(stack->top);
}

void push(Stack* stack, void* item) {
    stack->top = createNode(item, stack->top);
}

void* pop(Stack* stack) {
    void* data = stack->top->data;
    LinkedListNode* new_top = stack->top->next;

    free(stack->top);

    stack->top = new_top;

    return data;
}

void* top(Stack* stack) {
    return stack->top->data;
}

int clearStack(Stack* stack) {
    if (stack == NULL) return 0;

    while (stack->top != NULL) {
        free(pop(stack));
    }

    return 1;
}