/*
** EPITECH PROJECT, 2023
** msl_charisalpha
** File description:
** msl_charisalpha
*/

#include "msl.h"

int msl_charisalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return TRUE;
    return FALSE;
}
