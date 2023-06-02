/*
** EPITECH PROJECT, 2022
** env
** File description:
** add_var_to_env
*/
#include "src.h"

void copy_env(char **env, char **env_copy, unsigned int length)
{
    unsigned int i = 0;
    while (i < length) {
        env_copy[i] = NULL;
        if (env[i] != NULL)
            env_copy[i] = str_recat(env_copy[i], env[i]);
        i++;
    }
}

void add_var_to_env(char ***env, char *name, char *value)
{
    if (env == NULL || name == NULL)
        return;
    if (value == NULL)
        add_name_var_env(env, name);
    else
        add_value_var_env(env, name, value);
}
