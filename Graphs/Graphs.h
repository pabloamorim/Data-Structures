#include <stdio.h>
#include <stdlib.h>
#define MAX_GRAPH_SIZE 50
#define MAX_QUEUE_SIZE 50

typedef struct adj_list AdjList;

typedef struct graph Graph;

typedef struct queue Queue;

Graph* create_graph();

void add_edge(Graph *graph, int vertexX, int vertexY);

void print_graph(Graph *graph);

void depth_first_search(Graph *graph, int source);

void breadth_first_search(Graph *graph, int source);

Queue* create_queue();

int is_empty(Queue *queue);

void enqueue(Queue *queue, int item);

int dequeue(Queue *queue);