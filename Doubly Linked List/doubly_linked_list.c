#include"double_linked_list.h"

struct node
{
    int item;
    struct node *previous_node;
    struct node *next_node;
};
Node* create_doubly_linked_list()
{
    return NULL;
}
int is_empty(Node *first)
{
    return (first==NULL);
}
Node* insert_node(Node *first, int item)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->item = item;
    new_node->next_node = first;
    new_node->previous_node = NULL;
    if( first!=NULL )
       first->previous_node = new_node;
    return new_node;
}
void print_doubly_linked_list_backward(Node *last)
{
    if( last!=NULL )
    {
        printf("%d\n", last->item);
        print_doubly_linked_list_backward(last->next_node);
    }
}
int main()
{
    Node* d_list = create_doubly_linked_list();
    d_list = insert_node(d_list, 9);
    d_list = insert_node(d_list, 5);
    d_list = insert_node(d_list, 2);
    printf("Complete Doubly Linked List:\n");
    print_doubly_linked_list_backward(d_list);
    return 0;
}