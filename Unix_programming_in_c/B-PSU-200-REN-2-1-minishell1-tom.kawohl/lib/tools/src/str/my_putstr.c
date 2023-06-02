/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_putstr
*/
#include "../../include/tools.h"
#include <unistd.h>

void my_putstr(const char *str)
{
    if (!str)
        return;
    write(1, str, my_strlen(str));
}
