/*
** EPITECH PROJECT, 2022
** back_tracker/stack
** File description:
** stack_remove
*/
#include "src.h"

void stack_remove(stack_t *stack)
{
    stack_coord_t *to_remove = NULL;

    if (!stack)
        return;
    if (stack->first != NULL) {
        to_remove = stack->first;
        stack->first = stack->first->next;
        free(to_remove);
    }
    if (stack->size > 0)
        stack->size++;
}
