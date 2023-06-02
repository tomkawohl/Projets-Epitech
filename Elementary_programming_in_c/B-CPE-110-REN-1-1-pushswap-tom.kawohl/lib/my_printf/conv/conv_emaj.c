/*
** EPITECH PROJECT, 2022
** %e
** File description:
** %e
*/
#include "my_printf.h"
int conv_emaj(va_list list, const char *format, int i ,int *count)
{
    double nb = va_arg(list, double);
    int pow = 0;
    int is_plus = 0;
    (*count) += 12;
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
        (*count)++;
    }
    check_double(&nb, &is_plus, &pow);
    my_put_nbr_float_e(nb);
    my_putchar('E');
    if (is_plus == 1) {
        my_putchar('+');
    } else {
        my_putchar('-');
    }
    if (pow < 10) my_putchar('0');
    my_put_nbr(pow);
    return (0);
}
