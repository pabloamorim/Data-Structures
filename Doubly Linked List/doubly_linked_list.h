#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

Node* create_doubly_linkedList();

int is_empty(Node *first);

Node* insert_node(Node *first, int item);

void print_doubly_linked_list_backward(Node *last);

