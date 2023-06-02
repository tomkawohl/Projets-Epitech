/*
** EPITECH PROJECT, 2022
** src
** File description:
** conv_s
*/
#include "../include/w_printf.h"

void conv_s(va_list list, const char *format, int *i)
{
    my_putstr(va_arg(list, char *));
    return;
}
