/*
** EPITECH PROJECT, 2022
** float
** File description:
** float
*/
#include "my.h"

int my_put_nbr_e(double nb)
{
    int i = 0;
    int nb2 = nb;

    nb -= nb2;
    my_put_nbr(nb2);
    my_putchar('.');
    while (i != (6)){
        nb *= 10;
        i++;
    }
    my_put_nbr(nb);
    return (0);
}
