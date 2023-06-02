/*
** EPITECH PROJECT, 2022
** %d
** File description:
** %d
*/
#include <stdarg.h>
#include "../my.h"
int count_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
    }
    int count = 1;
    while (nb > 10) {
        count++;
        nb /= 10;
    }
    return (count);
}

int conv_d(va_list list, const char * format, int i, int *count)
{
        int tmp = va_arg(list, int);
        if (tmp < 0)
            (*count)++;
        my_put_nbr(tmp);
        (*count) += count_nbr(tmp);
        return (0);
}
