/*
** EPITECH PROJECT, 2023
** msl_compute_square_root
** File description:
** msl_compute_square_root
*/

#include "msl.h"

int msl_compute_square_root(int nb)
{
    int i = 1;

    if (nb == 0){
        write(2, "Error: Invalid number from msl_compute_square_root\n", 52);
        return ERROR;
    }
    for (; i * i < nb; i++);
    return i;
}
