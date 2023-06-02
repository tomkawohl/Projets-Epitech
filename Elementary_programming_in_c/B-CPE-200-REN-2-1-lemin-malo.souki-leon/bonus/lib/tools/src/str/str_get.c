/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_get_size
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int str_get_column_size(const char *str, int i)
{
    if (!str)
        return (0);
    int size = 0;
    int length = my_strlen(str);
    if (i > length)
        return (0);
    while (str[i] != '\n' && str[i] != '\0') {
        size++;
        i++;
    }
    return (size + 1);
}

unsigned int str_get_nbline(const char *str)
{
    int i = 0;
    int line = 0;
    if (!str)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == '\n')
            line++;
        i++;
    }
    return (line);
}
