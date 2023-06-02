/*
** EPITECH PROJECT, 2022
** signals
** File description:
** handler_sig
*/
#include "src.h"

void handler_sig(int sig)
{
    char *error = NULL;
    char *line_break = "\n";
    error = strerror(sig);
    write(2, error, my_strlen(error));
    write(2, line_break, my_strlen(line_break));
    return;
}
