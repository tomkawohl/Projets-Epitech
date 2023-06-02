/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/

#include "msl.h"

int msl_putstr(char const *str)
{
    if (str == NULL)
        return ERROR;
    write(1, str, msl_strlen((char *)str));
    return FALSE;
}
