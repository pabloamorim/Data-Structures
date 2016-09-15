#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

typedef struct stack Stack;

Stack* create_stack();

int is_empty(Stack *stack);

void push(Stack *stack, int item);

int pop(Stack *stack);

int peek(Stack *stack);

