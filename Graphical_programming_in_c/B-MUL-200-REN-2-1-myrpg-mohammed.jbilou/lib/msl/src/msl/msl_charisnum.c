/*
** EPITECH PROJECT, 2023
** msl_charisnum
** File description:
** msl_charisnum
*/

#include "msl.h"

int msl_charisnum(char c)
{
    if (c > '9' || c < '0')
        return FALSE;
    return TRUE;
}
