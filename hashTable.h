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

extern void __killMotherload();
extern HashTable* initiateHashTable(unsigned long capacity);
extern void updateKey(unsigned long hash, void* key, void* value);
extern void insertKey(HashTable** table_in_use, void* key, void* value);
extern int deleteKey(HashTable** table_in_use, void* key);
extern void* getValue(void* key);
extern void printIntValue(void* key);
extern void printIntValue(void* key);
extern void printKeys();
extern void printNodes(HTNode* head);
extern void printTable();

#endif