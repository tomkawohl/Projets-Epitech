/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/
#include "../my.h"
int conv_o(va_list list, const char *format, int i, int *count)
{
    my_put_nbr_base(va_arg(list, int), "8", count);
    return (0);
}
