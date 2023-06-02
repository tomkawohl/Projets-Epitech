/*
** EPITECH PROJECT, 2023
** msl_itoa
** File description:
** msl_itoa
*/

#include "msl.h"

char *msl_itoa(int nb)
{
    char *str = malloc(sizeof(char) * (msl_nbr_len(nb)));
    int count = 1;
    int i = 0;

    if (nb == -2147483648){
        str = "-2147483648";
        return str;
    }
    if (nb < 0){
        str[i] = '-';
        nb *= -1;
        i++;
    }
    for (;nb / count >= 10; count *= 10);
    for (;count > 0; count /= 10, i++){
        str[i] = (nb / count) % 10 + '0';
    }
    str[i] = '\0';
    return str;
}
