/*
** EPITECH PROJECT, 2022
** src
** File description:
** w_printf
*/
#include "../include/w_printf.h"

void w_printf(const char *format, ...)
{
    if (!format) return;
    va_list list;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            conversion_exec(list, format, &i);
        } else {
            write(1, &format[i], 1);
        }
    }
    va_end(list);
}
