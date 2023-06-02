/*
** EPITECH PROJECT, 2022
** src
** File description:
** conversion_exec
*/
#include "../include/w_printf.h"

void conversion_exec(va_list list, const char *format, int *i)
{
    int conv_max = 3;
    conversion_t conversion[] = {
        {'c', conv_c},
        {'d', conv_d},
        {'s', conv_s}
    };
    if (format[(*i) + 1] != '\0')
        (*i)++;
    for (int j = 0; j < conv_max; j++) {
        if (format[*i] == conversion[j].conv) {
            conversion[j].ptr_f(list, format, i);
        }
    }
    return;
}
