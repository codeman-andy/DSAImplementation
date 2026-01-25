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
hash: The key's correspondent hash
*key: The key requested
*value: The new value to update the key with

Looks through the nodes at the given hash on the table until it finds the one containing the key.
It then updates its value with the given input.
*/
extern void updateKey(unsigned long hash, void* key, void* value);

/*
**table_in_use: Address to the currently active Hash Table
*key: The key value for the node
*value: The value to be stored in the node

Checks if the key already exists on the Hash Table and, if yes, updates its value.
Otherwise, creates a new node, calculates an hash for it and then stores the key and value in it.
*/
extern void insertKey(HashTable** table_in_use, void* key, void* value);

/*
**table_in_use: Address to the currently active Hash Table
*key: The requested key to be deleted

Checks to see if the key exists on the Hash Table and, if yes, removes it.
*/
extern int deleteKey(HashTable** table_in_use, void* key);

/*
*key: The requested key

Returns a pointer to the value stored with the requested key.
*/
extern void* getValue(void* key);

/*
*key: The requested key

Converts the value-pointer to an INT-pointer and then prints it.
*/
extern void printIntValue(void* key);

/*
Prints all the keys currently stored on the Hash Table.
*/
extern void printKeys();

/*
Prints all the key-value pairs currently stored on the Hash Table.
*/
extern void printTable();

#endif