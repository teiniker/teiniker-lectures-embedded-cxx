#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <stdio.h>
#include <stdbool.h>


typedef struct  
{
    int size;
    int top;
    int *buffer;
} array_stack_t;

extern array_stack_t *stack_new(size_t size);
extern void stack_delete(array_stack_t *stack);

extern bool stack_is_empty(array_stack_t *stack);
extern void stack_push(array_stack_t *stack, int value);
extern int stack_pop(array_stack_t *stack);
extern int stack_top(array_stack_t *stack);

extern void stack_print(array_stack_t *stack);

#endif /* _ARRAY_STACK_H_ */