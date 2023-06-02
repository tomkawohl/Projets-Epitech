/*
** EPITECH PROJECT, 2022
** copy_tab.c
** File description:
** copy tab
*/

#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int count_tab(char **input)
{
    int i = 0;

    for (; input[i] != NULL; i++);
    return i;
}

char **copy_array(char **array)
{
    int cols = 0;
    int count_lines = count_tab(array);
    char **cpy = malloc(sizeof(char *) * (count_lines + 1));

    for (int i = 0; array[i] != NULL; i++){
        cols = str_len(array[i]);
        cpy[i] = malloc(sizeof(char) * (cols + 1));
        cpy[i][cols] = '\0';
        for (int j = 0; array[i][j] != '\0'; j++)
            cpy[i][j] = array[i][j];
    }
    cpy[count_lines] = NULL;
    return cpy;
}
