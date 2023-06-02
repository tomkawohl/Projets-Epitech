/*
** EPITECH PROJECT, 2022
** input
** File description:
** is_input_empty
*/
#include "src.h"

int is_input_empty(char *input)
{
    char space = ' ';
    long long int i = 0;
    if (input[0] == '\n')
        return (TRUE);
    while (input[i] != '\0' && input[i] != '\n') {
        if (input[i] != space)
            return (FALSE);
        i++;
    }
    return (TRUE);
}
