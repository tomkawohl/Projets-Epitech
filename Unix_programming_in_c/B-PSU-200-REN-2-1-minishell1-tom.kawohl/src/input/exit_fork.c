/*
** EPITECH PROJECT, 2022
** input
** File description:
** exit_fork
*/
#include "src.h"

void exit_fork(char *path, char **name_arg, char **env, char *input)
{
    free_exit(path, name_arg, env, input);
    exit(1);
}
