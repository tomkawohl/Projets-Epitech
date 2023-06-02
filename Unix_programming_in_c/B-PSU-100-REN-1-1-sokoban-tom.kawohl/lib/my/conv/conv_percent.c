/*
** EPITECH PROJECT, 2022
** %%
** File description:
** %%
*/
#include <stdarg.h>
#include "../my.h"
int conv_percent(va_list list, const char * format, int i, int *count)
{
        my_putchar(format[i]);
        (*count)++;
        return (0);
}
