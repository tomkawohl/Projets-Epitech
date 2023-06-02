/*
** EPITECH PROJECT, 2022
** flag
** File description:
** flag_is_perfect
*/
#include "src.h"

int flag_is_perfect(int set, int get)
{
    static int flag = FALSE;
    if (get == TRUE)
        return (flag);
    if (set == TRUE)
        flag = TRUE;
    return (flag);
}
