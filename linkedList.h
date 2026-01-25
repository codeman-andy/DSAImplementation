#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define NODE_NOT_FOUND 0
#define LL_SUCCESS 1
#define LL_ERROR 0

typedef struct LinkedListNode {
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;

/*
*data: Data to be stored in the node
*next: The next node it points to in the Linked List

Returns a pointer to the newly-created Linked List Node.
*/
extern LinkedListNode* createNode(void* data, LinkedListNode* next);

/*
*data: Data to be stored in the node

Returns a pointer to the newly-created Linked List.
*/
extern LinkedListNode* initializeList(void* data);

/*
**head: Address of the head-node of a Linked List
*data: Data to be stored in the node

Creates a Linked List Node to store the *data in, and then appends it to the end of the Linked List.
The address of the head-node is passed in case the Linked List is initially empty.
*/
extern void appendNode(LinkedListNode** head, void* data);

/*
**head: Address of the head-node of a Linked List
*data: Data to be stored in the node
index: Position to insert the node in

Creates a Linked List Node to store the *data in, and then places it at the desired index in a Linked List.
*/
extern void insertNode(LinkedListNode* head, void* data, int index);

/*
**head: Address of the head-node of a Linked List
*data: The data stored at the node that is to be deleted

Tries to find the node in a Linked List with the requested *data and then deletes it from the Linked List, bridging its neighbouring nodes together.
*/
extern int deleteNode(LinkedListNode** head, void* data);

/*
Prints a Linked List in a single-line manner.
*/
extern void printList(LinkedListNode* head);

/*
Prints a Linked List, prompting a new-line after each node is printed.
*/
extern void printListNEWLINE(LinkedListNode* head);

/*
**head: Address of the head-node of a Linked List

Reverses a Linked List.
*/
extern int reverseList(LinkedListNode** head);

/*
**head: Address of the head-node of a Linked List

Reverses a Linked List using recursion.
*/
extern void reverseListRECURR(LinkedListNode* head, LinkedListNode** headPtr);

/*
**head: Address of the head-node of a Linked List

Wipes out a Linked List from memory.
*/
extern int killList(LinkedListNode** head);

#endif