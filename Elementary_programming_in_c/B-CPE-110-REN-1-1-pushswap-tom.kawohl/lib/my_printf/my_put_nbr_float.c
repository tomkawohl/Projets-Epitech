/*
** EPITECH PROJECT, 2022
** float
** File description:
** float
*/
#include "my_printf.h"
int my_put_nbr_no_negativ(int nb, int *count)
{
    if (nb < 0) {
        nb = -nb;
        (*count)++;
    }
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb / 10 != 0){
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

int error(double nb)
{
    int j = 0;
    if (nb == 0){
        my_putchar('0');
        my_putchar('.');
        while (j != 6){
            j++;
            my_putchar('0');
        }
        return 1;
    }
}

int my_put_nbr_float(double nb, int *count)
{
    int i = 0;
    int nb2 = nb;

    if (error(nb) == 1) return 0;
    nb -= nb2;
    my_put_nbr(nb2);
    (*count)++;
    (*count) += count_nbr(nb2);
    my_putchar('.');
    while (i != (6)){
        nb *= 10;
        i++;
    }
    (*count) += 6;
    my_put_nbr_no_negativ(nb, count);
}
