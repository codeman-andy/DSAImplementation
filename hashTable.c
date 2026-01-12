#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"



typedef struct Motherload {
    HashTable* head_table;
    HashTable* tail_table;
    HashTable* free_table;
    unsigned long table_capacity;
    int total_num_tables;
    int total_num_keys;
} Motherload;

// Global variables and static variables are automatically initialized to zero
Motherload* MOTHERLOAD;

//int __hashFunction(int key, HashTable* table) {
//    float fracValue = sqrtf(0.5); // An irrational number must be used in order to avoid generating the same hash for different keys
//    int primeNumber = 257; // The value of the prime will need to be some bigger number close to a multiple of the HashTable's array length
//    int hash = table->offset + floor(primeNumber * fmodf(key * fracValue, 1));
//    return hash;
//}

unsigned long __hashFunction(unsigned char* str) {
    //           djb2 string hashing algorithm
	// Credit: sstp://www.cse.yorku.ca/~oz/hash.ssml
    unsigned long hash = 5381;
    int c;

    while (c = *str++) hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash = hash % MOTHERLOAD->table_capacity;

    return hash;
}

HTNode* __createNode(void* key, void* value) {
    HTNode* node = (HTNode*) malloc(sizeof(HTNode));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

bool __hasKey(HTNode* node, void* key){
    while (node != NULL && *((int*) node->key) != *((int*) key)) {
        node = node->next;
    }

    return node != NULL;
}

void __killNodes(HashTable* target){
    for (int i = 0; i < MOTHERLOAD->table_capacity; i++) {
        if (target->nodes[i] != NULL) {
            HTNode* node = target->nodes[i];
            while (node->next != NULL) {
                HTNode* previous = node;
                node = node->next;
                free(previous);
            }
            free(node);
        }
    }
}

bool __isFull(HashTable* table) {
    return table->num_keys == MOTHERLOAD->table_capacity * 2;
}

bool __isEmpty(HashTable* table) {
    return table->num_keys == 0;
}

bool __isHeadTable(HashTable* table) {
    return table == MOTHERLOAD->head_table;
}

bool __isTailTable(HashTable* table) {
    return table == MOTHERLOAD->tail_table;
}

HashTable* __createTable() {
    HashTable* table = (HashTable*) calloc(1, sizeof(HashTable));
    table->nodes = (HTNode**) calloc(MOTHERLOAD->table_capacity, sizeof(HTNode*));
    table->offset = MOTHERLOAD->table_capacity * MOTHERLOAD->total_num_tables;

    MOTHERLOAD->total_num_tables++;

    return table;
}

HashTable* __findTable(unsigned long hash, void* key) {
    HashTable* navigator = MOTHERLOAD->head_table;

    while (navigator != NULL && !__hasKey(navigator->nodes[hash], key)) {
        navigator = navigator->next;
    }

    if (navigator == NULL) return NOT_FOUND;

    return navigator;
}

HashTable* __setFreeTable() {
    if (!__isFull(MOTHERLOAD->head_table)) return MOTHERLOAD->head_table;

    HashTable* navigator = MOTHERLOAD->head_table;

    while (navigator->next != NULL && __isFull(navigator->next)) {
        navigator = navigator->next;
    }

    HashTable* free_table = navigator->next;

    if (navigator->next == NULL) {
        free_table = __createTable();
        // The newly-created HashTable has become the de facto tail-HashTable of the MOTHERLOAD
        MOTHERLOAD->tail_table = free_table;
    }

    MOTHERLOAD->free_table = free_table;

    return free_table;
}

void __resetTailTable() {
    HashTable* navigator = MOTHERLOAD->head_table;

    while (navigator->next != NULL) {
        navigator = navigator->next;
    }

    MOTHERLOAD->tail_table = navigator;
}

void __deleteTable(HashTable* target){
    free(target);
    MOTHERLOAD->total_num_tables--;
}

void __killTable(HashTable* target) {
    if (target == MOTHERLOAD->head_table) {
        MOTHERLOAD->head_table = MOTHERLOAD->head_table->next;
    }
    else {
        HashTable* previous = MOTHERLOAD->head_table;
        HashTable* current = MOTHERLOAD->head_table->next;
        while (current != target) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (previous->next == NULL) {
            MOTHERLOAD->tail_table = previous;
        }
    }

    if (target->num_keys != 0) {
        __killNodes(target);
    }

    __deleteTable(target);
}

bool __keyExists(unsigned long hash, void* key) {
    return __findTable(hash, key) != NOT_FOUND;
}

HashTable* __initMotherload(unsigned long capacity) {
    MOTHERLOAD = (Motherload*) calloc(1, sizeof(Motherload));
    MOTHERLOAD->table_capacity = 128;
    MOTHERLOAD->total_num_tables = 0;
    MOTHERLOAD->total_num_keys = 0;
    MOTHERLOAD->head_table = __createTable();
    MOTHERLOAD->tail_table = MOTHERLOAD->head_table;
    MOTHERLOAD->free_table = __setFreeTable();

    return MOTHERLOAD->free_table;
}

void __killMotherload() {
    if (MOTHERLOAD->head_table != MOTHERLOAD->tail_table) {
        HashTable* nextTable = MOTHERLOAD->head_table->next;
        __killTable(MOTHERLOAD->head_table);
        free(MOTHERLOAD->head_table);
        MOTHERLOAD->head_table = nextTable;
        __killMotherload();
    }
    else {
        free(MOTHERLOAD->head_table);
        free(MOTHERLOAD);
        MOTHERLOAD = NULL;
    }
}

HashTable* initiateHashTable(unsigned long capacity) {
    if (sizeof(capacity) > sizeof(unsigned long)) return UNSIGNED_LONG_OVERFLOW;

    return __initMotherload(capacity);
}

void updateKey(unsigned long hash, void* key, void* value) {
    HashTable* table = __findTable(hash, key);
    HTNode* node = table->nodes[hash];

    while (node->key != key) {
        node = node->next;
    }

    node->value = value;
}

void insertKey(HashTable** table_in_use, void* key, void* value) {
    unsigned long hash = __hashFunction(key);

    if (__keyExists(hash, key)) {
        updateKey(hash, key, value);
        return;
    }

    HashTable* free_table = MOTHERLOAD->free_table;
    
    HTNode* new_node = __createNode(key, value);

    if (free_table->nodes[hash] == NULL) {
        free_table->nodes[hash] = new_node;
    }
    else {
        HTNode* node = free_table->nodes[hash];
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }

    free_table->num_keys++;
    if (__isFull(free_table)) *table_in_use = __setFreeTable();

    MOTHERLOAD->total_num_keys++;
}

int deleteKey(HashTable** table_in_use, void* key) {
    unsigned long hash = __hashFunction(key);

    HashTable* table = __findTable(hash, key);

    if (table == NOT_FOUND) return HT_NOT_FOUND;

    if ( *((int*) table->nodes[hash]->key) == *((int*) key)) {
        HTNode* nextNode = table->nodes[hash]->next;
        free(table->nodes[hash]);
        table->nodes[hash] = nextNode;
        table->num_keys--;
        if (!__isHeadTable(table) && __isEmpty(table)) {
            __deleteTable(table);
            if (__isTailTable(table)) __resetTailTable();

            *table_in_use = __setFreeTable();
        }
    }
    else {
        HTNode* previous = table->nodes[hash];
        HTNode* current = table->nodes[hash]->next;
        while (*((int*) current->key) != *((int*) key)) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        table->num_keys--;
    }

    MOTHERLOAD->total_num_keys--;

    return HT_SUCCESS;
}

void* getValue(void* key) {
    unsigned long hash = __hashFunction(key);

    if (!__keyExists(hash, key)) return NOT_FOUND;

    HashTable* table = __findTable(hash, key);

    HTNode* node = table->nodes[hash];
    while (node->key != key) {
        node = node->next;
    }

    return node->value;
}

void printIntValue(void* key) {
    void* value = getValue(key);
    
    printf("The value for key %d is: %d\n", *((int*) key), *((int*) value));
}

void printNodesKeys(HTNode* head) {
    while (head != NULL) {
        printf(" %d", *((int*) head->key));
        head = head->next;
    }
}

void printKeys() {
    HashTable* table = MOTHERLOAD->head_table;
    printf("Current keys:");
    while (table != NULL) {
        for (int i = 0; i < MOTHERLOAD->table_capacity; i++) {
            if (table->nodes[i] != NULL) printNodesKeys(table->nodes[i]);
        }
        table = table->next;
    }
    printf("\n");
}

void printNodes(HTNode* head) {
    while (head != NULL) {
        printf("The value for key %d is: %d\n", *((int*) head->key), *((int*) head->value));
        head = head->next;
    }
}

void printTable() {
    HashTable* table = MOTHERLOAD->head_table;
    while (table != NULL) {
        for (int i = 0; i < MOTHERLOAD->table_capacity; i++) {
            if (table->nodes[i] != NULL) printNodes(table->nodes[i]);
        }
        table = table->next;
    }
}

/*
int main() {
    __initMotherload(128);
    printf("Hello!\n");
    int a = 2;
    int b = 10;
    insertKey(&a, &b);
    printf("Currently I have %d table.\n", MOTHERLOAD->total_num_tables);
    int c = 4;
    int d = 5;
    insertKey(&c, &d);
    printf("Now I have %d tables.\n", MOTHERLOAD->total_num_tables);
    int e = 0;
    int f = 1;
    insertKey(&e, &f);
    printf("Here are my values so far:\n");
    printIntValue(&a);
    printIntValue(&c);
    printIntValue(&e);
    deleteKey(&c);
    printf("I have deleted key-4.\n");
    printf("So now I have %d table.\n", MOTHERLOAD->total_num_tables);
    printf("I will now try to delete key-4 again...\n");
    deleteKey(&c);
    __killMotherload();
    printf("I have killed THE MOTHERLOAD: %p\n", MOTHERLOAD);
    printf("Goodbye!");
    return 0;
}*/