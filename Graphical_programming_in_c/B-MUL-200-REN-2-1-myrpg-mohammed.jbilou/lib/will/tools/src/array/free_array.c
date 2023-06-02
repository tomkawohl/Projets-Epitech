/*
** EPITECH PROJECT, 2022
** array
** File description:
** free_array
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void free_array_str2d(char **str)
{
    int i = 0;
    while (str[i] != NULL) {
        if (str[i] != NULL)
            free(str[i]);
        i++;
    }
    free(str);
}

void free_array_int2d(int **int2d, int line)
{
    if (!int2d)
        return;
    int i = 0;
    while (i < line) {
        if (int2d[i] != NULL)
            free(int2d[i]);
        i++;
    }
    free(int2d);
}
