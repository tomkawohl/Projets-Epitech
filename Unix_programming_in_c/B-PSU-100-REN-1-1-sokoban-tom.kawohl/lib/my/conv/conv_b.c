/*
** EPITECH PROJECT, 2022
** %b
** File description:
** %b
*/

#include "../my.h"

int conv_b(va_list list, const char *format, int i, int *count)
{
    unsigned int nbr = va_arg(list, unsigned int);
    my_put_nbr_base(nbr, "2", count);
    return (0);
}
