/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** my_putnbr
*/
#include "my_printf.h"
int my_put_nbr_ld(unsigned long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb / 10 != 0){
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}
