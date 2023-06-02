/*
** EPITECH PROJECT, 2022
** str
** File description:
** print_error
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void print_error(const char *str)
{
    if (!str)
        return;
    write(2, str, str_len(str));
    return;
}
