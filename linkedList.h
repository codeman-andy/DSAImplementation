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
*data: Data to be stored in the Node
*next: Pointer to the next Node in the Linked List

Returns a pointer to the newly-created Linked List Node.
*/
extern LinkedListNode* createNode(void* data, LinkedListNode* next);

/*
*data: Pointer to be stored in the Node

Returns a pointer to the newly-created Linked List.
*/
extern LinkedListNode* initializeList(void* data);

/*
**head: Address of the head-node of a Linked List
*data: Pointer to be stored in the Node

Creates a new Linked List Node to store the *data in, and then appends it to the end of the Linked List.
The address of the head-node is passed in case the Linked List is empty.
*/
extern void appendNode(LinkedListNode** head, void* data);

/*
**head: Address of the head-node of a Linked List
*data: Pointer to be stored in the Node
index: Position in which the new Node will be inserted

Creates a new Linked List Node to store the *data in, and then places it at the desired index in the Linked List.
*/
extern void insertNode(LinkedListNode* head, void* data, int index);

/*
**head: Address of the head-node of a Linked List
*data: The pointer stored at the Node that is to be deleted

Tries to find a Node in the Linked List with the requested *data and then deletes it from the Linked List, bridging the neighbouring Nodes together.
*/
extern int deleteNode(LinkedListNode** head, void* data);

/*
*head: Pointer to the head of the Linked List

Prints the Linked List in a single-line manner.
*/
extern void printList(LinkedListNode* head);

/*
*head: Pointer to the head of the Linked List

Prints the Linked List, prompting a new-line after each Node.
*/
extern void printListNEWLINE(LinkedListNode* head);

/*
**head: Address of the head-node of a Linked List

Reverses the Linked List.
*/
extern int reverseList(LinkedListNode** head);

/*
**head: Address of the head-node of a Linked List

Reverses the Linked List using recursion.
*/
extern void reverseListRECURR(LinkedListNode* head, LinkedListNode** headPtr);

/*
**head: Address of the head-node of a Linked List

Wipes out the Linked List from memory.
*/
extern int killList(LinkedListNode** head);

#endif