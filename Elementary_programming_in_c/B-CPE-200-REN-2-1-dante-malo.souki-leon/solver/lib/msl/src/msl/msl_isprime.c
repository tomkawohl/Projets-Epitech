/*
** EPITECH PROJECT, 2023
** msl_isprime
** File description:
** msl_isprime
*/

#include "msl.h"

int msl_isprime(int nb)
{
    int res = 0;
    int j = FALSE;

    if (nb <= 1){
        write(2, "Invalid number from msl_isprime\n", 33);
        return ERROR;
    }
    for (int i = 2; i != nb; i++){
        res = nb / i;
        if (res * i == nb)
            j++;
    }
    if (j == FALSE)
        return TRUE;
    return FALSE;
}
