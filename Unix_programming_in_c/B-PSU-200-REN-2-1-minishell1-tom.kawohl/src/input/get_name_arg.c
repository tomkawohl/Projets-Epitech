/*
** EPITECH PROJECT, 2022
** input
** File description:
** get_name_arg
*/
#include "src.h"

char **get_name_arg(char *input)
{
    char **name_arg = NULL;
    if (!input)
        return (NULL);
    name_arg = str_to_word_array(input);
    if (name_arg == NULL)
        return (NULL);
    return (name_arg);
}
