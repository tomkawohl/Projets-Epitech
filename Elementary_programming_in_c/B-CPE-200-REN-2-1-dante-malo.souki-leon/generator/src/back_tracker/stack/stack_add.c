/*
** EPITECH PROJECT, 2022
** back_tracker/stack
** File description:
** stack_add
*/
#include "src.h"

void stack_add(stack_t *stack, int x, int y)
{
    stack_coord_t *to_add = malloc(sizeof(*to_add));

    if (to_add == NULL)
        return;
    to_add->x = x;
    to_add->y = y;
    to_add->prev = NULL;
    to_add->next = NULL;
    stack->size++;
    if (stack->first == NULL) {
        stack->first = to_add;
        stack->end = to_add;
        return;
    }
    stack->first->prev = to_add;
    to_add->next = stack->first;
    stack->first = to_add;
}
