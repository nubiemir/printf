#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>

typedef struct FormatStack
{
    int top;
    char **str;
} Stack;

#define NEW(len) ({                                    \
    Stack *stack = (Stack *)malloc(sizeof(Stack));     \
    stack->top = -1;                                   \
    stack->str = (int *)malloc(len * sizeof(char **)); \
    stack;                                             \
})

int ft_printf(const char *ptr, ...);
#endif