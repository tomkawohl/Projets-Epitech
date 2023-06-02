/*
** EPITECH PROJECT, 2023
** msl_str_islower
** File description:
** msl_str_islower
*/

#include "msl.h"

int msl_str_islower(char *str)
{
    if (str[0] == '\0' || str == NULL){
        write(2, "Error: Invalid string from mls_str_islower\n", 44);
        return ERROR;
    }
    for (int i = 0; str[i]; i++){
        if (str[i] < 'Z' && str[i] > 'A')
            return FALSE;
    }
    return TRUE;
}
