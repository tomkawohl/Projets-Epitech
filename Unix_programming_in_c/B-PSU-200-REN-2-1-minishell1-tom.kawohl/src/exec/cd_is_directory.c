/*
** EPITECH PROJECT, 2022
** exec
** File description:
** cd_is_directory
*/
#include "src.h"

void print_error_no_dir(char *path)
{
    int error_nb = 1;
    char *error = NULL;
    char *no_dir = ": Not a directory.\n";

    get_return(&error_nb);
    error = str_recat(error, path);
    error = str_recat(error, no_dir);
    if (!error)
        return;
    write(2, error, my_strlen(error));
    free(error);
    return;
}

int cd_is_directory(char *path)
{
    struct stat info;
    if (!path)
        return (FALSE);
    if (stat(path, &info) == -1)
        return (FALSE);
    if (S_ISDIR(info.st_mode))
        return (TRUE);
    print_error_no_dir(path);
    return (FALSE);
}
