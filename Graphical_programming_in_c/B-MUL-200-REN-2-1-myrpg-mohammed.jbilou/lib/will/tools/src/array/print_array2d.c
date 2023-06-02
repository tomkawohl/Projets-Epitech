/*
** EPITECH PROJECT, 2022
** array
** File description:
** print_array2d
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void print_str2d(char **str)
{
    if (!str)
        return;
    int i = 0;
    while (str[i] != NULL) {
        write(1, str[i], my_strlen(str[i]));
        i++;
    }
    return;
}

void print_int2d(int **int2d, int line, int column_size)
{
    if (!int2d)
        return;
    int i = 0;
    while (i < line) {
        print_int1d(int2d[i], column_size);
        i++;
    }
}
