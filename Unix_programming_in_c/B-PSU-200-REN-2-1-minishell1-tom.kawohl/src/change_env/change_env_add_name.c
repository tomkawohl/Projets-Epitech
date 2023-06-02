/*
** EPITECH PROJECT, 2022
** src
** File description:
** change_env_add_name
*/
#include "src.h"

char **change_env_add_name(char **env, char **arg)
{
    char **env_return = NULL;

    if (verify_name_var(arg[1])) {
        env_return = m_add_name_env(env, arg[1]);
        free_array_str2d(arg);
        get_change_status(RESET, FALSE);
        return (env_return);
    }
    free_array_str2d(arg);
    get_change_status(RESET, FALSE);
    return (env);
}
