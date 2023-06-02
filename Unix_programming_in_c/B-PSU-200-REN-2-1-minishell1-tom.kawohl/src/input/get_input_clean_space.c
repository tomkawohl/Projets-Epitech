/*
** EPITECH PROJECT, 2022
** input
** File description:
** get_input_clean_space
*/
#include "src.h"

int count_words_input_clean(char *str)
{
    int count = 0;
    int detect = 0;
    int i = 0;
    if (!str)
        return (0);
    if (str[0] != SPACE && str[0] != '\t') {
        count++;
        if (str[1] != '\0')
            i++;
    }
    while (str[i] != '\0') {
        if (str[i] == 32 || str[i] == '\t')
            detect = TRUE;
        if (str[i] != 32 && str[i] != '\t' && detect == TRUE) {
            count++;
            detect = FALSE;
        }
        i++;
    }
    return (count);
}
