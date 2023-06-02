/*
** EPITECH PROJECT, 2022
** length_o
** File description:
** length_o
*/
#include "my_printf.h"
void display_base_lo(unsigned long int nb, int base, int *count)
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

int lengthl_o(va_list list, const char *format, int *i, int *count)
{
    unsigned long int tmp = va_arg(list, unsigned long int);
    display_base_lo(tmp, 8, count);
    return (0);
}
