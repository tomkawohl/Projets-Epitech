/*
** EPITECH PROJECT, 2022
** cond
** File description:
** cond
*/
#include <stdarg.h>
#include "my.h"
void my_put_s(va_list list, const char * format, int i, int count)
{
    count += my_putstr(va_arg(list, char*));
}

int cond(va_list list, const char * format, int i, int count)
{
    if ((format[i + 1]) == 's'){
        count += my_putstr(va_arg(list, char*));
    }
    if ((format[i + 1]) == 'c'){
        my_putchar(va_arg(list, int));
        count++;
    }
    if ((format[i + 1]) == 'i' || (format[i + 1]) == 'd'){
        int tmp = va_arg(list, int);
        my_put_nbr(tmp);
        count += idec(tmp);
    }
    if ((format[i + 1]) == '%'){
        my_putchar(format[i]);
        count++;
    }
    return (count);
}
