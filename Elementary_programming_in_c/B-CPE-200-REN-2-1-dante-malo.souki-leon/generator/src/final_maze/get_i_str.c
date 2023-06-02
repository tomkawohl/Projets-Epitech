/*
** EPITECH PROJECT, 2022
** src
** File description:
** get_i_str
*/
#include "src.h"

int get_i_str(int *i)
{
    static int index = 0;
    if (i != NULL) {
        index = (*i);
    }
    return (index);
}
