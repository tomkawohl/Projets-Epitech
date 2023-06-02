/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_cat
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void add_dest(char *res, char *dest, unsigned int *i)
{
    while (dest[*i] != '\0') {
        res[*i] = dest[*i];
        (*i)++;
    }
    return;
}

void add_src(char *res, const char *src, unsigned int *i)
{
    unsigned int j = 0;

    while (src[j] != '\0') {
        res[*i] = src[j];
        (*i)++;
        j++;
    }
    res[*i] = '\0';
    return;
}

char *str_add(char *dest, const char *src)
{
    unsigned int i = 0;
    unsigned int length_dest = 0;
    unsigned int length_src = 0;
    char *res = NULL;

    length_dest = str_len(dest);
    length_src = str_len(src);
    res = malloc(sizeof(char) * (length_dest + length_src + 1));
    if (!res)
        return (NULL);
    add_dest(res, dest, &i);
    add_src(res, src, &i);
    return (res);
}

char *str_cat(char *dest, const char *src)
{
    char *res = NULL;

    if (src == NULL)
        return (NULL);
    if (dest == NULL) {
        res = str_dup(src);
        return (res);
    }
    res = str_add(dest, src);
    free(dest);
    return (res);
}
