/*
** EPITECH PROJECT, 2022
** int
** File description:
** char
*/
#include "my.h"
#include <stdlib.h>
int my_itoa(long nb)
{
    int i = 0;
    int j = 0;
    int nb2 = nb;

    while (nb2 > 0){
        nb2 /= 10;
        j++;
    }
    char *str = malloc(sizeof(char) * j);
    while (nb > 0){
        str[i] = (nb % 10) + '0';
        i++;
        nb /= 10;
    }
    while (i != -1){
        my_putchar(str[i]);
        i--;
    }
}
