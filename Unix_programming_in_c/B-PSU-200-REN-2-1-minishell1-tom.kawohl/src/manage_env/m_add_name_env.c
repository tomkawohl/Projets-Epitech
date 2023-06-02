/*
** EPITECH PROJECT, 2022
** src
** File description:
** m_add_name_env
*/
#include "src.h"

void set_new_env(char **new_env, char **env, char *name)
{
    int i = 0;
    char *var = NULL;
    var = str_recat(var, name);
    var = str_recat(var, "=");
    while (env[i] != NULL) {
        new_env[i] = NULL;
        new_env[i] = str_recat(new_env[i], env[i]);
        i++;
    }
    if (!var) {
        new_env[i] = NULL;
        return;
    }
    new_env[i] = NULL;
    new_env[i] = str_recat(new_env[i], var);
    free(var);
}

char **m_add_name_env(char **env, char *name)
{
    int nb_var = 0;
    char **new_env = NULL;
    if (m_is_var_in_env(env, name) == TRUE)
        return (env);
    if (env == NULL || name == NULL)
        return (env);
    nb_var = count_arg(env);
    new_env = malloc(sizeof(char *) * (nb_var + 2));
    if (new_env == NULL)
        return (env);
    set_new_env(new_env, env, name);
    new_env[nb_var + 1] = NULL;
    free_array_str2d(env);
    return (new_env);
}
