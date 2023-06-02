/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_int_display
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void list_int_display(list_int_t *list)
{
    element_int_t *element;
    if (!list)
        return;
    element = list->first;
    while (element) {
        my_putnbr(element->value);
        my_putchar(' ');
        element = element->next;
    }
    my_putchar('\n');
}
