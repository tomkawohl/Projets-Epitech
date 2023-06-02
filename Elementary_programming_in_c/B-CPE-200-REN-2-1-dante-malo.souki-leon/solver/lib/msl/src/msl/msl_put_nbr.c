/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "msl.h"

int msl_put_nbr(int nb)
{
    char c = '0';
    int count = 1;

    if (nb == -2147483648){
        write(1, "-2147483648", 12);
        return FALSE;
    }
    if (nb < 0){
        write(1, "-", 1);
        nb *= -1;
    }
    for (;nb / count >= 10; count *= 10);
    for (;count > 0; count /= 10){
        c = (nb / count) % 10 + '0';
        write(1, &c, 1);
    }
    return FALSE;
}
