/*
** EPITECH PROJECT, 2022
** back_tracker/stack
** File description:
** stack_clear
*/
#include "src.h"

void stack_clear(stack_t *stack)
{
    if (!stack)
        return;
    while (stack->first) {
        stack_remove(stack);
    }
    free(stack);
}
