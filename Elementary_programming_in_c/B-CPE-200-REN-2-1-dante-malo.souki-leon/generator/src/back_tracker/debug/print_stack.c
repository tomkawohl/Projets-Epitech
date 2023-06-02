/*
** EPITECH PROJECT, 2022
** back_tracker/debug
** File description:
** print_stack
*/
#include "src.h"

void print_stack(list_t *stack)
{
    U_INT i = 0;
    element_t *tmp = NULL;
    coord_t *pos = NULL;

    if (!stack)
        return;
    tmp = stack->first;
    while (tmp) {
        pos = tmp->data;
        z_printf("STACK %d: pos->x = %d pos->y : %d\n", i, pos->x, pos->y);
        tmp = tmp->next;
        i++;
    }
}
