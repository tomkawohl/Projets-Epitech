/*
** EPITECH PROJECT, 2022
** cond
** File description:
** cond
*/
#include <stdarg.h>
#include "my_printf.h"
#include "struct.h"
int conversion(va_list list, const char *format, int i, int *count)
{
    int j = 0;
    conversion_t type_st[] = {
        {'c', conv_c}, {'d', conv_d}, {'i', conv_i}, {'e', conv_e},
        {'E',conv_emaj}, {'b', conv_b}, {'f', conv_f}, {'o', conv_o},
        {'p', conv_p}, {'%', conv_percent}, {'s', conv_s}, {'g', conv_g},
        {'S', conv_smaj}, {'u', conv_u}, {'x', conv_x}, {'X', conv_xmaj},
        {'n', conv_n}
    };
    for (int k = 0; k < 17; k++) {
        if (format[i] == type_st[j].type) {
            type_st[j].ptr_f(list, format, i, count);
        }
        j++;
    }
    return (0);
}
