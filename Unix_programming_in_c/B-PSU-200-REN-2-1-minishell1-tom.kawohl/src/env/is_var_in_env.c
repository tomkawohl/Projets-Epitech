/*
** EPITECH PROJECT, 2022
** env
** File description:
** is_var_in_env
*/
#include "src.h"

int is_var_in_env(char **env, char *search)
{
    if (search == NULL || env == NULL)
        return (FALSE);
    char **tmp = NULL;
    int search_length = my_strlen(search);
    int i = 0;
    tmp = env;
    while (tmp[i] != NULL) {
        if (my_strncmp(env[i], search, search_length) == 0) {
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

/*
char *z_get_env(char **env, char *search)
{
    char **tmp = NULL;
    char *res = NULL;
    int search_length = my_strlen(search);
    int i = 0;
    if (env == NULL || search == NULL)
        return (NULL);
    tmp = env;
    while (tmp[i] != NULL) {
        if (my_strncmp(env[i], search, search_length) == 0) {
            res = str_recat(res, tmp[i] + (search_length + 1));
            return (res);
        }
        i++;
    }
    return (NULL);
}
*/
