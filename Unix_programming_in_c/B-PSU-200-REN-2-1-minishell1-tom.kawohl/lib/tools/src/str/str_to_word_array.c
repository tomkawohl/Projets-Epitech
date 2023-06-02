/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_to_word_array
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int count_words(const char *str)
{
    unsigned int count = 0;
    int detect = 0;
    int i = 0;
    if (!str)
        return (0);
    if (str[0] != 32) {
        count++;
        if (str[1] != '\0')
            i++;
    }
    while (str[i] != '\0') {
        if (str[i] == 32)
            detect = 1;
        if (str[i] != 32 && detect == 1) {
            count++;
            detect = 0;
        }
        i++;
    }
    return (count);
}

unsigned int word_size(const char *str, int i)
{
    unsigned int size = 0;
    if (!str)
        return (0);
    while (str[i] != '\0' && str[i] != 32) {
        size++;
        i++;
    }
    return (size);
}

void fill_array_str(char **str_word, int j, const char *str, int *i)
{
    int k = 0;
    str_word[j] = malloc(sizeof(char) * (word_size(str, (*i)) + 1));
    while (str[*i] != '\0' && str[*i] != 32) {
        str_word[j][k] = str[*i];
        k++;
        (*i)++;
    }
    str_word[j][k] = '\0';
}

char **str_to_word_array(const char *str)
{
    int i = 0;
    int j = 0;
    if (!str)
        return (NULL);
    int nb_word = count_words(str);
    if (nb_word == 0)
        return (NULL);
    char **str_word = malloc(sizeof(char *) * (nb_word + 1));
    if (!str_word)
        return (NULL);
    while (str[i] != '\0' && j != nb_word) {
        if (str[i] != 32) {
            fill_array_str(str_word, j, str, &i);
            j++;
        }
        while (str[i] != '\0' && str[i] == 32)
            i++;
    }
    str_word[j] = NULL;
    return (str_word);
}
