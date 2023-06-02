/*
** EPITECH PROJECT, 2022
** src
** File description:
** m_assign_var_env.c
*/
#include "src.h"

char **m_assign_var_env(char **env, char *name, char *value)
{
    int index = 0;
    if (env == NULL || name == NULL || value == NULL)
        return (env);
    index = m_get_index_var(env, name);
    if (index == -1)
        env = m_add_name_env(env, name);
    index = m_get_index_var(env, name);
    if (index == -1)
        return (env);
    free(env[index]);
    env[index] = NULL;
    env[index] = str_recat(env[index], name);
    env[index] = str_recat(env[index], "=");
    env[index] = str_recat(env[index], value);
    return (env);
}
