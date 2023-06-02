/*
** EPITECH PROJECT, 2022
** %s
** File description:
** %s
*/
#include <stdarg.h>
#include "../my.h"
int conv_s(va_list list, const char * format, int i, int *count)
{
    char *buffer = va_arg(list, char *);
    my_putstr(buffer);
    (*count) += my_strlen(buffer);
    return (0);
}
