/*
** EPITECH PROJECT, 2022
** exec
** File description:
** cd_check_nb_arg
*/
#include "src.h"

void cd_print_too_many_arg(void)
{
    char *error = "cd: Too many arguments.\n";
    int error_nb = 1;
    get_return(&error_nb);
    write(2, error, my_strlen(error));
    return;
}

int cd_check_nb_arg(char **path)
{
    unsigned int nb_arg = count_arg(path);
    if (nb_arg <= 2)
        return (TRUE);
    cd_print_too_many_arg();
    return (FALSE);
}
