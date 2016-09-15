#include <stdio.h>
#include <stdlib.h>
#include "Graphs.h"
#define MAX_GRAPH_SIZE 50
#define MAX_QUEUE_SIZE 50

struct adj_list 
{
	int item;
	struct adj_list *next_adj_vertex;
};

AdjList* create_adj_list(int item)
{
	AdjList *adj_list = (AdjList*) malloc(sizeof(AdjList));
	adj_list->item = item;
	adj_list->next_adj_vertex = NULL;
	
	return adj_list;
}

struct graph 
{
	AdjList *vertices[MAX_GRAPH_SIZE];
	short visited[MAX_GRAPH_SIZE];
};

Graph* create_graph() 
{
	Graph *graph = (Graph*) malloc(sizeof(Graph));
	int i;
	for (i = 1; i <= MAX_GRAPH_SIZE - 1; i++) 
	{
		graph->vertices[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

//ADICIONANDO ARESTAS - addEdge + AdjList
void add_edge(Graph *graph, int vertexX, int vertexY) 
{
	AdjList *vertex = create_adj_list(vertexY);
	vertex->next_adj_vertex = graph->vertices[vertexX];
	graph->vertices[vertexX] = vertex;

//Undirected graph. Edge to the other direction as well.
	vertex = create_adj_list(vertexX);
	vertex->next_adj_vertex = graph->vertices[vertexY];
	graph->vertices[vertexY] = vertex;

}

//DFS - BUSCA EM PROFUNDIDADE (DEPTH FIRST SEARCH)
void depth_first_search(Graph *graph, int source)
{
	graph->visited[source] = 1;
	printf("%d\n", source);
	AdjList *adj_list = graph->vertices[source];

	while (adj_list != NULL) 
	{
		if (!graph->visited[adj_list->item])
		{
			depth_first_search(graph, adj_list->item);
		}
		adj_list = adj_list->next_adj_vertex;
	}
}
//BFS - BUSCA EM LARGURA (BREADTH FIRST SEARCH)
void breadth_first_search(Graph *graph, int source)
{
	Queue *queue = create_queue();
	int dequeued;
	AdjList *adj_list = graph->vertices[source];
	graph->visited[source] = 1;
	enqueue(queue, source);
	
	while (!is_empty(queue)) 
	{
		dequeued = dequeue(queue);
		adj_list = graph->vertices[dequeued];
		while (adj_list != NULL)
		{
			if (graph->visited[adj_list->item] == 0)
			{
				printf("%d\n", adj_list->item);
				graph->visited[adj_list->item] = 1;
				enqueue(queue, adj_list->item);
			}
			adj_list = adj_list->next_adj_vertex;
		}
	}
}
//FILA
struct queue
{
    int current_size;
    int first;
    int last;
    int items[MAX_QUEUE_SIZE];
};

Queue* create_queue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->current_size = 0;
    queue->first = 0;
    queue->last = MAX_QUEUE_SIZE-1;
    return queue;
}
int is_empty(Queue *queue)
{
    return queue->current_size==0;
}
void enqueue(Queue *queue, int item)
{
    if(queue->current_size>=MAX_QUEUE_SIZE)
        printf("Queue is full!\n");
    else
    {
        queue->last = (queue->last+1)%MAX_QUEUE_SIZE;
        queue->items[queue->last] = item;
        queue->current_size++;
    }
}
int dequeue(Queue *queue)
{
    if(is_empty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        int dequeue = queue->items[queue->first];
        queue->first = (queue->first+1)%MAX_QUEUE_SIZE;
        queue->current_size--;
        return dequeue;
    }
}

int main()
{
	Graph *undirectedGraph = create_graph();

	add_edge(undirectedGraph, 1, 2);
	add_edge(undirectedGraph, 1, 5);
	add_edge(undirectedGraph, 2, 5);
	add_edge(undirectedGraph, 2, 3);
	add_edge(undirectedGraph, 2, 4);
	add_edge(undirectedGraph, 3, 4);
	add_edge(undirectedGraph, 4, 5);
	
	return 0;
}
