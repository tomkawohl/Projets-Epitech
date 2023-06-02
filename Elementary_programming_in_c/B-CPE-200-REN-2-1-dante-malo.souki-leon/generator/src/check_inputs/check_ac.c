/*
** EPITECH PROJECT, 2022
** check_inputs
** File description:
** check_ac
*/
#include "src.h"

int check_ac(int ac)
{
    char *error_few_args = "generator: Too few arguments\n";
    char *error_much_args = "generator: Too much arguments\n";
    if (ac < 3) {
        write(2, error_few_args, my_strlen(error_few_args));
        return (FALSE);
    }
    if (ac > 4) {
        write(2, error_much_args, my_strlen(error_much_args));
        return (FALSE);
    }
    return (TRUE);
}
