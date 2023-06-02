/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strcmp
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int result_my_strcmp(char c1, char c2)
{
    if (c1 < c2)
        return (-1);
    return (1);
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    if (s1 == NULL || s2 == NULL)
        return (-2);
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);
    if (s1_len != s2_len)
        return (-3);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (result_my_strcmp(s1[i], s2[i]));
        }
        i++;
    }
    return (0);
}
