/*
** EPITECH PROJECT, 2022
** %f
** File description:
** %f
*/
#include <stdarg.h>
#include "../my.h"
int conv_f(va_list list, const char * format, int i, int *count)
{
        double tmp = va_arg(list, double);
        my_put_nbr_float(tmp, count);
        return (0);
}
