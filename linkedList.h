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
    *data: Data to be inserted in the Node;
    *next: Reference to the next Node in the Linked List;
*/
extern LinkedListNode* createNode(void* data, LinkedListNode* next);
extern LinkedListNode* initializeList(void* data);
extern void appendNode(LinkedListNode** head, void* data);
extern void insertNode(LinkedListNode* head, void* data, int index);
extern int deleteNode(LinkedListNode** head, void* data);
extern void printList(LinkedListNode* head);
extern void printListNEWLINE(LinkedListNode* head);
extern int reverseList(LinkedListNode** head);
extern void reverseListRECURR(LinkedListNode* head, LinkedListNode** headPtr);
extern int killList(LinkedListNode** head);

#endif