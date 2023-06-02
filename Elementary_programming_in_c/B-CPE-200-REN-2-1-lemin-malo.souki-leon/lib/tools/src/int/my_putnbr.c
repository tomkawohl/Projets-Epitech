/*
** EPITECH PROJECT, 2022
** int
** File description:
** my_putnbr
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void my_putnbr(int nbr)
{
    char *str = int_to_string(nbr);
    if (!str)
        return;
    my_putstr(str);
    free(str);
}
