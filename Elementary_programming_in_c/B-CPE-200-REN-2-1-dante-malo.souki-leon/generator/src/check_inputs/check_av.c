/*
** EPITECH PROJECT, 2022
** check_inputs
** File description:
** check_av
*/
#include "src.h"

int check_optional(int ac, char **av)
{
    char *optional_invalid = "optional: Invalid argument\n";
    if (ac == 4) {
        if (av[3] == NULL) {
            write(2, optional_invalid, my_strlen(optional_invalid));
            return (FALSE);
        }
        if (my_strcmp(av[3], "perfect") != 0) {
            write(2, optional_invalid, my_strlen(optional_invalid));
            return (FALSE);
        } else {
            flag_is_perfect(TRUE, FALSE);
        }
    }
    return (TRUE);
}

int check_av(int ac, char **av)
{
    char *x_invalid = "x: Invalid argument\n";
    char *y_invalid = "y: Invalid argument\n";
    if (av[1] == NULL) {
        write(2, x_invalid, my_strlen(x_invalid));
        return (FALSE);
    }
    if (av[2] == NULL) {
        write(2, y_invalid, my_strlen(y_invalid));
        return (FALSE);
    }
    if (check_optional(ac, av) == FALSE)
        return (FALSE);
    return (TRUE);
}
