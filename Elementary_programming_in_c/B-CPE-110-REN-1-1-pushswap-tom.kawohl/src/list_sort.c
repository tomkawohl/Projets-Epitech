/*
** EPITECH PROJECT, 2022
** list_sort
** File description:
** list_sort
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>

int list_is_sorted(list_int_t *list)
{
    element_int_t *element;
    if (!list)
        return (LIST_ERROR);
    element = list->first;
    while (element && (element->next != NULL)) {
        if (element->value > element->next->value)
            return (FALSE);
        element = element->next;
    }
    return (TRUE);
}
