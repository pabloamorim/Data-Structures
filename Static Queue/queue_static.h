#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue Queue;

Queue* create_queue();

void enqueue(Queue *queue, int item);

int dequeue(Queue *queue);

int is_empty(Queue *queue);