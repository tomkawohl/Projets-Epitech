/*
** EPITECH PROJECT, 2022
** sc
** File description:
** sc
*/

#include <stdarg.h>
#include "my_printf.h"
int my_put_nbr_float_e2(double nb)
{
    int i = 0;
    int nb2 = nb;

    nb -= nb2;
    my_put_nbr(nb2);
    while (i != 1){
        nb *= 10;
        i++;
    }
    if (nb != 0) {
        my_put_nbr(nb);
    }
        return (0);
}

void check_double2(double *nb, int *for_plus, int *for_pow)
{
    if (*nb < 1) {
        if (*nb < 1) my_putchar('0');
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

int conv_e2(double nb)
{
    int pow = 0;
    int is_plus = 0;
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    check_double2(&nb, &is_plus, &pow);
    my_put_nbr_float_e2(nb);
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
