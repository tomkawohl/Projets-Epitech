/*
** EPITECH PROJECT, 2022
** exec
** File description:
** cd_print_error
*/
#include "src.h"

void cd_print_error_no_file(char *path)
{
    char *error_msg = NULL;
    char *error = ": No such file or directory.\n";
    if (!path)
        return;
    error_msg = str_recat(error_msg, path);
    error_msg = str_recat(error_msg, error);
    write(2, error_msg, my_strlen(error_msg));
    free(error_msg);
}

void cd_print_error_perm(char *path)
{
    char *error_msg = NULL;
    char *error = ": Permission denied.\n";
    if (!path)
        return;
    error_msg = str_recat(error_msg, path);
    error_msg = str_recat(error_msg, error);
    write(2, error_msg, my_strlen(error_msg));
    free(error_msg);
}
