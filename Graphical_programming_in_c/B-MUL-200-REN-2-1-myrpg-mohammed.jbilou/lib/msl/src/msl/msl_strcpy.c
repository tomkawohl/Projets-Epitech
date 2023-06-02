/*
** EPITECH PROJECT, 2023
** msl_strcpy
** File description:
** msl_strcpy
*/

#include "msl.h"

char *msl_strcpy(char *str)
{
    char *cpy = str;
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return str;
    str = malloc(sizeof(char) * (msl_strlen(str) + 1));
    for (; cpy[i]; i++)
        str[i] = cpy[i];
    str[i] = '\0';
    return str;
}
