/*
** EPITECH PROJECT, 2023
** msl_strcmp
** File description:
** msl_strcmp
*/

#include "msl.h"

int msl_strcmp(char const *src, char *dest)
{
    if (msl_strlen(src) != msl_strlen(dest))
        return TRUE;
    for (int i = 0; src[i] != dest[i]; i++){
        if (src[i] != dest[i])
            return TRUE;
    }
    return FALSE;
}
