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
    if (char_is_alpha(str[0]) == TRUE) {
        count++;
        if (str[1] != '\0')
            i++;
    }
    while (str[i] != '\0') {
        if (char_is_alpha(str[i]) != TRUE)
            detect = 1;
        if (char_is_alpha(str[i]) == TRUE && detect == 1) {
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
    while (str[i] != '\0' && char_is_alpha(str[i]) == TRUE) {
        size++;
        i++;
    }
    return (size);
}

void fill_array(char **str_word, int j, const char *str, int *i)
{
    int k = 0;
    str_word[j] = malloc(sizeof(char) * (word_size(str, (*i)) + 1));
    while (char_is_alpha(str[*i]) == TRUE) {
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
    while (str[i] != '\0') {
        if (char_is_alpha(str[i]) == TRUE) {
            fill_array(str_word, j, str, &i);
            j++;
        }
        while (str[i] != '\0' && char_is_alpha(str[i]) != TRUE)
            i++;
    }
    str_word[j] = NULL;
    return (str_word);
}
