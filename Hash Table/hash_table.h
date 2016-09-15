#include<stdio.h>
#include<stdlib.h>

typedef struct element Element;

typedef struct hashTable Hashtable;

int hash_function(int key);

Hashtable* create_hash_table();

void put(Hashtable *ht, int key, int value);

int get(Hashtable *ht, int key);

void Remove(Hashtable *ht, int key);

int contains_key(Hashtable *ht, int key);

void print_hash_table(Hashtable *ht);