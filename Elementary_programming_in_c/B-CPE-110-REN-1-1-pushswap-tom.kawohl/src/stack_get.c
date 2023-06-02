/*
** EPITECH PROJECT, 2022
** stack_get
** File description:
** stack_get
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>

int stack_get_min_index(list_int_t *list)
{
    element_int_t *tmp;
    int min = 0;
    int index = 0;
    int index_tmp = 0;
    if (!list)
        return (-1);
    tmp = list->first;
    min = tmp->value;
    while (tmp != NULL) {
        index_tmp++;
        if (tmp->value < min) {
            min = tmp->value;
            index = index_tmp;
        }
        tmp = tmp->next;
    }
    if (index == 0)
        return (index);
    return (index - 1);
}

int stack_get_max_index(list_int_t *list)
{
    element_int_t *tmp;
    int max = 0;
    int index = 0;
    int index_tmp = 0;
    if (!list)
        return (-1);
    tmp = list->first;
    max = tmp->value;
    while (tmp != NULL) {
        index_tmp++;
        if (tmp->value > max) {
            max = tmp->value;
            index = index_tmp;
        }
        tmp = tmp->next;
    }
    if (index == 0)
        return (index);
    return (index - 1);
}
