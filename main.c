#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarySearchTree.h"
#include "hashTable.h"
#include "linkedList.h"
#include "stack.h"
#include "main.h"

int input;
Structure* structure;
LinkedListNode* user_structures;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

Structure* getStructure() {
    LinkedListNode* navigator = user_structures;
    size_t index = 1;
    while(index != input) {
        navigator = navigator->next;
        index++;
    }

    return navigator->data;
}

void printStructures() {
    LinkedListNode* navigator = user_structures;
    int index = 1;
    while(navigator != NULL) {
        Structure* current = (Structure*) navigator->data;
        printf("%d. %s   ", index, current->name);
        navigator = navigator->next;
        index++;
    }
    printf("\n");
}

int interpretAction(int command) {
    if (command == EXIT) return EXIT;

    if (command > 9) {
        printf("Invalid command. Please try again.\n");
        return 1;
    }

    if (structure->type == LINKED_LIST) {
        int data;
        if (command == ADD) {
            int* data = (int*) calloc(1, sizeof(int));
            printf("What do you want to add?\n");
            scanf("%d", data);
            appendNode(&(structure->head), data);
            printf("List:");
            printList(structure->head);
        }
        if (command == DELETE) {
            printf("Which entry would you like to delete?\n");
            printf("List:");
            printList(structure->head);
            scanf("%d", &data);
            if (deleteNode(&(structure->head), &data)) printf("Entry successfully deleted!\n");
            else printf("The value you were trying to delete does not exist.\n");
        }
        if (command == REVERSE) {
            printf("List:");
            printList(structure->head);
            reverseList(&structure->head);
            printf("Has become...\n");
            printf("List:");
            printList((structure->head));
        }
        if (command == PRINT) {
            printf("List:");
            printList(structure->head);
        }
        if (command == KILL) {
            if (killList(&(structure->head))) printf("The list has been successfully deleted.\n");
            else printf("There was an error while attempting to delete the list.\n");
            return EXIT;
        }
        
    }

    if (structure->type == BSTREE) {
        int data;
        if (command == ADD) {
            int* data = (int*) calloc(1, sizeof(int));
            printf("What do you want to add?\n");
            scanf("%d", data);
            BSTreeNode** headPtr = (BSTreeNode**) &(structure->head);
            insertBSTreeNode(headPtr, data);
            printLevelOrder(structure->head);
        }
        if (command == DELETE) {
            printf("Which entry would you like to delete?\n");
            printLevelOrder(structure->head);
            scanf("%d", &data);
            if (deleteBSTNode(&(structure->head), &data)) printf("The entry has been successfully deleted!\n");
            else printf("The entry you were trying to delete does not exist.\n");
        }
        if (command == FIND_MIN) {
            BSTreeNode* min = FindMin(structure->head);
            printf("The minimum value in the tree is currently %d.\n", *((int*) min->data));
        }
        if (command == FIND_MAX) {
            BSTreeNode* max = FindMax(structure->head);
            printf("The maximum value in the tree is currently %d.\n", *((int*) max->data));
        }
        if (command == FIND_HEIGHT) {
            int height = FindHeight(structure->head);
            printf("The tree's current height is %d.\n", height);
        }
        if (command == LEVEL_ORDER) {
            printLevelOrder(structure->head);
        }
        if (command == KILL) {
            if (killBSTree(&(structure->head))) printf ("The binary search tree has been successfully deleted!\n");
            else printf("There was an error while attempting to delete your binary search tree.\n");
            return EXIT;
        }

    }

    if (structure->type == HASH_TABLE) {
        int data;
        if (command == ADD) {
            int* key = (int*) calloc(1, sizeof(int));
            printf("Insert key: ");
            scanf("%d", key);
            int* value = (int*) calloc(1, sizeof(int));
            printf("Insert value: ");
            scanf("%d", value);
            insertKey(&(structure->head), key, value);
        }
        if (command == DELETE) {
            printf("Which key would you like to delete?\n");
            printKeys();
            scanf("%d", &data);
            if (deleteKey(&(structure->head), &data)) printf("The entry has been successfully deleted!\n");
            else printf("The entry you were trying to delete does not exist.\n");
        }
        if (command == PRINT_KEY) {
            printf("Which key would you like to print out?\n");
            printKeys();
            scanf("%d", &data);
            printIntValue(&data);
        }
        if (command == PRINT_TABLE) {
            printTable();
        }
        if (command == KILL) {
            __killMotherload();
            printf("The hash table has been deleted.\n");
            return EXIT;
        }
    }

    if (structure->type == STACK) {
        int data;
        if (command == PUSH) {
            int* data = (int*) calloc(1, sizeof(int));
            printf("What do you want to add?\n");
            scanf("%d", data);
            push(structure->head, data);
            printStack(structure->head);
        }
        if (command == POP) {
            pop(structure->head);
            printStack(structure->head);
        }
        if (command == TOP) {
            data = *((int*) top(structure->head));
            printf("The top element on the stack is: %d\n", data);
        }
        if (command == PRINT_STACK) {
            printStack(structure->head);
        }
        if (command == KILL) {
            if (clearStack(structure->head)) printf("The stack has been successfully deleted.\n");
            else printf("There was an error when attempting to delete the stack.\n");
        }
    }

    return 1;
}

