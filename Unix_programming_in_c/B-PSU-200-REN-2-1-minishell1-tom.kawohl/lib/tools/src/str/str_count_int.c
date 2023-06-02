/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_count_int
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int str_count_int(const char *str)
{
    unsigned int count = 0;
    int detect = 0;
    int i = 0;
    if (!str) return (0);
    if (char_is_num(str[0]) == TRUE) {
        count++;
        if (str[1] != '\0')
            i++;
    }
    while (str[i] != '\0') {
        if (char_is_num(str[i]) != TRUE)
            detect = 1;
        if (char_is_num(str[i]) == TRUE && detect == 1) {
            count++;
            detect = 0;
        }
        i++;
    }
    return (count);
}
