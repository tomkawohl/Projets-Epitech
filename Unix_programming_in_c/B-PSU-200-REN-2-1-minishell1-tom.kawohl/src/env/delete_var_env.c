/*
** EPITECH PROJECT, 2022
** env
** File description:
** delete_var_env
*/
#include "src.h"

void delete_var_env(char ****env, char *var)
{
    int i = 0;
    int index = 0;
    char **env_copy = NULL;
    int length = count_arg(env[0][0]);
    int j = 0;
    if (is_var_in_env(env[0][0], var) == FALSE) return;
    index = get_index_var(env[0][0], var);
    if (index == -1) return;
    env_copy = malloc(sizeof(char *) * (length + 1));
    while (env[0][0][i] != NULL) {
        if (i == index) j++;
        env_copy[i] = NULL;
        env_copy[i] = str_recat(env_copy[i], env[0][0][j]);
        i++;
        j++;
    }
    env_copy[i] = NULL;
    if (is_env_freeable(FALSE) == TRUE) free_array_str2d(env[0][0]);
    env[0][0] = env_copy;
    is_env_freeable(TRUE);
}
