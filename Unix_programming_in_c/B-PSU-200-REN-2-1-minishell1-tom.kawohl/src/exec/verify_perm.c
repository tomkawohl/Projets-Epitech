/*
** EPITECH PROJECT, 2022
** exec
** File description:
** verify_perm
*/
#include "src.h"

int verify_perm(char *path)
{
    char *error = NULL;
    char *perm = ": Permission denied.\n";
    int error_nb = 1;
    struct stat info;
    if (!path)
        return (TRUE);
    if (stat(path, &info) == -1)
        return (TRUE);
    if (access(path, X_OK) != 0) {
        error = str_recat(error, path);
        error = str_recat(error, perm);
        get_return(&error_nb);
        if (!error)
            return (FALSE);
        write(2, error, my_strlen(error));
        free(error);
        return (FALSE);
    }
    return (TRUE);
}
