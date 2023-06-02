/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strncpy
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (n + 1));
    if (dest)
        free(dest);
    while (src[i] != '\0' && n != 0) {
        str[i] = src[i];
        i++;
        n--;
    }
    str[i] = '\0';
    return (str);
}
