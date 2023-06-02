/*
** EPITECH PROJECT, 2022
** char
** File description:
** char_is_num
*/
#include "../../include/tools.h"

int char_is_num(char c)
{
    if (c > 47 && c < 58) {
        return (TRUE);
    }
    return (FALSE);
}
