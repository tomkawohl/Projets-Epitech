/*
** EPITECH PROJECT, 2022
** rotate
** File description:
** rotate
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

int rotate_first(list_int_t *list, char *str)
{
    int tmp1 = 0;
    if (!list)
        return (LIST_ERROR);
    if (list->size < 1)
        return (LIST_ERROR);
    tmp1 = list->first->value;
    list_int_remove(list);
    list_int_add_end(list, tmp1);
    write(1, str, my_strlen(str));
    return (0);
}

int rotate_end(list_int_t *list, char *str)
{
    int tmp1 = 0;
    if (!list)
        return (LIST_ERROR);
    if (list->size < 1)
        return (LIST_ERROR);
    tmp1 = list->end->value;
    list_int_remove_end(list);
    list_int_add(list, tmp1);
    write(1, str, my_strlen(str));
    return (0);
}
