/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_getnbr_int
*/
#include "../../include/tools.h"
#include <unistd.h>

int check_operator(char c, int result)
{
    if (c == 45)
        return (-result);
    return (result);
}

int my_getnbr_int(const char *str)
{
    int i = 0;
    long result = 0;
    if (!str)
        return (0);
    if ((str[0] == 45 || str[0] == 43)) {
        if (char_is_num(str[1]) == TRUE)
            i++;
    }
    while (char_is_num(str[i]) == TRUE && str[i] != '\0') {
        result += (str[i] - 48);
        result *= 10;
        if ((result / 10) > 2147483647)
            return (0);
        i++;
        if (char_is_num(str[i]) == FALSE || str[i] == '\0') {
            result /= 10;
            return (check_operator(str[0], (int)result));
        }
    }
    return (0);
}
