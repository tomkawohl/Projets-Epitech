/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** a function that copies a whole string into another
*/

#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *str_cpy(char const *src)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(src) + 1));

    cpy[my_strlen(src)] = '\0';
    for (int i = 0; src[i] != '\0'; i++)
        cpy[i] = src[i];
    return cpy;
}
