/*
** EPITECH PROJECT, 2022
** %p
** File description:
** %p
*/
#include "../my.h"
int my_put_nbr_p(unsigned long int nb)
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

void display_hex_p(unsigned long int i)
{
    char *hexadecimal = "0123456789abcdef";
    if (i > 9) {
        my_putchar(hexadecimal[i]);
    } else {
        my_put_nbr(i);
    }
}

int my_put_nbr_hex_p(unsigned long int nb, int base)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / base != 0)
        my_put_nbr_hex_p(nb / base, base);
    display_hex_p(nb % base);
    return (0);
}

int conv_p(va_list list, const char *format, int i, int *count)
{
    (*count) += 14;
    my_putstr("0x");
    my_put_nbr_hex_p(va_arg(list, unsigned long int), 16);
    return (0);
}
