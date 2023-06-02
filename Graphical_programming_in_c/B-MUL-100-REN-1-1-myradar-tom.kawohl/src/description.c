/*
** EPITECH PROJECT, 2022
** src
** File description:
** description
*/
#include "src.h"

void description(const char *filename)
{
    char *buffer = file_to_str_getline(filename);
    if (!buffer)
        return;
    w_printf("%s", buffer);
    free(buffer);
    return;
}
