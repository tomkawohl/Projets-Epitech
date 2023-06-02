/*
** EPITECH PROJECT, 2022
** swap
** File description:
** swap
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

int swap_first(list_int_t *list, char *str)
{
    int tmp1 = 0;
    int tmp2 = 0;
    if (!list)
        return (LIST_ERROR);
    if (list->size < 1)
        return (LIST_ERROR);
    tmp1 = list->first->value;
    tmp2 = list->first->next->value;
    list_int_remove(list);
    list_int_remove(list);
    list_int_add(list, tmp1);
    list_int_add(list, tmp2);
    write(1, str, my_strlen(str));
    return (0);
}
