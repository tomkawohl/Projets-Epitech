/*
** EPITECH PROJECT, 2022
** input
** File description:
** error_input
*/
#include "src.h"

void error_command_not_found(char *name)
{
    char *error = NULL;
    char *not_found = ": Command not found.\n";
    error = str_recat(error, name);
    error = str_recat(error, not_found);
    write(2, error, my_strlen(error));
    free(error);
}
