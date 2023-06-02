/*
** EPITECH PROJECT, 2022
** src
** File description:
** m_delete_var_env
*/
#include "src.h"

void m_delete_var(char **env, char **new_env, int index)
{
    char **tmp = NULL;
    int i = 0;
    int j = 0;

    tmp = env;
    while (tmp[i] != NULL) {
        if (i == index) j++;
        new_env[i] = NULL;
        new_env[i] = str_recat(new_env[i], tmp[j]);
        i++;
        j++;
    }
    new_env[i] = NULL;
}

char **m_delete_var_env(char **env, char *var)
{
    int index = 0;
    char **new_env = NULL;
    int length = 0;

    if (env == NULL || var == NULL)
        return (env);
    index = (m_get_index_var(env, var));
    if (index == -1)
        return (env);
    length = count_arg(env);
    new_env = malloc(sizeof(char *) * (length + 1));
    m_delete_var(env, new_env, index);
    free_array_str2d(env);
    return (new_env);
}
