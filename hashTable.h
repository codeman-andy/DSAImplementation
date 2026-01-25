#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HT_ERROR -1
#define HT_SUCCESS 1
#define HT_NOT_FOUND 0

#define NOT_FOUND NULL

#define UNSIGNED_LONG_OVERFLOW NULL

typedef struct HTNode {
    void* key;
    void* value;
    struct HTNode* next;
} HTNode;

typedef struct HashTable {
    int num_keys;
    int offset;
    HTNode** nodes;
    struct HashTable* next;
} HashTable;

/*
capacity: The length for the table

Returns a pointer to the newly-created Hash Table.
*/
extern HashTable* initiateHashTable(unsigned long capacity);

/*
Looks through the nodes at the given hash on the table until it finds the one containing the key.
It then updates its value.
*/
extern void updateKey(unsigned long hash, void* key, void* value);

/*
**table_in_use: Address to a Hash Table

Checks if the key already exists on a Hash Table and, if yes, updates its value.
Otherwise, creates a new node, calculates an hash for it, and then stores the key and value in it.
*/
extern void insertKey(HashTable** table_in_use, void* key, void* value);

/*
**table_in_use: Address to a Hash Table

Checks to see if the key exists on the Hash Table and, if yes, removes it.
*/
extern int deleteKey(HashTable** table_in_use, void* key);

/*
Returns a the value stored on the requested key.
*/
extern void* getValue(void* key);

/*
Converts a value-pointer to an INT-pointer and then prints it.
*/
extern void printIntValue(void* key);

/*
Prints all the keys currently stored.
*/
extern void printKeys();

/*
Prints all the key-value pairs currently stored.
*/
extern void printTable();

#endif