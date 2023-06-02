/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_cd
*/
#include "src.h"

char *get_real_path(char **path, char **env)
{
    char *real_path = NULL;
    if (path[1] == NULL)
        return (z_get_env(env, "HOME"));
    if (my_strcmp(path[1], "-") == 0) {
        real_path = z_get_env(env, "OLDPWD");
        return (real_path);
    }
    real_path = str_recat(real_path, path[1]);
    return (real_path);
}

int go_to_folder(char *path)
{
    int return_cd = 0;
    int error = 1;
    return_cd = access(path, F_OK);
    if (return_cd != 0) {
        cd_print_error_no_file(path);
        get_return(&error);
        return (-1);
    }
    return_cd = access(path, R_OK);
    if (return_cd != 0) {
        cd_print_error_perm(path);
        get_return(&error);
        return (-1);
    }
    if (cd_is_directory(path) == FALSE)
        return (-1);
    return_cd = chdir(path);
    get_return(&return_cd);
    return (0);
}

void handle_cd(char *real_path, char **path)
{
    get_change_status(PWD, FALSE);
    go_to_folder(real_path);
    free(real_path);
    free_array_str2d(path);
}

int exec_cd(char *input, char **env)
{
    char **path = NULL;
    char *real_path = NULL;
    if (!input) return (FALSE);
    if (my_strncmp(input, "cd", 2) == 0) {
        path = str_to_word_array(input);
        if (!path)
            return (TRUE);
        if (cd_check_nb_arg(path) == FALSE)
            return (TRUE);
        real_path = get_real_path(path, env);
        if (!real_path) {
            free_array_str2d(path);
            print_cd_path_null();
            return (TRUE);
        }
        handle_cd(real_path, path);
        return (TRUE);
    }
    return (FALSE);
}
