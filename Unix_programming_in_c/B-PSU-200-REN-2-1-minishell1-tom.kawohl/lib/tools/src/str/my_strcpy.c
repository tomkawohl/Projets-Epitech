/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strcpy
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    if (my_strlen(dest) == 0 || my_strlen(src) == 0)
        return (NULL);
    char *str = malloc(sizeof(char) * (my_strlen(dest) + 1));
    while (src[i] != '\0' && dest[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
