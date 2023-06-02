/*
** EPITECH PROJECT, 2022
** mini-printf
** File description:
** mini-printf
*/
#include <stdarg.h>
#include "my.h"
#include "struct.h"
#include <stdlib.h>
int check_parameter(const char *format, int *i, int *parameter)
{
    int j = 0;
    char tab_c[19] = "bcdeEfginopsSuxX%";
    char tab_l[2] = "l";
    while (tab_c[j] != '\0') {
        if (tab_c[j] == format[(*i) + 1])
            (*parameter) = 1;
        j++;
    }
    j = 0;
    while (tab_l[j] != '\0') {
        if (tab_l[j] == format[(*i) + 1])
            (*parameter) = 2;
        j++;
    }
    return 0;
}

int check_parameter_precision(const char *format, int *i, int *parameter)
{
    int j = 0;
    char tab_p[11] = "0123456789.";
    while (tab_p[j] != '\0') {
        if (tab_p[j] == format[(*i) + 1])
            (*parameter) = 3;
        j++;
    }
    return (0);
}

int exec_parameter(va_list list, const char *format, int *i, int *count)
{
    int parameter = 0;
    check_parameter_precision(format, i, &parameter);
    check_parameter(format, i, &parameter);
    if (parameter == 3) {
        (*i)++;
        precision(list, format, i, count);
    }
    if (parameter == 2) {
        (*i)++;
        length_l(list, format, i, count);
    }
    if (parameter == 1) {
        (*i)++;
        conversion(list, format, *i, count);
    }
    return (0);
}

int my_printf(const char *format , ...)
{
    int count = 0;
    va_list list;
    va_start(list, format);
    if (format == NULL)
        return (84);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%') {
            exec_parameter(list, format, &i, &count);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(list);
    return (count);
}
