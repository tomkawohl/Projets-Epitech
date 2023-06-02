/*
** EPITECH PROJECT, 2023
** msl_str_isupper
** File description:
** msl_str_isupper
*/

#include "msl.h"

int msl_str_isupper(char *str)
{
    if (str[0] == '\0' || str == NULL){
        write(2, "Error: Invalid string from mls_str_isupper\n", 44);
        return ERROR;
    }
    for (int i = 0; str[i]; i++){
        if (str[i] < 'z' && str[i] > 'a')
            return FALSE;
    }
    return TRUE;
}
