/*
** EPITECH PROJECT, 2022
** handle_l_a
** File description:
** handle_l_a
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>

int is_overflow(char const *str, int *i_a)
{
    long result = 0;
    while (is_num(str[*i_a]) != 0) {
        result += str[*i_a] - 48;
        result *= 10;
        if ((result / 10) > 2147483647) {
            return (TRUE);
        }
        (*i_a)++;
        if (is_num(str[*i_a]) == 0) {
            (*i_a)--;
            result /= 10;
            return (FALSE);
        }
    }
    return (0);
}

int detect_overflow(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != 45 && str[i] != 43 && is_num(str[i]) == 0) {
            return (0);
        }
        if (is_num(str[i]) == 1) {
            return (is_overflow(str, &i));
        }
        i++;
    }
    return (0);
}

int is_str_valid(char *str)
{
    int i = 0;
    if (str[0] == '-') {
        if (my_strlen(str) == 1)
            return (FALSE);
        i++;
    }
    while (str[i] != '\0') {
        if (is_num(str[i]) == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

int handle_error(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (is_str_valid(av[i]) == FALSE)
            return (-1);
    }
    for (int i = 1; i < ac; i++) {
        if (detect_overflow(av[i]) == TRUE)
            return (-1);
    }
    return (0);
}
