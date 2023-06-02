/*
** EPITECH PROJECT, 2022
** src
** File description:
** conv_c
*/
#include "../include/w_printf.h"

void conv_c(va_list list, const char *format, int *i)
{
    my_putchar(va_arg(list, int));
    return;
}
