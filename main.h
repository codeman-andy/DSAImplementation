#ifndef MAIN_H
#define MAIN_H

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

typedef struct Structure {
    char* name;
    void* head;
} Structure;

#endif