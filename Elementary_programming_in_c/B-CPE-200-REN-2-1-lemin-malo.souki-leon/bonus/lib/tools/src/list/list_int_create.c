/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_int_create
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

list_int_t *list_int_create(void)
{
    list_int_t *list = malloc(sizeof(*list));
    element_int_t *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
        return (NULL);
    element->value = 0;
    element->next = NULL;
    list->first = element;
    list->size = 0;
    return (list);
}
