/*
** EPITECH PROJECT, 2022
** src
** File description:
** conv_d
*/
#include "../include/w_printf.h"

void conv_d(va_list list, const char *format, int *i)
{
    my_putnbr(va_arg(list, int));
    return;
}
