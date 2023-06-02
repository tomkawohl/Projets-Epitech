/*
** EPITECH PROJECT, 2022
** back_tracker/stack
** File description:
** stack_print
*/
#include "src.h"

void stack_print(stack_t *stack)
{
    stack_coord_t *tmp;
    U_INT i = 0;

    if (!stack)
        return;
    tmp = stack->first;
    while (tmp) {
        z_printf("STACK %d : x : %d y : %d\n", i, tmp->x, tmp->y);
        tmp = tmp->next;
        i++;
    }
}
