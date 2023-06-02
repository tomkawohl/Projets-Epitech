/*
** EPITECH PROJECT, 2023
** msl_str_isprintable
** File description:
** msl_str_isprintable
*/

#include "msl.h"

int msl_str_isprintable(char *str)
{
    if (str[0] == '\0' || str == NULL){
        write(2, "Error: Invalid string from msl_str_isprintable\n", 48);
        return ERROR;
    }
    for (int i = 0; str[i]; i++){
        if (str[i] < 32 || str[i] > 126)
            return FALSE;
    }
    return TRUE;
}
