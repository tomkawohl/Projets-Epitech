/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_add
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void list_add(list_t *list, void *value)
{
    element_t *element = malloc(sizeof(element_t));
    if (list == NULL || element == NULL || value == NULL)
        return;
    element->data = value;
    element->prev = NULL;
    element->next = NULL;
    if (list->first == NULL) {
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

void list_add_end(list_t *list, void *value)
{
    element_t *element = malloc(sizeof(element_t));
    if (list == NULL || element == NULL || value == NULL)
        return;
    element->data = value;
    element->prev = NULL;
    element->next = NULL;
    if (list->first == NULL) {
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
