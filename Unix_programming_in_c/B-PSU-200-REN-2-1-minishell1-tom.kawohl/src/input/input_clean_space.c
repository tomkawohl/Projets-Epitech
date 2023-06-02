/*
** EPITECH PROJECT, 2022
** input
** File description:
** input_clean_space
*/
#include "src.h"

int is_input_clean(char *input)
{
    int nb_spaces = 0;
    int nb_words = count_words_input_clean(input);
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t')
            return (FALSE);
        if (input[i] == SPACE)
            nb_spaces++;
    }
    if (nb_spaces >= nb_words)
        return (FALSE);
    return (TRUE);
}

int count_char_valid(char *input)
{
    int i = 0;
    int char_valid = 0;
    while (input[i] != '\0') {
        if (input[i] != '\t' && input[i] != SPACE) {
            char_valid++;
        }
        i++;
    }
    return (char_valid);
}

void fill_input_clean(char *input_clean, char *input)
{
    int i = 0;
    int j = 0;
    int detect = FALSE;
    int first_word = FALSE;
    while (input[i] != '\0') {
        if ((input[i] == 32 || input[i] == '\t') &&
        first_word == TRUE && detect == TRUE) {
            input_clean[j] = SPACE;
            j++;
            detect = FALSE;
        }
        if (input[i] != '\t' && input[i] != SPACE) {
            first_word = TRUE;
            input_clean[j] = input[i];
            j++;
            detect = TRUE;
        }
        i++;
    }
}

char *input_clean_space(char *input)
{
    char *input_clean = NULL;
    int char_valid = 0;
    int nb_words = 0;
    if (!input)
        return (input);
    if (is_input_clean(input))
        return (input);
    char_valid = count_char_valid(input);
    if (char_valid <= 0)
        return (input);
    nb_words = count_words_input_clean(input);
    char_valid += (nb_words - 1);
    input_clean = malloc(sizeof(char) * (char_valid + 1));
    if (!input_clean)
        return (input);
    fill_input_clean(input_clean, input);
    input_clean[char_valid] = '\0';
    free(input);
    return (input_clean);
}
