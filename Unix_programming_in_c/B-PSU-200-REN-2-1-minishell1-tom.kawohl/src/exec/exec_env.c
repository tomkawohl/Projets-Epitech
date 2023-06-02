/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_env
*/
#include "src.h"

int exec_env(char *input, char **env)
{
    if (!input)
        return (FALSE);
    if (my_strncmp(input, "env", 3) != 0)
        return (FALSE);
    print_env(env);
    return (TRUE);
}
