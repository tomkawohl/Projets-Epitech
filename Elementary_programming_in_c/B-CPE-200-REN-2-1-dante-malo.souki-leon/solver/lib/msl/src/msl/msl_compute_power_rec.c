/*
** EPITECH PROJECT, 2023
** msl_compute_power_rec
** File description:
** msl_compute_power_rec
*/

#include "msl.h"

int msl_overflow_power(int nb, int bef)
{
    if (nb < 0)
        nb *= -1;
    if (bef < 0)
        bef *= -1;
    if (bef > nb)
        return TRUE;
    return FALSE;
}

int msl_compute_power_rec(int nb, int power)
{
    int res = nb;

    if (power <= 0){
        write (2, "Error: Invalid power from msl_compute_power_rec\n", 22);
        return ERROR;
    }
    for (; power != 1; power--){
        int bef = nb;
        nb *= res;
        if (msl_overflow_power(nb, bef) == 1){
            write(2, "Error: Invalid result from msl_compute_power_rec\n", 50);
            return ERROR;
        }
    }
    return nb;
}
