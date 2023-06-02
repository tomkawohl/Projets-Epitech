/*
** EPITECH PROJECT, 2022
** lengthl_x
** File description:
** lengthl_x
*/
#include "../my.h"
int lengthl_x(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    my_put_nbr_hex_p(tmp, 16);
    (*count) += count_nbr_ld(tmp);
    return (0);
}
