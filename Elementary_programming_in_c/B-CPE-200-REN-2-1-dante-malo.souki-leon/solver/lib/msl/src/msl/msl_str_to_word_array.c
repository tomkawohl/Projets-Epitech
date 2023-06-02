/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** str_to_word_array
*/

#include "msl.h"

int msl_line_size(int i, char *buffer)
{
    int col_size = 0;
    for (;buffer[i] != '\n' && buffer[i] != '\0'; i++){
        col_size++;
    }
    return col_size;
}

int get_line(char *buffer)
{
    int j = 1;
    for (int i = 0; buffer[i]; i++){
        if (buffer[i] == '\n')
        j++;
    }
    return j;
}

char **msl_str_to_word_array(char *buffer)
{
    int l;
    int k = 0;
    int col_size;
    int line = get_line(buffer);
    char **array = malloc(sizeof(char *) * (line + 1));
    for (int i = 0; k != line; k++, i++){
        l = 0;
        col_size = msl_line_size(i, buffer);
        array[k] = malloc(sizeof(char) * (col_size + 1));
        array[k][col_size] = '\0';
        for (;buffer[i] != '\n' &&
        buffer[i] != '\0'; i++, l++){
            array[k][l] = buffer[i];
        }
    }
    array[line] = NULL;
    return array;
}
