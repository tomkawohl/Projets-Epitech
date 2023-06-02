/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_len
*/
#include "my_paint.h"

unsigned int str_len(const char *str)
{
    unsigned int length = 0;

    if (!str)
        return (0);
    for (unsigned int i = 0; str[i] != '\0'; i++)
        length++;
    return (length);
}
