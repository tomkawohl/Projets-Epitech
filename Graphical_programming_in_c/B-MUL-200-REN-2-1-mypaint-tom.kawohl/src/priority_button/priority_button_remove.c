/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_remove
*/
#include "my_paint.h"

void priority_button_remove(priority_button_t *prio)
{
    priority_button_element_t *to_remove = NULL;

    if (!prio)
        return;
    if (prio->first == NULL)
        return;
    to_remove = prio->first;
    prio->first = prio->first->next;
    button_destroy(to_remove->button);
    free(to_remove);
    prio->size--;
    return;
}

void priority_button_remove_all(priority_button_t *prio)
{
    if (!prio)
        return;
    while (prio->first != NULL && prio->size != 0) {
        priority_button_remove(prio);
    }
    return;
}
