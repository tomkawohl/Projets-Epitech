/*
** EPITECH PROJECT, 2022
** src
** File description:
** copy_env
*/
#include "src.h"

char **m_copy_env(char **env)
{
    char **env_copy = NULL;
    unsigned int i = 0;
    int nb_var = 0;

    if (env == NULL)
        return (NULL);
    nb_var = count_arg(env);
    env_copy = malloc(sizeof(char *) * (nb_var + 1));
    while (env[i] != NULL) {
        env_copy[i] = NULL;
        env_copy[i] = str_recat(env_copy[i], env[i]);
        i++;
    }
    env_copy[nb_var] = NULL;
    return (env_copy);
}

/*
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
*/
