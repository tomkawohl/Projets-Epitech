/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strdup
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strdup(const char *str)
{
    int i = 0;
    if (!str)
        return (NULL);
    char *dup = {0};
    dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!dup)
        return (NULL);
    while (str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
