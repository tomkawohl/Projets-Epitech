/*
** EPITECH PROJECT, 2023
** msl_memset
** File description:
** msl_memset
*/

#include "msl.h"

void msl_memset(char *buffer, char replace, int size)
{
    for (int i = 0; i != size; i++)
        buffer[i] = replace;
}
