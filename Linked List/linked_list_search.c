#include "linked_list_search.h"

struct node
{
    int item;
    struct node *next_node;
};
Node* create_linked_list()
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
    return new_node;
}
void print_linked_list(Node *first)
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
        printf("%d\n", p->item);
}
Node* search_linked_list(Node *first, int item)
{
    Node *p;
    for( p=first; p!=NULL; p=p->next_node)
    {
        if(p->item==item)
            return p;
    }
}
int main()
{
    Node* list = create_linked_list();
    int x, y;
    puts("Digite os elementos da lista: ");
    scanf("%d", &x);
    while( x>=0 )
    {
        if(x%2==0) list = insert_node(list, x);
        puts("Digite outro elemento para adicionar na lista:");
        scanf("%d", &x);
    }
    puts("LISTA ENCADEADA");
    print_linked_list(list);
    puts("Digite o elemento que voce quer buscar: ");
    scanf("%d", &y);
    if(search_linked_list(list,y))
        printf("This element exist it is %d\n", y);
    else
        printf("Element does not exist.\n");
    free(list);

    return 0;
}