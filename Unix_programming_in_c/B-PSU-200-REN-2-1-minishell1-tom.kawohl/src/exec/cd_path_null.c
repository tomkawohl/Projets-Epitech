/*
** EPITECH PROJECT, 2022
** exec
** File description:
** cd_path_null
*/
#include "src.h"

void print_cd_path_null(void)
{
    char *error = ": No such file or directory.\n";
    int error_nb = 1;
    write(2, error, my_strlen(error));
    get_return(&error_nb);
    return;
}
