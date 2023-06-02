/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strlen
*/
#include "../../include/tools.h"

int my_strlen(const char *str)
{
    int length = 0;
    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return (length);
}
