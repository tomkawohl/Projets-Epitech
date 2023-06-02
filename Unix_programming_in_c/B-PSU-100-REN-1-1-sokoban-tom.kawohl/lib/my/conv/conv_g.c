/*
** EPITECH PROJECT, 2022
** %g
** File description:
** %g
*/
#include <stdarg.h>
#include "../my.h"
int float_int(long double *nb, int *count, int i)
{
    while (i != 6 && *nb != (long)(*nb)){
        *nb *= 10;
        if (*nb < 1) my_putchar('0');
        i++;
        (*count)++;
    }
}

int check_scien(long double *nb, int *count)
{
    if (*nb == 0.0){
        my_putchar('0');
        (*count)++;
        return 1;
    }
    if (*nb > 999999.4) {
        conv_e2(*nb + 0.5);
        (*count) += 6;
        return 1;
    }
    if (*nb < 0.00001) {
        (*count) += 6;
        conv_e2(*nb);
        return 1;
    }
}

int my_put_nbr_float_forg(long double *nb, int *count)
{
    int i = 0;
    long nb2 = *nb;

    if (check_scien(nb, count) == 1) return 0;
    *nb -= nb2;
    my_put_nbr(nb2);
    (*count) += count_nbr(nb2);
    if (*nb != 0) {
        my_putchar('.');
        (*count)++;
    }
    i = idec(nb2);
    if (i == 6) return 0;
    float_int(nb, count, i);
    if (*nb != 0){
        my_itoa((long)(*nb));
    }
}

int conv_g(va_list list, const char *format, int i, int *count)
{
    long double tmp = va_arg(list, double);
    my_put_nbr_float_forg(&tmp, count);
    return (0);
}
