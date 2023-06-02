/*
** EPITECH PROJECT, 2022
** push
** File description:
** push
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

int push_first(list_int_t *out, list_int_t *in, char *str)
{
    int tmp = 0;
    if (out == NULL || in == NULL)
        return (LIST_ERROR);
    tmp = out->first->value;
    list_int_remove(out);
    list_int_add(in, tmp);
    write(1, str, my_strlen(str));
    return (0);
}
