/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_revstr
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    if (!str)
        return (NULL);
    int i = 0;
    int length = my_strlen(str);
    int n = length - 1;
    char *result = malloc(sizeof(char) * (length + 1));
    if (!result)
        return (NULL);
    while (i < length) {
        result[i] = str[n];
        i++;
        n--;
    }
    result[i] = '\0';
    return (result);
}
