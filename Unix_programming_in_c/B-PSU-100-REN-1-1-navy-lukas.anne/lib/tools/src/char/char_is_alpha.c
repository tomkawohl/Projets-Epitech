/*
** EPITECH PROJECT, 2022
** char
** File description:
** char_is_alpha
*/
#include "../../include/tools.h"

int char_is_alpha(char c)
{
    if (c > 64 && c < 91)
        return (TRUE);
    if (c > 96 && c < 123)
        return (TRUE);
    return (FALSE);
}
