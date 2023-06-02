/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** my_putchar
*/

#include "msl.h"

void msl_putchar(char c)
{
    write(1, &c, 1);
}
