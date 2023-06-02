/*
** EPITECH PROJECT, 2022
** %c
** File description:
** %c
*/

#include <stdarg.h>
#include "my_printf.h"
int conv_c(va_list list, const char *format, int i, int *count)
{
        my_putchar(va_arg(list, int));
        (*count)++;
        return (0);
}
