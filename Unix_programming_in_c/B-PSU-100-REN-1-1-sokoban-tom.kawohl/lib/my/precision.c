/*
** EPITECH PROJECT, 2022
** precision
** File description:
** precision
*/
#include "my.h"
#include <stdlib.h>
#include "struct.h"

int check_precision(const char *format, int *i, int *nb1, int *nb2)
{
    int j = 0;
    *nb1 = my_getnbr(format + *i);
    while (is_num(format[*i]) == 1) {
        (*i)++;
    }
    if (is_num(format[*i + 1]) == 1)
        (*i)++;
    *nb2 = my_getnbr(format + *i);
    return (0);
}

int check_type(const char *format, int *i)
{
    int j = 0;
    char tab_c[2] = "d";
    while (tab_c[j] != '0') {
        if (tab_c[j] == format[(*i) + 1]) {
            (*i)++;
            return (0);
        }
        j++;
    }
    return (0);
}

int is_superior(int *nb1, int nb2,int *count)
{
    if ((*nb1) > nb2) {
        (*nb1) -= nb2;
        while ((*nb1) > 0) {
            my_putchar(' ');
            (*nb1)--;
            (*count)++;
        }
    }
    return (0);
}

int precision(va_list list, const char *format, int *i, int *count)
{
    int j = 0;
    precision_t type_st[] = {
        {'d', precision_d}
    };
    int nb1 = 0;
    int nb2 = 0;
    check_precision(format, i, &nb1, &nb2);
    is_superior(&nb1, nb2, count);
    check_type(format, i);
    for (int k = 0; k < 2; k++) {
        if (format[*i] == type_st[j].precision) {
            type_st[j].ptr_fp(list, nb1, nb2, count);
        }
        j++;
    }
    return (0);
}