int actionsHashTable() {
    char* ask_for_input = "What would you like to do with your Hash Table?\n";
    char* choices = "1. Add a key-value pair\n2. Delete a key\n3. Print a key\n4. Print full table\n9. Delete the hash table\n0. Exit\n";
    printf(ask_for_input);
    printf(choices);
    scanf("%d", &input);
    while (interpretAction(input)) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }
    return 0;
}

int actionsBSTree() {
    char* ask_for_input = "What would you like to do with your Binary Search Tree?\n";
    char* choices = "1. Add a node\n2. Delete a node\n3. Find minimum value\n4. Find maximum value\n5. Find tree height\n6. Perform a level-order print\n9. Delete the tree\n0. Exit\n";
    printf(ask_for_input);
    printf(choices);
    scanf("%d", &input);
    while (interpretAction(input)) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }
    return 0;
}

int actionsLinkedList() {
    char* ask_for_input = "What would you like to do with your Linked List?\n";
    char* choices = "1. Add a node\n2. Delete a node\n3. Reverse the order\n4. Print the list\n9. Delete the list\n0. Exit\n";
    printf(ask_for_input);
    printf(choices);
    scanf("%d", &input);
    while (interpretAction(input)) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }
    return 0;
}

int actionsStack() {
    char* ask_for_input = "What would you like to do with your Stack?\n";
    char* choices = "1. Push\n2. Pop\n3. Top\n4. Print\n9. Delete the stack\n0. Exit\n";
    printf(ask_for_input);
    printf(choices);
    scanf("%d", &input);
    while (interpretAction(input)) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }
    return 0;
}

void actions() {
    if (input == LINKED_LIST) {
        actionsLinkedList();
    }

    if (input == BSTREE) {
        actionsBSTree();
    }

    if (input == HASH_TABLE) {
        actionsHashTable();
    }

    if (input == STACK) {
        actionsStack();
    }
}

int interpreter() {
    if (input == EXIT) return EXIT;

    if (input == PRINT_STRUCTURES) {
        printf("Currently active structures are:\n");
        printStructures();
        printf("Which structure would you like to choose? (Choose an index)\n");
        scanf("%d", &input);
        if (input == EXIT) return EXIT;
        structure = getStructure();
        input = structure->type;
        actions();
        return 1;
    }

    char name[256];
    
    clear_buffer();
    printf("Enter a name for this structure: ");
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = 0; // Removes the new-line character from the Name

    //head = initializeList(&name); // Why does passing only "name" makes the compiler interpret it as an integer without a cast, but in the initialize function itself it becomes a char?
    structure = (Structure*) calloc(1, strlen(name) + sizeof(size_t) + 4);
    structure->name = (char*) calloc(1, strlen(name));
    memcpy(structure->name, name, strlen(name));

    appendNode(&user_structures, structure);

    if (input == LINKED_LIST) {
        structure->type = LINKED_LIST;
        actionsLinkedList();
    }

    if (input == BSTREE) {
        structure->type = BSTREE;
        actionsBSTree();
    }

    if (input == HASH_TABLE) {
        structure->type = HASH_TABLE;
        unsigned long capacity;
        printf("How much should the capacity be for your hash table structure?\n");
        scanf("%lu", &capacity);
        structure->head = initiateHashTable(capacity);
        actionsHashTable();
    }

    if (input == STACK) {
        structure->type = STACK;
        structure->head = createStack();
        actionsStack();
    }

    return 1;
}

int main() {
    printf("Address of Input before definition: %p\n", &input);
    //input = (int*) calloc(1, sizeof(int));
    printf("Address of Input after definition: %p\n", &input);
    printf("Hello! Welcome to my Data Structures and Algorithms implementation.\n");
    char* ask_for_input = "Which data structure would you like to build?\n";
    printf(ask_for_input);
    char* choices = "1. Linked List\n2. Binary Search Tree\n3. Hash Table\n4. Stack\n5. Print structures in-memory\n0. Exit\n";
    printf(choices);
    //fgets(input, sizeof(int), stdin);
    scanf("%d", &input);
    while (interpreter()) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }

    printf("Thank you for demo-ing my DSA implementation! Hope to talk to you soon!\nGoodbye!");

    return EXIT;
}