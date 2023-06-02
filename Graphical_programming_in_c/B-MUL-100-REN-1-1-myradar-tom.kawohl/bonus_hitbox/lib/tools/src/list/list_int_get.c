/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_int_get
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int list_int_get_value(list_int_t *list, unsigned int index)
{
    element_int_t *element;
    unsigned int current = 0;
    if (!list)
        return (0);
    element = list->first;
    while (element->next != NULL && current < index) {
        element = element->next;
        current++;
    }
    return (element->value);
}
