/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** A function that splits into words
*/

#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int my_cols_counter(char const *str, int i, char c1, char c2)
{
    int word = 0;

    for (; str[i] != '\0' && (str[i] == c1 || str[i] == c2 ); i++);
    for (; str[i] != '\0' && str[i] != c1 && str[i] != c2; i++)
        word++;
    return word;
}

static int count_lines(char const *str, char c1, char c2)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != c1 && str[i] != c2)
        && (str[i + 1] == c1 || str[i + 1] == c2 || str[i + 1] == '\0')) {
            n++;
        }
    }
    return (n);
}

char **str_to_array_separator(char const *str, char const c1, char const c2)
{
    int i = 0;
    int k = 0;
    int lines = count_lines(str, c1, c2);
    char **array = malloc(sizeof(char *) * (lines + 1));
    int cols = 0;
    int j = 0;

    for (; i < lines; i++) {
        cols = my_cols_counter(str, j, c1, c2);
        array[i] = malloc(sizeof(char) * (cols + 1));
        array[i][cols] = '\0';
        for (; str[j] != '\0' && (str[j] == c1 || str[j] == c2); j++);
        for (; str[j] != '\0' && str[j] != c1 && str[j] != c2; j++, k++) {
            array[i][k] = str[j];
        }
        k = 0;
    }
    array[lines] = NULL;
    return (array);
}
