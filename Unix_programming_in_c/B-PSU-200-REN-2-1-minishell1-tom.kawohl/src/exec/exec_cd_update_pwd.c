/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_cd_update_pwd
*/
#include "src.h"

void free_path_pwd(char *pwd, char *full_path_tmp)
{
    free(pwd);
    free(full_path_tmp);
}

int is_home(char *path, char **env)
{
    char *home = z_get_env(env, "HOME");
    if (!home)
        return (FALSE);
    if (my_strcmp(path, home) != 0) {
        free(home);
        return (FALSE);
    }
    add_value_var_env(&env, "PWD", path);
    free(home);
    return (TRUE);
}

void update_pwd(char *path, char **env)
{
    char *pwd = z_get_env(env, "PWD");
    char *full_path_tmp = NULL;
    char *full_path = NULL;
    if (!pwd) return;
    full_path_tmp = getcwd(full_path_tmp, PATH_MAX);
    if (!full_path_tmp) {
        free(pwd);
        return;
    }
    add_value_var_env(&env, "OLDPWD", pwd);
    if (is_home(path, env)) {
        free_path_pwd(pwd, full_path_tmp);
        return;
    }
    full_path = str_recat(full_path, full_path_tmp);
    full_path = str_recat(full_path, "/");
    full_path = str_recat(full_path, path);
    add_value_var_env(&env, "PWD", full_path);
    free(full_path);
    free_path_pwd(pwd, full_path_tmp);
}
