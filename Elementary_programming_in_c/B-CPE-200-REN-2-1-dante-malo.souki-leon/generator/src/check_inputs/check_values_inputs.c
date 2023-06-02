/*
** EPITECH PROJECT, 2022
** check_inputs
** File description:
** check_value_inputs
*/
#include "src.h"

int check_value(char *value_str, char *error_str)
{
    int value = 0;
    if (str_is_num(value_str) == FALSE) {
        write(2, error_str, my_strlen(error_str));
        return (FALSE);
    }
    value = my_getnbr_int(value_str);
    if (value <= 1) {
        write(2, error_str, my_strlen(error_str));
        return (FALSE);
    }
    return (TRUE);
}

int check_value_inputs(char **av)
{
    char *x_invalid = "x: Invalid argument\n";
    char *y_invalid = "y: Invalid argument\n";
    if (check_value(av[1], x_invalid) == FALSE)
        return (FALSE);
    if (check_value(av[2], y_invalid) == FALSE)
        return (FALSE);
    return (TRUE);
}
