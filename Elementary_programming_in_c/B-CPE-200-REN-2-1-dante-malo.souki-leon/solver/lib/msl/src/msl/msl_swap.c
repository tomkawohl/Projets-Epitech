/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** my_swap
*/

#include "msl.h"

void msl_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
