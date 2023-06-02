/*
** EPITECH PROJECT, 2022
** exec
** File description:
** check_execve
*/
#include "src.h"

void error_invalid_format(char *path)
{
    int error_nb = 1;
    char *res = NULL;
    char *error = ": Exec format error. Wrong Architecture.\n";
    res = str_recat(res, path);
    res = str_recat(res, error);
    get_return(&error_nb);
    if (!res)
        return;
    write(2, res, my_strlen(res));
    free(res);
}

void error_perm(char *path)
{
    int error_nb = 1;
    char *error = ": Permission denied.\n";
    char *res = NULL;
    res = str_recat(res, path);
    res = str_recat(res, error);
    get_return(&error_nb);
    if (!res)
        return;
    write(2, res, my_strlen(res));
    free(res);
}

int command_not_found(char *path)
{
    struct stat info;
    char *res = NULL;
    int error_nb = 1;
    char *error = ": Command not found.\n";

    if (stat(path, &info) == -1) {
        get_return(&error_nb);
        res = str_recat(res, path);
        res = str_recat(res, error);
        if (!res)
            return (TRUE);
        write(2, res, my_strlen(res));
        free(res);
        return (TRUE);
    }
    return (FALSE);
}

void check_execve(char *path)
{
    if (command_not_found(path))
        return;
    if (errno == 8) {
        error_invalid_format(path);
        return;
    }
    if (errno == EACCES) {
        error_perm(path);
        return;
    }
    error_command_not_found(path);
}
