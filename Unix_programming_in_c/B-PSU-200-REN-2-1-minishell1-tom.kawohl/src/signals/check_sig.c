/*
** EPITECH PROJECT, 2022
** signals
** File description:
** check_sig
*/
#include "src.h"

void print_signal(char *str_error, int status)
{
    char *error = NULL;
    char *core_dump = " (core dumped)";
    error = str_recat(error, str_error);
    if (WCOREDUMP(status)) {
        error = str_recat(error, core_dump);
    }
    error = str_recat(error, "\n");
    if (!error)
        return;
    write(2, error, my_strlen(error));
    free(error);
}

void print_float_error(int status)
{
    char *res = NULL;
    char *error = "Floating exception";
    char *core_dump = " (core dumped)";

    res = str_recat(res, error);
    if (WCOREDUMP(status)) {
        res = str_recat(res, core_dump);
    }
    res = str_recat(res, "\n");
    if (!res)
        return;
    write(2, res, my_strlen(res));
    free(res);
    return;
}

void check_sig(int status)
{
    int sig_term = 0;
    char *str_error = NULL;

    sig_term = WTERMSIG(status);
    if (sig_term == 8) {
        print_float_error(status);
        get_return(&status);
        return;
    }
    str_error = strsignal(sig_term);
    print_signal(str_error, status);
    get_return(&status);
}
