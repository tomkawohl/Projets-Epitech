/*
** EPITECH PROJECT, 2023
** msl_revstr
** File description:
** msl_revstr
*/

#include "msl.h"

char *msl_revstr(char *str)
{
    int n = msl_strlen(str) - 1;

    str = msl_strcpy(str);
    for (int i = 0; i < n; i++, n--){
        char c = str[i];
        str[i] = str[n];
        str[n] = c;
    }
    return str;
}
