/*
** EPITECH PROJECT, 2022
** lengthl_u.c
** File description:
** lengthl_u.c
*/
#include "../my.h"
int lengthl_u(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    my_put_nbr_ld(tmp);
    (*count) += count_nbr_ld(tmp);
    return (0);
}
