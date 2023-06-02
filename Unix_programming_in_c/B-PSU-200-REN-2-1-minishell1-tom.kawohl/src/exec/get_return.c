/*
** EPITECH PROJECT, 2022
** exec
** File description:
** get_return
*/
#include "src.h"

int get_return(int *set)
{
    static int return_func = 0;
    if (set != NULL) {
        return_func = (*set);
    }
    return (return_func);
}
