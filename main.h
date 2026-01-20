#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarySearchTree.h"
#include "hashTable.h"
#include "linkedList.h"
#include "stack.h"

#define ERROR 0
#define SUCCESS 1

#define LINKED_LIST 1
#define ADD 1
#define DELETE 2
#define REVERSE 3
#define PRINT 4
#define KILL 9
#define EXIT 0

#define BSTREE 2
#define FIND_MIN 3
#define FIND_MAX 4
#define FIND_HEIGHT 5
#define LEVEL_ORDER 6

#define HASH_TABLE 3
#define PRINT_KEY 3
#define PRINT_TABLE 4

#define STACK 4
#define PUSH 1
#define POP 2
#define TOP 3
#define PRINT_STACK 4

#define FETCH_STRUCTURE 5

typedef struct Structure {
    char* name;
    size_t type;
    void* head;
} Structure;

#endif