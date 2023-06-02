/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_int_create
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void list_int_add(list_int_t *list, int x)
{
    element_int_t *element = malloc(sizeof(*element));
    if (list == NULL || element == NULL)
        return;
    element->value = x;
    element->prev = NULL;
    element->next = NULL;
    if (list->size == 0) {
        list_int_remove(list);
        list->first = element;
        list->end = element;
        list->size++;
        return;
    }
    list->first->prev = element;
    element->next = list->first;
    list->first = element;
    list->size++;
}

void list_int_add_end(list_int_t *list, int x)
{
    element_int_t *element = malloc(sizeof(*element));
    if (list == NULL || element == NULL)
        return;
    element->value = x;
    element->prev = NULL;
    element->next = NULL;
    if (list->size == 0) {
        list_int_remove(list);
        list->first = element;
        list->end = element;
        list->size++;
        return;
    }
    element->next = NULL;
    list->end->next = element;
    element->prev = list->end;
    list->end = element;
    list->size++;
}
