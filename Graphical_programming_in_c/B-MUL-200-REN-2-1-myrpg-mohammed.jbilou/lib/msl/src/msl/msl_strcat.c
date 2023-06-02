/*
** EPITECH PROJECT, 2023
** msl_strcat
** File description:
** msl_strncat
*/

#include "msl.h"

char *msl_strcat(char *src, char *dest)
{
    int i = 0;
    char *src2 = src;

    src = malloc(sizeof(char) * (msl_strlen(src) + msl_strlen(dest) + 1));
    for (int j = 0; src2[j]; j++)
        src[j] = src2[j];
    for (; src2[i]; i++);
    for (int j = 0; dest[j]; i++, j++){
        src[i] = dest[j];
    }
    src[i] = '\0';
    return src;
}
