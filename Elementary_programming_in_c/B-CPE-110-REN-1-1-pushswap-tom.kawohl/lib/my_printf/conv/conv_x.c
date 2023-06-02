/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/
#include "my_printf.h"

int conv_x(va_list list, const char *format, int i, int *count)
{
    my_put_nbr_hex(va_arg(list, int), 16, count);
    return (0);
}
