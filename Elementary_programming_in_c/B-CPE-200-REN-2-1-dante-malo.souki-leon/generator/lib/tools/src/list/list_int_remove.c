/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_int_remove
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void list_int_clear(list_int_t *list)
{
    if (!list)
        return;
    while (list->first) {
        list_int_remove(list);
    }
    free(list);
}

void list_int_remove(list_int_t *list)
{
    element_int_t *to_remove;
    if (!list)
        return;
    if (list->first != NULL) {
        to_remove = list->first;
        list->first = list->first->next;
        free(to_remove);
    }
    if (list->size > 0)
        list->size--;
}

void list_int_remove_end(list_int_t *list)
{
    element_int_t *to_remove;
    if (!list)
        return;
    if (list->first == list->end) {
        list_int_remove(list);
        return;
    }
    if (list->end != NULL) {
        to_remove = list->end;
        list->end = list->end->prev;
        list->end->next = NULL;
        to_remove->next = NULL;
        to_remove->prev = NULL;
        free(to_remove);
    }
    if (list->size > 0)
        list->size--;
}
