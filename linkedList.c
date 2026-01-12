#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"



LinkedListNode* createNode(void* data, LinkedListNode* next) {
    LinkedListNode* node = (LinkedListNode*) calloc(1, sizeof(LinkedListNode));
    node->data = data;
    node->next = next;
    return node;
}

LinkedListNode* initializeList(void* data) {
    return createNode(data, NULL);
}

bool __compare(void* node_data, void* data) {
    return *((int*) node_data) == *((int*) data);
}

void appendNode(LinkedListNode** head, void* data) {
    if (*head == NULL) {
        *head = initializeList(data);
        return;
    }

    LinkedListNode* navigator = *head;
    while (navigator->next != NULL) {
        navigator = navigator->next;
    }
    navigator->next = createNode(data, NULL);
}

void insertNode(LinkedListNode* head, void* data, int index) {
    int previousNode = index - 1;
    int currentNode = 0;
    while (head->next != NULL && currentNode < previousNode) {
        // head travels through the Linked List until it reaches the node
        // just before where we want to insert the new one
        head = head->next;
        currentNode += 1;
    }
    // head is pointing to the node just before where we want to insert the new one
    // so we make it point to the new one, and make the new one point to where head is currently pointing
    head->next = createNode(data, head->next);
}

int deleteNode(LinkedListNode** head, void* data) {
    LinkedListNode* navigator = *head;
    if (__compare(navigator->data, data)) {
        *head = navigator->next;
        free(navigator);
        return LL_SUCCESS;
    }
    
    LinkedListNode* previousNode = NULL;
    while (navigator != NULL && !__compare(navigator->data, data)) {
        previousNode = navigator;
        navigator = navigator->next;
    }

    if (head == NULL) return NODE_NOT_FOUND;

    previousNode->next = navigator->next;
    free(navigator);

    return LL_SUCCESS;
}

void printList(LinkedListNode* head) {
    printf("List:");
    while (head != NULL) {
        printf(" %d", *((int*) head->data));
        head = head->next;
    }
    printf("\n");
}

int reverseList(LinkedListNode** head) {
    if (*head == NULL) return LL_ERROR;

    LinkedListNode* currentNode = *head;
    LinkedListNode* nextNode = NULL;
    LinkedListNode* previousNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    *head = previousNode;
    return LL_SUCCESS;
}

void reverseListRECURR(LinkedListNode* head, LinkedListNode** headPtr) {
    LinkedListNode* prev = head;
    head = head->next;
    if (head == NULL) {
        *headPtr = prev;
        return;
    }
    reverseListRECURR(head, headPtr);
    head->next = prev;
    prev->next = NULL;
}

int killList(LinkedListNode** head) {
    if (*head == NULL) {
        return LL_ERROR;
    }
    LinkedListNode* navigator = *head;
    LinkedListNode* next = NULL;
    
    while (navigator != NULL) {
        next = navigator->next;
        free(navigator);
        navigator = next;
    }

    *head = NULL;
    
    return LL_SUCCESS;
}

/*int main() {
    LinkedListNode* head = NULL;
    head = initializeList(1);
    appendNode(head, 2);
    appendNode(head, 6);
    insertNode(head, 4, 1);
    searchList(head);
    reverseListRECURR(head, &head);
    searchList(head);
    deleteNode(head, 4);
    searchList(head);
    destroyList(head);
}*/