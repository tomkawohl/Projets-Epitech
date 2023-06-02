/*
** EPITECH PROJECT, 2022
** array
** File description:
** str1d_to_str2d
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h> //to delete


void fill_array(char **str2d, const char *str, int *i, int line)
{
    int j = 0;
    int k = 0;
    int column_size = str_get_column_size(str, *i);
    str2d[line] = malloc(sizeof(char) * (column_size + 1));
    while (k != column_size && str[*i] != '\0') {
        str2d[line][j] = str[*i];
        j++;
        k++;
        (*i)++;
    }
    str2d[line][j] = '\0';
}

char **str1d_to_str2d(const char *str)
{
    if (!str) return (NULL);
    int i = 0;
    int line = 0;
    int j = 0;
    int nb_line = str_get_nbline(str);
    int str_len = my_strlen(str);
    if (str[str_len] != '\n')
        nb_line++;
    char **str2d = malloc(sizeof(char *) * (nb_line + 1));
    if (!str2d) return (NULL);
    while (j < nb_line) {
        fill_array(str2d, str, &i, line);
        line++;
        j++;
    }
    str2d[line] = (NULL);
    return (str2d);
}
