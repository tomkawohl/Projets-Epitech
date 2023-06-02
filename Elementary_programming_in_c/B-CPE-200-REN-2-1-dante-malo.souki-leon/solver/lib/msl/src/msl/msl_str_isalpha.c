/*
** EPITECH PROJECT, 2023
** msl_str_isalpha
** File description:
** msl_str_isalpha
*/

#include "msl.h"

int msl_str_isalpha(char *str)
{
    if (str[0] == '\0' || str == NULL){
        write(2, "Error: invalid string from msl_str_isalpha\n", 44);
        return ERROR;
    }
    for (int i = 0; str[i]; i++){
        if (msl_charisalpha(str[i]) == FALSE)
            return FALSE;
    }
    return TRUE;
}
