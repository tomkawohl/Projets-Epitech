/*
** EPITECH PROJECT, 2022
** exec
** File description:
** check_command
*/
#include "src.h"

int check_command(char *input, char **env)
{
    if (exec_cd(input, env))
        return (TRUE);
    if (exec_echo(input))
        return (TRUE);
    if (exec_exit(input))
        return (END);
    if (exec_env(input, env))
        return (TRUE);
    if (exec_setenv(input, env)) {
        return (TRUE);
    }
    if (exec_unsetenv(input))
        return (TRUE);
    return (FALSE);
}
