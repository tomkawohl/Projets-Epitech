/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_cmp
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int str_cmp(const char *s1, const char *s2)
{
    unsigned int i = 0;
    unsigned int s1_len = 0;
    unsigned int s2_len = 0;

    if (s1 == NULL || s2 == NULL)
        return (1);
    s1_len = str_len(s1);
    s2_len = str_len(s2);
    if (s1_len != s2_len)
        return (1);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}
