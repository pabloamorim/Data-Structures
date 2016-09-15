#include"stack_static.h"

struct stack
{
    int current_size;
    int items[MAX_STACK_SIZE];
};
Stack* create_stack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->current_size = 0;
    return stack;
}
int is_empty(Stack *stack)
{
    return (stack->current_size==0);
}
void push(Stack *stack, int item)
{
    if(stack->current_size == MAX_STACK_SIZE)
        printf("Stack overflow!\n");
    else
        stack->items[stack->current_size++] = item;
}
int pop(Stack *stack)
{
    if(is_empty(stack))
    {
        printf("Empty stack!\n");
        return -1;
    }
    else
        return stack->items[--stack->current_size];
}
int peek(Stack *stack)
{
   if(!is_empty(stack))
       return stack->items[stack->current_size-1];
   else
       return -1;
}
int main()
{
    Stack* stk = create_stack();
    int n;
    puts("Digite um numero:");
    scanf("%d", &n);
    while(n>=0)
    {
        if(n!=0)
            push(stk, n);
        puts("Digite outro numero:");
        scanf("%d", &n);

    }
    printf("O elemento do topo eh: %d\n", peek(stk));
    printf("PILHA COMPLETA:\n");
    while(!is_empty(stk))
        printf("%d\n", pop(stk));
    return 0;
}