#include "printf.h"

int is_empty(Stack *stack)
{
    return (stack->top == -1);
}

void push(Stack *stack, char *str)
{
    stack->str[++stack->top] = str;
}

char *pop(Stack *stack)
{
    if (is_empty(stack))
        return (NULL);
    else
        return (stack->str[stack->top--]);
}
char *peek(Stack *stack)
{
    if (is_empty(stack))
        return (NULL);
    else
        return (stack->str[stack->top]);
}