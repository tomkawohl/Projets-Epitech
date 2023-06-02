/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_dup
*/
#include "my_paint.h"

char *str_dup(const char *str)
{
    unsigned int i = 0;
    char *dest = NULL;
    unsigned int length_str = 0;
    if (!str)
        return (NULL);
    length_str = str_len(str);
    dest = malloc(sizeof(char) * (length_str + 1));
    if (!dest)
        return (NULL);
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[length_str] = '\0';
    return (dest);
}
