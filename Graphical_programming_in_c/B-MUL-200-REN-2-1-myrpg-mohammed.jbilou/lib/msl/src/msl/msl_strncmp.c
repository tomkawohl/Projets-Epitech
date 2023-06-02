/*
** EPITECH PROJECT, 2023
** msl_strncmp
** File description:
** msl_strncmp
*/

#include "msl.h"

int msl_strncmp_error(char *src, char *dest)
{
    if (src[0] == '\0' || dest[0] == '\0'){
        write(2, "Error: Invalid string from msl_strncmp\n", 40);
        return ERROR;
    }
    if (src == NULL || dest == NULL){
        write(2, "Error: Invalid string from msl_strncmp\n", 40);
        return ERROR;
    }
    return FALSE;
}

int msl_strncmp(char *src, char *dest, int n)
{
    int size = msl_strlen(src);

    if (msl_strncmp_error(src, dest) == ERROR)
        return ERROR;
    if (size < n)
        n = size;
    for (int i = 0; i < n; i++){
        if (dest[i] == '\0' || src[i] == '\0')
            break;
        if (src[i] != dest[i])
            return FALSE;
    }
    return TRUE;
}
