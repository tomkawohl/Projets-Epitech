/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_delimiter_array
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

char get_delimiter(char delimiter, int set)
{
    static char c = 'a';
    if (set == TRUE) {
        c = delimiter;
    }
    return (c);
}

unsigned int count_words_delimiter(const char *str, char c)
{
    unsigned int count = 0;
    int detect = 0;
    int i = 0;
    if (!str)
        return (0);
    if (str[0] != c) {
        count++;
        if (str[1] != '\0')
            i++;
    }
    while (str[i] != '\0') {
        if (str[i] == c)
            detect = 1;
        if (str[i] != c && detect == 1) {
            count++;
            detect = 0;
        }
        i++;
    }
    return (count);
}

unsigned int word_size_delimiter(const char *str, int i)
{
    unsigned int size = 0;
    char delimiter = get_delimiter('a', FALSE);
    if (!str)
        return (0);
    while (str[i] != '\0' && str[i] != delimiter) {
        size++;
        i++;
    }
    return (size);
}

void fill_array_str_delimiter(char **str_word, int j, const char *str, int *i)
{
    int k = 0;
    char delimiter = get_delimiter('a', FALSE);
    str_word[j] = malloc(sizeof(char) * (word_size_delimiter(str, (*i)) + 1));
    while (str[*i] != '\0' && str[*i] != delimiter) {
        str_word[j][k] = str[*i];
        k++;
        (*i)++;
    }
    str_word[j][k] = '\0';
}

char **str_delimiter_array(const char *str, char delimiter)
{
    int i = 0;
    int j = 0;
    get_delimiter(delimiter, TRUE);
    if (!str) return (NULL);
    int nb_word = count_words_delimiter(str, delimiter);
    if (nb_word == 0) return (NULL);
    char **str_word = malloc(sizeof(char *) * (nb_word + 1));
    if (!str_word) return (NULL);
    while (str[i] != '\0' && j != nb_word) {
        if (str[i] != delimiter) {
            fill_array_str_delimiter(str_word, j, str, &i);
            j++;
        }
        while (str[i] != '\0' && str[i] == delimiter)
            i++;
    }
    str_word[j] = NULL;
    return (str_word);
}
