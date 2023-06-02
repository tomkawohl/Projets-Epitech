/*
** EPITECH PROJECT, 2022
** %e
** File description:
** %e
*/
#include "my_printf.h"
int my_put_nbr_float_e(double nb)
{
    int i = 0;
    int nb2 = nb;

    nb -= nb2;
    my_put_nbr(nb2);
    my_putchar('.');
    while (i != 6){
        nb *= 10;
        i++;
    }
    if (nb > 0.000001) my_put_nbr(nb);
    else {
        for (int j = 0; j < 6; j++){
            my_putchar('0');
        }
    }
    return (0);
}

void check_double(double *nb, int *for_plus, int *for_pow)
{
    if (*nb < 1) {
        while (*nb < 1) {
            (*nb) *= 10;
            (*for_pow)++;
        }
    } else {
        *for_plus = 1;
        while (*nb >= 10) {
            (*nb) /= 10;
            (*for_pow)++;
        }
    }
}

int conv_e(va_list list, const char *format, int i ,int *count)
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
    my_putchar('e');
    if (is_plus == 1) {
        my_putchar('+');
    } else {
        my_putchar('-');
    }
    if (pow < 10) my_putchar('0');
    my_put_nbr(pow);
    return (0);
}
