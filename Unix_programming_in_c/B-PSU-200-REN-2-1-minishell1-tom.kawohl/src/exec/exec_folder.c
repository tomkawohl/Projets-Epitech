/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_folder
*/
#include "src.h"

void print_error(char * path)
{
    char *error = NULL;
    char *perm = ": Permission denied.\n";
    int error_nb = 1;
    error = str_recat(error, path);
    error = str_recat(error, perm);
    get_return(&error_nb);
    if (!error)
        return;
    write(2, error, my_strlen(error));
    free(error);
}

/* return 0 if it's not a folder, 1 in other case */
int exec_folder(char *path)
{
    struct stat info;
    int check = 0;
    if (!path)
        return (0);
    check = stat(path, &info);
    if (check == -1)
        return (0);
    if (S_ISDIR(info.st_mode)) {
        print_error(path);
        return (1);
    }
    return (0);
}
