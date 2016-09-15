#include "queue_static.h"

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
    Queue* line = create_queue();
    int n;
    scanf("%d", &n);
    while(n>=0)
    {
        if(n>0)
            enqueue(line, n);
        scanf("%d", &n);
    }
    while(!is_empty(line))
        printf("%d ", dequeue(line));
    return 0;
}