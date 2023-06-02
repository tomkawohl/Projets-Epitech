/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_find
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

static void verify_word(char c, char cmp, unsigned int *word, unsigned int *j)
{
    if (c == cmp) {
        (*word)++;
        (*j)++;
    } else {
        (*word) = 0;
        (*j) = 0;
    }
}

bool str_find(char *str, char *to_find)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int word = 0;
    int find_length = 0;

    if (str == NULL || to_find == NULL)
        return (false);
    find_length = str_len(to_find);
    while (str[i] != '\0') {
        verify_word(str[i], to_find[j], &word, &j);
        if (word == find_length)
            return (true);
        i++;
    }
    return (false);
}
