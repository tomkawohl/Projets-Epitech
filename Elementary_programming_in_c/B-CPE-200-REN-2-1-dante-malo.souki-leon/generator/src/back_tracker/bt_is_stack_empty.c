/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_is_stack_empty
*/
#include "src.h"

z_bool bt_is_stack_empty(int set, int get)
{
    static z_bool is_empty = false;
    if (get == TRUE)
        return (is_empty);
    if (set == TRUE)
        is_empty = true;
    return (is_empty);
}
