/*
** EPITECH PROJECT, 2023
** msl_nbr_len
** File description:
** msl_nbr_len
*/

#include "msl.h"

int msl_nbr_len(int nb)
{
    int i = 1;

    for (; nb > 10; nb /= 10, i++);
    return i;
}
