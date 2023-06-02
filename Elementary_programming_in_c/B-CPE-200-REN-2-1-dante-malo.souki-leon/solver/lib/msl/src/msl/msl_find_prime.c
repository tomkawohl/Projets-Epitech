/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

#include "msl.h"

int msl_find_prime(int nb, int act)
{
    int detect = msl_isprime(nb);

    if (act != 1 && act != -1){
        write (2, "Invalid parameter on msl_find_prime_sup\n", 41);
        write (2, "Try 1 or -1\n", 13);
        return ERROR;
    }
    if (detect == ERROR)
        return ERROR;
    for (; msl_isprime(nb) != 1; nb += act);
    return nb;
}
