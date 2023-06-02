/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_strstr
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strstr(char *str, const char *to_find)
{
    int i = 0;
    int j = 0;
    int to_find_length = my_strlen(to_find);
    int word = 0;
    if (str == NULL || to_find == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] != to_find[j]) {
            word = 0;
            j = 0;
        }
        if (str[i] == to_find[j]) {
            word++;
            j++;
        }
        if (word == to_find_length)
            return (&str[i - word + 1]);
        i++;
    }
    return (NULL);
}
