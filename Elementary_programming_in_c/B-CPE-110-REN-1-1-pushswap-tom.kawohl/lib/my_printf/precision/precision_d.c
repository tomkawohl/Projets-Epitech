/*
** EPITECH PROJECT, 2022
** precision_d
** File description:
** precision_d
*/

#include "my_printf.h"
int my_put_nbr_precision(int nb, int *nb2)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb / 10 != 0){
        my_put_nbr_precision((nb / 10), nb2);
        (*nb2)--;
        if ((*nb2) >= 0) {
            my_putchar(nb % 10 + '0');
        }
    }
}

int precision_d(va_list list, int nb1, int nb2, int *count)
{
    int tmp = va_arg(list, int);
    int nb3 = nb2 - count_nbr(tmp);
    if (nb2 > count_nbr(tmp)) {
        while (nb3 > 0) {
            my_putchar('0');
            nb3--;
            (*count)++;
        }
    }
    (*count) += nb2;
    nb2--;
    my_put_nbr_precision(tmp, &nb2);
    return (0);
}
