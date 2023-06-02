/*
** EPITECH PROJECT, 2022
** %u
** File description:
** %u
*/
#include "my_printf.h"
#include <stdarg.h>
int count_nbr_u(unsigned nb)
{
    int count = 1;
    while (nb > 10) {
        count++;
        nb /= 10;
    }
    return (count);
}

int conv_u(va_list list, const char * format, int i, int *count)
{
    unsigned int j = 4294967295;
    int tmp = va_arg(list, int);
    if (tmp < 0){
        j += tmp + 1;
        my_put_nbr2(j);
        (*count) += count_nbr_u(j);
    } else {
        my_put_nbr(tmp);
        (*count) += count_nbr(tmp);
    }
    return (0);
}
