/*
** EPITECH PROJECT, 2023
** msl_strncat
** File description:
** msl_srtncat
*/

#include "msl.h"

char *msl_strncat(char *src, char *dest, int n)
{
    int i = 0;
    char *src2 = src;
    int size = msl_strlen(dest);
    if (size < n)
        n = size;

    src = malloc(sizeof(char) * (msl_strlen(src) + n + 1));
    for (int j = 0; src2[j]; j++)
        src[j] = src2[j];
    for (; src2[i]; i++);
    for (int j = 0; j < n; i++, j++){
        src[i] = dest[j];
    }
    src[i] = '\0';
    return src;
}
