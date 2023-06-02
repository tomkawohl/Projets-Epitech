/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** my_strncpy
*/

#include "msl.h"

char *msl_strncpy(char *str, int n)
{
    int size = msl_strlen(str);
    char *new_str;

    if (size < n)
        n = size;
    new_str = malloc(sizeof(char) * n);
    for (int i = 0; i != n; i++)
        new_str[i] = str[i];
    return new_str;
}
