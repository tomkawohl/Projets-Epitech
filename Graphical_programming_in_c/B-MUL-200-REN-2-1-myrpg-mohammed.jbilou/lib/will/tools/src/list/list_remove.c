/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_remove
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void list_clear(list_t *list)
{
    if (!list)
        return;
    while (list->first) {
        list_remove(list);
    }
    free(list);
}

void list_remove(list_t *list)
{
    element_t *to_remove;
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

void list_remove_end(list_t *list)
{
    element_t *to_remove;
    if (!list)
        return;
    if (list->first == list->end) {
        list_remove(list);
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
