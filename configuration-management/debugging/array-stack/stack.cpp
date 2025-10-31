#include <stdlib.h>

#include "stack.h"

array_stack_t *stack_new(size_t size)
{
    array_stack_t *stack = (array_stack_t*)malloc(sizeof(array_stack_t));
    stack->size = size;
    stack->top = -1;
    stack->buffer = (int*)calloc(size, sizeof(int));
    return stack;
}

void stack_delete(array_stack_t *stack)
{
    free(stack->buffer);
    free(stack);
}

bool stack_is_empty(array_stack_t *stack)
{
    return stack->top == -1;

}

bool stack_is_full(array_stack_t *stack)
{
    return stack->top == stack->size-1;
}

void stack_push(array_stack_t *stack, int value)
{
    if(stack_is_full(stack))
        return;    // stack is full
    
    stack->top++;
    stack->buffer[stack->top] = value;
}

int stack_top(array_stack_t *stack)
{
    if(stack_is_empty(stack))
        return EXIT_FAILURE;

    return stack->buffer[stack->top];
}

int stack_pop(array_stack_t *stack)
{
    if(stack_is_empty(stack))
        return EXIT_FAILURE;

    int value = stack_top(stack);
    stack->top--;
    return value;
}

void stack_print(array_stack_t *stack)
{
    if(stack_is_empty(stack))
    {
        printf("[]<--top\n");
        return;
    }

    printf("[ ");
    for(int i=0; i <= stack->top; i++)
    {
        printf("%d ", stack->buffer[i]);       
    }
    printf("]<--top\n");
}
