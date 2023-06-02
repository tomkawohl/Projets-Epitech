/*
** EPITECH PROJECT, 2022
** exec
** File description:
** count_arg
*/
#include "src.h"

unsigned int count_arg(char **function)
{
    unsigned int i = 0;
    while (function[i] != NULL) {
        i++;
    }
    return (i);
}
