/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strncmp
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int result_my_strncmp(char c1, char c2)
{
    if (c1 < c2)
        return (-1);
    return (1);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    if (n <= 0)
        return (-2);
    if (s1 == NULL || s2 == NULL)
        return (-2);
    while (s1[i] != '\0' && s2[i] != '\0' && i != n) {
        if (s1[i] != s2[i]) {
            return (result_my_strncmp(s1[i], s2[i]));
        }
        i++;
    }
    return (0);
}
