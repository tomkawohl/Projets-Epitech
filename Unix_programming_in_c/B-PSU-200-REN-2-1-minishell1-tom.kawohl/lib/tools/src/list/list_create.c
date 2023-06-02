/*
** EPITECH PROJECT, 2022
** list
** File description:
** list_create
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return (NULL);
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}
