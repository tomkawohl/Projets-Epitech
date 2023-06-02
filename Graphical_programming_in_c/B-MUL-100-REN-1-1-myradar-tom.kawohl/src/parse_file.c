/*
** EPITECH PROJECT, 2022
** src
** File description:
** parse_file
*/
#include "src.h"

int is_line_valid(char *str)
{
    if (!str)
        return (FALSE);
    if (str[0] != 'A' && str[0] != 'T')
        return (FALSE);
    if (str[0] == 'A') {
        if (str_count_int(str) != 6)
            return (FALSE);
    } else {
        if (str_count_int(str) != 3)
            return (FALSE);
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (char_is_alpha(str[i]))
            return (FALSE);
    }
    return (TRUE);
}

int is_file_valid(char **file_2d)
{
    int i = 0;
    while (file_2d[i] != NULL) {
        if (is_line_valid(file_2d[i]) == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

char **parse_file(const char *file)
{
    if (!file)
        return (NULL);
    char *file_1d = file_to_str_getline(file);
    if (!file_1d)
        return (NULL);
    char **file_2d = str1d_to_str2d(file_1d);
    if (!file_2d)
        return (NULL);
    if (is_file_valid(file_2d) == FALSE)
        return (NULL);
    free(file_1d);
    return (file_2d);
}
