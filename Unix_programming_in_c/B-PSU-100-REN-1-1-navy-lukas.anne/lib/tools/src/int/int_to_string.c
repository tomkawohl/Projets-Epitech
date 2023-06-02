/*
** EPITECH PROJECT, 2022
** int
** File description:
** int_to_string
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

int count_char_int(int value)
{
    int count_char_int = 1;
    if (int_is_negativ(value)) {
        count_char_int++;
        value = -value;
    }
    if (value < 10)
        return (count_char_int);
    while (value >= 10) {
        count_char_int++;
        value /= 10;
    }
    return (count_char_int);
}

char *return_str(int char_int, int is_negativ, int value_int)
{
    char *str = {0};
    int i = char_int;
    int j = (i - 1);
    str = malloc(sizeof(char) * (char_int + 1));
    if (!str) return (NULL);
    str[i] = '\0';
    while (i != 0) {
        str[j] = ((value_int % 10) + '0');
        value_int /= 10;
        i--;
        j--;
        if (is_negativ == 1 && j == 0) {
            str[0] = '-';
            break;
        }
    }
    return (str);
}

char *int_to_string(long long value)
{
    if (int_is_overflow(value)) return (NULL);
    int char_int = 0;
    int value_int = (int)value;
    int is_negativ = 0;
    if (int_is_negativ(value_int)) {
        is_negativ = 1;
        value_int = -value_int;
    }
    char_int = count_char_int(value);
    return (return_str(char_int, is_negativ, value_int));
}
