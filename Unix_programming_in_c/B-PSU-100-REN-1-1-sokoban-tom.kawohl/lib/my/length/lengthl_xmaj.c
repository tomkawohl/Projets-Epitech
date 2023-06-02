/*
** EPITECH PROJECT, 2022
** length_xmaj
** File description:
** length_xmaj
*/
#include "../my.h"
void display_hex_l_xmaj(unsigned long int i)
{
    char *hexadecimal = "0123456789ABCDEF";
    if (i > 9) {
        my_putchar(hexadecimal[i]);
    } else {
        my_put_nbr(i);
    }
}

int my_put_nbr_hex_l_xmaj(unsigned long int nb, int base)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / base != 0)
        my_put_nbr_hex_l_xmaj(nb / base, base);
    display_hex_l_xmaj(nb % base);
    return (0);
}

int lengthl_xmaj(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    my_put_nbr_hex_l_xmaj(tmp, 16);
    (*count) += count_nbr_ld(tmp);
    return (0);
}
