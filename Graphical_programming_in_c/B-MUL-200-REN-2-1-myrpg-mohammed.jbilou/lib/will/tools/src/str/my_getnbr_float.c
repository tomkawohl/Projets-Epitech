/*
** EPITECH PROJECT, 2022
** str
** File description:
** my_getnbr_float
*/
#include "../../include/tools.h"
#include <unistd.h>

int check_operator(char c, int result)
{
    if (c == 45)
        return (-result);
    return (result);
}

float my_getnbr_float(const char *str)
{
    int i = 0;
    int tmp = 0;
    int is_dot = 0;
    float result = 0.0;
    float multiply = 1.0;
    if (!str) return (0.0);
    if (str[0] == '-') multiply = -1.0;
    while (str[i] != '\0') {
        if (str[i] == '.') is_dot++;
        if (is_dot == 2) return (0.0);
        if (is_dot == 1)
            multiply /= 10.0;
        if (char_is_num(str[i])) {
            tmp = (str[i] - 48);
            result += (float)tmp;
            result *= 10.0;
        }
        i++;
    }
    return (result * multiply);
}
