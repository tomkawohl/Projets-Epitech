/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/
#include "../my.h"
void display_hex_xmaj(int i, int *count)
{
    char *hexadecimal = "0123456789ABCDEF";
    if (i > 9) {
        my_putchar(hexadecimal[i]);
        (*count)++;
    } else {
        my_put_nbr(i);
        (*count)++;
    }
}

int my_put_nbr_hex_xmaj(int nb, int base, int *count)
{
    if (nb < 0) {
        my_putchar('-');
        (*count)++;
        nb *= -1;
    }
    if (nb / base != 0)
        my_put_nbr_hex_xmaj(nb / base, base, count);
    display_hex_xmaj(nb % base, count);
    return (0);
}

int conv_xmaj(va_list list, const char *format, int i, int *count)
{
    my_put_nbr_hex_xmaj(va_arg(list, int), 16, count);
    return (0);
}
