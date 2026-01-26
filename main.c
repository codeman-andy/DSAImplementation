#include "main.h"

int input;
Structure* structure;
LinkedListNode* user_structures;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void createStructure() {
    char name[256];
    
    clear_buffer();
    printf("Enter a name for this structure: ");
    fgets(name, 256, stdin);
    name[strcspn(name, "\n")] = 0; // Removes the new-line character from the Name

    //head = initializeList(&name); // Why does passing only "name" makes the compiler interpret it as an integer without a cast, but in the initialize function itself it becomes a char?
    structure = (Structure*) calloc(1, strlen(name) + sizeof(size_t) + 4);
    structure->name = (char*) calloc(1, strlen(name));
    memcpy(structure->name, name, strlen(name));
    structure->type = input;

    appendNode(&user_structures, structure);

    if (structure->type == HASH_TABLE) {
        unsigned long capacity;
        printf("What is the capacity for your hash table structure?\n");
        scanf("%lu", &capacity);
        structure->head = initiateHashTable(capacity);
    }

    if (structure->type == STACK) {
        structure->head = createStack();
    }
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

int deleteStructure() {
    if (!deleteNode(&user_structures, structure)) return ERROR;
    free(structure);
    structure = NULL;
    return SUCCESS;
}

void printStructures() {
    LinkedListNode* navigator = user_structures;

    printf("Currently active structures are:\n");

    int index = 1;
    while(navigator != NULL) {
        Structure* current = (Structure*) navigator->data;
        printf("%d. %s   ", index, current->name);
        navigator = navigator->next;
        index++;
    }
    printf("0. Exit\n");
}

int fetchStructure() {
    printStructures();
    printf("Which structure would you like to choose? (Choose index)\n");
    scanf("%d", &input);
    if (input == EXIT) return EXIT;
    structure = getStructure();
    return SUCCESS;
}

int interpretAction(int command) {
    if (command == EXIT) return EXIT;

    if (structure->type == LINKED_LIST) {
        LinkedListNode** linked_list_address = (LinkedListNode**) &(structure->head);

        switch (command) {
        case ADD:
            printf("What do you want to add?\n");
            int* data = (int*) calloc(1, sizeof(int));
            scanf("%d", data);
            appendNode(linked_list_address, data);
            printf("List:");
            printList(structure->head);
            break;

        case DELETE:
            printf("Which entry would you like to delete?\n");
            printf("List:");
            printList(structure->head);
            int entry;
            scanf("%d", &entry);
            if (deleteNode(linked_list_address, &entry)) printf("Entry successfully deleted!\n");
            else printf("The value you were trying to delete does not exist.\n");
            break;
        
        case REVERSE:
            printf("List:");
            printList(structure->head);
            reverseList(linked_list_address);
            printf("Has become...\n");
            printf("List:");
            printList((structure->head));
            break;
        
        case PRINT:
            printf("List:");
            printList(structure->head);
            break;
        
        case KILL:
            if (killList(linked_list_address) && deleteStructure()) printf("The list has been successfully deleted.\n");
            else printf("There was an error while attempting to delete the list.\n");
            return EXIT;

        default:
            printf("Invalid command. Please try again.\n");
            return 1;
        }
    }

    if (structure->type == BSTREE) {
        BSTreeNode** bstree_address = (BSTreeNode**) &(structure->head);

        switch (command) {
        case ADD:
            printf("What do you want to add?\n");
            int* data = (int*) calloc(1, sizeof(int));
            scanf("%d", data);
            insertBSTreeNode(bstree_address, data);
            printLevelOrder(structure->head);
            break;

        case DELETE:
            printf("Which entry would you like to delete?\n");
            printLevelOrder(structure->head);
            int entry;
            scanf("%d", &entry);
            if (deleteBSTNode(bstree_address, &entry)) printf("The entry has been successfully deleted!\n");
            else printf("The entry you were trying to delete does not exist.\n");
            break;

        case FIND_MIN:
            printf("The minimum value in the tree is currently ");
            BSTreeNode* min = FindMin(structure->head);
            printf("%d.\n", *((int*) min->data));
            break;

        case FIND_MAX:
            printf("The maximum value in the tree is currently ");
            BSTreeNode* max = FindMax(structure->head);
            printf("%d.\n", *((int*) max->data));
            break;

        case FIND_HEIGHT:
            printf("The tree's current height is ");
            int height = FindHeight(structure->head);
            printf("%d.\n", height);
            break;

        case LEVEL_ORDER:
            printLevelOrder(structure->head);
            break;

        case KILL:
            if (killBSTree(bstree_address) && deleteStructure()) printf ("The binary search tree has been successfully deleted!\n");
            else printf("There was an error while attempting to delete your binary search tree.\n");
            return EXIT;

        default:
            printf("Invalid command. Please try again.\n");
            return 1;
        }
    }

    if (structure->type == HASH_TABLE) {
        HashTable** ht_address = (HashTable**) &(structure->head);

        switch (command) {
        case ADD:
            printf("Insert key: ");
            int* key = (int*) calloc(1, sizeof(int));
            scanf("%d", key);
            printf("Insert value: ");
            int* value = (int*) calloc(1, sizeof(int));
            scanf("%d", value);
            insertKey(ht_address, key, value);
            break;

        case DELETE:
            printf("Which key would you like to delete?\n");
            printKeys();
            int data;
            scanf("%d", &data);
            if (deleteKey(ht_address, &data)) printf("The entry has been successfully deleted!\n");
            else printf("The entry you were trying to delete does not exist.\n");
            break;

        case PRINT_KEY:
            printf("Which key would you like to print out?\n");
            printKeys();
            int selected_key;
            scanf("%d", &selected_key);
            if (!printIntValue(&selected_key)) printf("The key requested does not exist.\n");
            break;

        case PRINT_TABLE:
            printTable();
            break;

        case KILL:
            if (__killMotherload() && deleteStructure()) printf("The hash table has been deleted.\n");
            else printf("There was an error when attempting to delete the hash table.\n");
            return EXIT;

        default:
            printf("Invalid command. Please try again.\n");
            return 1;
        }
    }

    if (structure->type == STACK) {
        switch (command) {
        case PUSH:
            printf("What do you want to add?\n");
            int* data = (int*) calloc(1, sizeof(int));
            scanf("%d", data);
            push(structure->head, data);
            printStack(structure->head);
            break;

        case POP:
            pop(structure->head);
            printStack(structure->head);
            break;

        case TOP:
            printf("The top element on the stack is: ");
            int top_of_stack = *((int*) top(structure->head));
            printf("%d\n", top_of_stack);
            break;

        case PRINT_STACK:
            printStack(structure->head);
            break;

        case KILL:
            if (clearStack(structure->head) && deleteStructure()) printf("The stack has been successfully deleted.\n");
            else printf("There was an error when attempting to delete the stack.\n");
            return EXIT;

        default:
            printf("Invalid command. Please try again.\n");
            return 1;
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
    switch (structure->type) {
    case LINKED_LIST:
        actionsLinkedList();
        break;

    case BSTREE:
        actionsBSTree();
        break;

    case HASH_TABLE:
        actionsHashTable();
        break;

    case STACK:
        actionsStack();
        break;
    }
}

int interpreter() {
    switch (input) {
    case EXIT: return EXIT;

    case FETCH_STRUCTURE:
        if (fetchStructure() == EXIT) return 1;
        actions();
        return 1;
    
    default:
        createStructure();
        actions();
        return 1;
    }
}

int main() {
    printf("Address of Input before definition: %p\n", &input);
    printf("Address of Input after definition: %p\n", &input);
    printf("Hello! Welcome to my Data Structures and Algorithms implementation.\n");
    char* ask_for_input = "Which data structure would you like to build?\n";
    printf(ask_for_input);
    char* choices = "1. Linked List\n2. Binary Search Tree\n3. Hash Table\n4. Stack\n5. Choose a structure in-memory\n0. Exit\n";
    printf(choices);
    scanf("%d", &input);
    while(interpreter()) {
        printf(ask_for_input);
        printf(choices);
        scanf("%d", &input);
    }

    printf("Thank you for demo-ing my DSA implementation! Hope to talk to you soon!\nGoodbye!");

    return EXIT;
}