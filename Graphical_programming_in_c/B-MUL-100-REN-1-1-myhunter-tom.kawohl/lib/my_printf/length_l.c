/*
** EPITECH PROJECT, 2022
** length_l
** File description:
** legth_l
*/
#include "my_printf.h"
#include <stdlib.h>
#include "struct.h"
int is_parameter_correct(const char *format, int *i)
{
    int j = 0;
    char tab_l[7] = "diouxX";
    while (tab_l[j] != '\0') {
        if (tab_l[j] == format[(*i) + 1]) {
            return (1);
        }
        j++;
    }
    return (0);
}

int length_l(va_list list, const char *format, int *i, int *count)
{
    if (is_parameter_correct(format, i) == 0) return (-1);
    (*i)++;
    int j = 0;
    length_t type_st[] = {
        {'d', lengthl_d},
        {'i', lengthl_i},
        {'o', lengthl_o},
        {'u', lengthl_u},
        {'x', lengthl_x},
        {'X', lengthl_xmaj}
    };
    for (int k = 0; k < 7; k++) {
        if (format[*i] == type_st[j].length) {
            type_st[j].ptr_fl(list, format, i, count);
        }
        j++;
    }
    return (0);
}
