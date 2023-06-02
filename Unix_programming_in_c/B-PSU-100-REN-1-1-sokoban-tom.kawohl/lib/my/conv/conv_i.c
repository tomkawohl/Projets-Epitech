/*
** EPITECH PROJECT, 2022
** %i
** File description:
** %i
*/

#include <stdarg.h>
#include "../my.h"
int conv_i(va_list list, const char * format, int i, int *count)
{
        int tmp = va_arg(list, int);
        if (tmp < 0)
            (*count)++;
        my_put_nbr(tmp);
        (*count) += count_nbr(tmp);
        return (0);
}
