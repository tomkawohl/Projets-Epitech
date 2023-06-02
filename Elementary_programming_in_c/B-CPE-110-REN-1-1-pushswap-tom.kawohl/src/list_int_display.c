/*
** EPITECH PROJECT, 2022
** list_int_display
** File description:
** list_int_display
*/
#include "my_all.h"
#include "my_printf.h"
#include "../lib/wlist/include/wlist.h"
#include <stdlib.h>

void list_int_display(list_int_t *list)
{
    element_int_t *element;
    if (!list)
        return;
    element = list->first;
    while (element) {
        my_printf("%d ",element->value);
        element = element->next;
    }
    my_printf("\n");
}
