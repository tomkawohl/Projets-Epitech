/*
** EPITECH PROJECT, 2022
** conv_n
** File description:
** conv_n
*/
#include<stdarg.h>
#include "my_printf.h"
int conv_n(va_list list, const char *format, int i, int *count)
{
    int *ptr = va_arg(list, int *);
    *ptr = *count;
    return (0);
}
