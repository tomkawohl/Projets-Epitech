/*
** EPITECH PROJECT, 2022
** env
** File description:
** add_name_var_env
*/
#include "src.h"

char **add_name(char ****env, char *name)
{
    unsigned int env_length = count_arg(env[0][0]);
    char **env_copy = malloc(sizeof(char *) * (env_length + 2));
    if (!env_copy)
        return (env[0][0]);
    copy_env(env[0][0], env_copy, env_length);
    if (is_env_freeable(FALSE) == TRUE)
        free_array_str2d(env[0][0]);
    env_copy[env_length] = NULL;
    env_copy[env_length] = str_recat(env_copy[env_length], name);
    env_copy[env_length] = str_recat(env_copy[env_length], "=");
    env_copy[env_length + 1] = NULL;
    is_env_freeable(TRUE);
    return (env_copy);
}

void add_name_var_env(char ***env, char *name)
{
    if (is_var_in_env(env[0], name) == FALSE) {
        env[0] = add_name(&env, name);
    }
}
