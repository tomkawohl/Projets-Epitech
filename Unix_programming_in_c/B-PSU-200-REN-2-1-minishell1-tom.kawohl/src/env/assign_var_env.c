/*
** EPITECH PROJECT, 2022
** env
** File description:
** assign_var_env
*/
#include "src.h"

void assign_var_env(char ****env, char *name, char *value)
{
    int index = 0;
    if (env[0][0] == NULL || name == NULL)
        return;
    index = get_index_var(env[0][0], name);
    free(env[0][0][index]);
    env[0][0][index] = NULL;
    env[0][0][index] = str_recat(env[0][0][index], name);
    env[0][0][index] = str_recat(env[0][0][index], "=");
    env[0][0][index] = str_recat(env[0][0][index], value);
    return;
}
