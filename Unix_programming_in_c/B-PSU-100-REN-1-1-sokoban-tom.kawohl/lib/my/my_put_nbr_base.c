/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/
#include "my.h"

void display_base(int nb, int base, int *count)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        (*count)++;
    }
    if (nb / base != 0)
        display_base(nb / base, base, count);
    my_putchar((nb % base) + '0');
    (*count)++;
}

void display_hex(int i, int *count)
{
    char *hexadecimal = "0123456789abcdef";
    if (i > 9) {
        my_putchar(hexadecimal[i]);
        (*count)++;
    } else {
        my_put_nbr(i);
        (*count)++;
    }
}

int my_put_nbr_hex(int nb, int base, int *count)
{
    if (nb < 0) {
        my_putchar('-');
        (*count)++;
        nb *= -1;
    }
    if (nb / base != 0)
        my_put_nbr_hex(nb / base, base, count);
    display_hex(nb % base, count);
    return (0);
}

int my_put_nbr_base(int nbr, char const *base, int *count)
{
    int nb_base = my_getnbr(base);
    if (nb_base == 16) {
        my_put_nbr_hex(nbr, nb_base, count);
    } else {
        display_base(nbr, nb_base, count);
    }
    return (0);
}
