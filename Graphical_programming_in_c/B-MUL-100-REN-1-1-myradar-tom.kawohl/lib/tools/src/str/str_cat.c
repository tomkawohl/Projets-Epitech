/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_cat
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *str_cat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    if (dest == NULL || src == NULL)
        return (NULL);
    unsigned int length_dest = my_strlen(dest);
    unsigned int length_src = my_strlen(src);
    char *res = malloc(sizeof(char) * (length_dest + length_src + 1));
    if (!res)
        return (NULL);
    while (dest[i] != '\0') {
        res[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        res[i] = src[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

char *str_recat(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
        return (NULL);
    char *res = str_cat(dest, src);
    free (dest);
    return (res);
}
