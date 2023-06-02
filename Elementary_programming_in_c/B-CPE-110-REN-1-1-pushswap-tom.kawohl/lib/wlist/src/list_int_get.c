/*
** EPITECH PROJECT, 2022
** list_int_get
** File description:
** list_int_get
*/
#include "../include/wlist.h"
#include <stdlib.h>

int list_get_value(list_int_t *list, int index)
{
    element_int_t *element;
    unsigned int current = 0;
    if (index != 0)
        index = index - 1;
    if (!list)
        return (0);
    element = list->first;
    while (element->next != NULL && current < index) {
        element = element->next;
        current++;
    }
    return (element->value);
}
