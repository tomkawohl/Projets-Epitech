/*
** EPITECH PROJECT, 2022
** char
** File description:
** my_putchar
*/
#include "../../include/tools.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
