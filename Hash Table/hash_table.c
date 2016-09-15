#include "hash_tables.h"

struct element
{
	int key;
	int value;
};

struct hashTable
{
	Element *table[11];
};

int hash_function(int key)
{
	return key%11;
}

Hashtable* create_hash_table()
{
	Hashtable *ht =	(Hashtable*)malloc(sizeof(Hashtable));
	int i;
	for (i = 0; i < 11; i++)
	{
		ht->table[i] = NULL;
	}
	return ht;
}

void put(Hashtable *ht, int key, int value)
{
	int h = hash_function(key);
	while (ht->table[h] != NULL)
	{
		if (ht->table[h]->key == key)
		{
			ht->table[h]->value = value;
			break;
		}
		h = (h + 1) % 11;
	}
	if (ht->table[h] == NULL)
	{
		Element *new_element = (Element*) malloc(sizeof(Element));
		new_element->key = key;
		new_element->value = value;
		ht->table[h] = new_element;
	}
}

int get(Hashtable *ht, int key)
{
	int h;
	h = hash_function(key);
	while (ht->table[h] != NULL)
	{
		if (ht->table[h]->key == key)
		{
			return ht->table[h]->value;
		}

		h = (h + 1) % 11;
	}
	return -100;
}

void Remove(Hashtable *ht, int key)
{
	int h;
	h = hash_function(key);
	
	while (ht->table[h] != NULL)
	{
		if (ht->table[h]->key == key)
		{
			ht->table[h] = NULL;
			ht->table[h]->key = -1;
		}
		h = (h+1)%11;
	}
}

int main()
{
	Hashtable *ht = create_hash_table();
	put(ht, 3, 1000);
	put(ht, 14, 2000);
	put(ht, 15, 3000);
	put(ht, 92, 4000);

	return 0;
}