/*
** EPITECH PROJECT, 2022
** src
** File description:
** change_pwd_env
*/
#include "src.h"

char **change_pwd_env(char **env, char **arg)
{
    char *pwd = z_get_env(env, "PWD");
    char *full_path = NULL;
    char **env_return = NULL;

    free_array_str2d(arg);
    if (!pwd)
        pwd = getcwd(pwd, PATH_MAX);
    full_path = getcwd(full_path, PATH_MAX);
    if (!full_path) {
        free(pwd);
        return (env);
    }
    env_return = m_assign_var_env(env, "OLDPWD", pwd);
    env_return = m_assign_var_env(env_return, "PWD", full_path);
    free(full_path);
    free(pwd);
    get_change_status(RESET, FALSE);
    return (env_return);
}
