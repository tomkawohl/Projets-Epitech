/*
** EPITECH PROJECT, 2022
** lengthl_i
** File description:
** lengthl_i
*/
#include "../my.h"
int lengthl_i(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    my_put_nbr_ld(tmp);
    (*count) += count_nbr_ld(tmp);
    return (0);
}
