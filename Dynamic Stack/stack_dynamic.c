#include"stack_dynamic.h"

struct node
{
    int item;
    struct node *next_node;
};
struct stack
{
    Node *top;
};
Stack* create_stack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
int is_empty(Stack *stack)
{
    return (stack->top == NULL);
}
void push(Stack *stack, int item)
{
    Node *new_top = (Node*)malloc(sizeof(Node));
    new_top->item = item;
    new_top->next_node = stack->top;
    stack->top = new_top;
}
int pop(Stack *stack)
{
    Node *node_aux;
    if(is_empty(stack))
    {
        printf("Empty stack!\n");
        return -1;
    }
    else
    {
        node_aux = stack->top;
        stack->top = node_aux->next_node;
        return node_aux->item;
        free(node_aux);
    }
}
int peek(Stack *stack)
{
    if(!is_empty(stack))
        return stack->top->item;
    else
        return -1;
}
int main()
{
    int n;
    Stack* stk = create_stack();
    puts("Digite um numero: ");
    scanf("%d", &n);
    while(n>0)
    {
        push(stk, n);
        puts("Digite outro numero:");
        scanf("%d", &n);
    }
    printf("O elemento do topo eh %d\n", peek(stk));
    while(!is_empty(stk))
        printf("%d\n", pop(stk));
    return 0;
}