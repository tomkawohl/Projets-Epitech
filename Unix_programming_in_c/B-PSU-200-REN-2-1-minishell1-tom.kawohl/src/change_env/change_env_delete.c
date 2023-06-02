/*
** EPITECH PROJECT, 2022
** src
** File description:
** change_env_delete
*/
#include "src.h"

char **change_env_delete(char **env, char **arg)
{
    char **env_return = NULL;
    env_return = m_delete_var_env(env, arg[1]);
    free_array_str2d(arg);
    get_change_status(RESET, FALSE);
    return (env_return);
}
