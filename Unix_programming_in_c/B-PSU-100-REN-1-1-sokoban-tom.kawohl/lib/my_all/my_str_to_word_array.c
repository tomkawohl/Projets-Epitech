/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/
#include "my_all.h"
#include <stdlib.h>

int is_alpha(char c)
{
    if ((c > 64 && c < 91) || c == 32)
        return (1);
    if ((c > 96 && c < 123) || c == 32)
        return (1);
    return (0);
}

int nb_word(const char *str)
{
    if (!str)
        return (84);
    int nb_word = 0;
    int max = my_strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && i != 0) {
            nb_word++;
        }
    }
    if (is_alpha(str[max - 1]) != 0)
        nb_word++;
    return (nb_word);
}

int nb_letter(const char *str, int i)
{
    int nb_letter = 0;
    while (is_alpha(str[i]) == 1) {
        nb_letter++;
        i++;
    }
    return (nb_letter);
}

void complete_buffer(char *buffer, const char *str, int *i)
{
    int j = 0;
    while (is_alpha(str[*i]) == 1) {
        buffer[j] = str[*i];
        j++;
        (*i)++;
    }
}

char **my_str_to_word_array(const char *str)
{
    if (!str) return NULL;
    char **buffer = malloc(sizeof(char *) * (nb_word(str)) + 1);
    int size = nb_word(str);
    int j = 0;
    int i = 0;
    int detect_word = 0;
    while (str[i] != '\0' && j < size) {
        detect_word = 0;
        if (is_alpha(str[i]) == 1) {
            detect_word = 1;
            buffer[j] = malloc(sizeof(char) * nb_letter(str, i) + 1);
            complete_buffer(buffer[j], str, &i);
        }
        if (j + 1 == size) break;
        if (detect_word == 1) j++;
        i++;
    }
    buffer[j + 1] = NULL;
    return (buffer);
}
