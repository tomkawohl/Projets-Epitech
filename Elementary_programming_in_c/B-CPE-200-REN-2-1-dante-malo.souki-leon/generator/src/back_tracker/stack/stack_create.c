/*
** EPITECH PROJECT, 2022
** back_tracker/stack
** File description:
** stack_create
*/
#include "src.h"

stack_t *stack_create(void)
{
    stack_t *stack = malloc(sizeof(*stack));

    if (stack == NULL)
        return (NULL);
    stack->size = 0;
    stack->first = NULL;
    stack->end = NULL;
    return (stack);
}
