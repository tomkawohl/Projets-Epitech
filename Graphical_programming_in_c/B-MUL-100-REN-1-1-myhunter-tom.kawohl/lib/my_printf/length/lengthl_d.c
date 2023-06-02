/*
** EPITECH PROJECT, 2022
** length_l
** File description:
** length_l
*/
#include "my_printf.h"
int count_nbr_ld(unsigned long int nb)
{
    int count = 1;
    while (nb > 10) {
        count++;
        nb /= 10;
    }
    return (count);
}

int lengthl_d(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    my_put_nbr_ld(tmp);
    (*count) += count_nbr_ld(tmp);
    return (0);
}
