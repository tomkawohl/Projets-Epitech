/*
** EPITECH PROJECT, 2023
** msl_str_isnum
** File description:
** msl_str_isnum
*/

#include "msl.h"

int msl_str_isnum(char *str)
{
    if (str == NULL || str[0] == '\0'){
        write(2, "Error: Invalid string from msl_str_isnum\n", 42);
        return ERROR;
    }
    for (int i = 0; str[i]; i++){
        if (msl_charisnum(str[i]) == FALSE)
            return FALSE;
    }
    return TRUE;
}
